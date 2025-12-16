#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Grammar {
    vector<string> nonterminals;
    vector<string> terminals;
    map<string, vector<vector<string>>> prod;
};

set<string> FIRST(const string& symbol, const Grammar& G, map<string, set<string>>& firstMemo);

set<string> FIRST_string(const vector<string>& symbols, const Grammar& G,
                         map<string, set<string>>& firstMemo) {
    set<string> res;
    bool allNullable = true;
    for (auto& sym : symbols) {
        set<string> fs = FIRST(sym, G, firstMemo);
        for (auto& s : fs)
            if (s != "ε")
                res.insert(s);
        if (fs.find("ε") == fs.end()) {
            allNullable = false;
            break;
        }
    }
    if (allNullable)
        res.insert("ε");
    return res;
}

set<string> FIRST(const string& symbol, const Grammar& G, map<string, set<string>>& firstMemo) {
    if (firstMemo.count(symbol))
        return firstMemo[symbol];
    set<string> res;
    if (find(G.terminals.begin(), G.terminals.end(), symbol) != G.terminals.end()) {
        res.insert(symbol);
        firstMemo[symbol] = res;
        return res;
    }
    for (auto& rhs : G.prod.at(symbol)) {
        if (rhs.empty()) {
            res.insert("ε");
            continue;
        }
        bool nullable = true;
        for (auto& s : rhs) {
            set<string> fs = FIRST(s, G, firstMemo);
            for (auto& x : fs)
                if (x != "ε")
                    res.insert(x);
            if (fs.find("ε") == fs.end()) {
                nullable = false;
                break;
            }
        }
        if (nullable)
            res.insert("ε");
    }
    firstMemo[symbol] = res;
    return res;
}

map<string, set<string>> computeFOLLOW(const Grammar& G, map<string, set<string>>& firstMemo) {
    map<string, set<string>> follow;
    for (auto& nt : G.nonterminals)
        follow[nt] = {};
    follow[G.nonterminals[0]].insert("$");
    bool changed = true;
    while (changed) {
        changed = false;
        for (auto& p : G.prod) {
            string A = p.first;
            for (auto& rhs : p.second) {
                for (int i = 0; i < rhs.size(); i++) {
                    string B = rhs[i];
                    if (find(G.nonterminals.begin(), G.nonterminals.end(), B) ==
                        G.nonterminals.end())
                        continue;
                    vector<string> beta(rhs.begin() + i + 1, rhs.end());
                    set<string> fBeta = FIRST_string(beta, G, firstMemo);
                    int before = follow[B].size();
                    for (auto& s : fBeta)
                        if (s != "ε")
                            follow[B].insert(s);
                    if (fBeta.find("ε") != fBeta.end() || beta.empty()) {
                        for (auto& s : follow[A])
                            follow[B].insert(s);
                    }
                    if (follow[B].size() > before)
                        changed = true;
                }
            }
        }
    }
    return follow;
}

// LL(1) 判断和预测分析表生成
bool isLL1(const Grammar& G, const map<string, set<string>>& firstMemo,
           const map<string, set<string>>& follow,
           map<pair<string, string>, vector<string>>& parseTable) {
    bool isLL1 = true;
    for (auto& nt : G.nonterminals) {
        set<string> allFirsts;
        bool hasEpsilon = false;
        for (auto& rhs : G.prod.at(nt)) {
            set<string> rhsFirst =
                FIRST_string(rhs, G, const_cast<map<string, set<string>>&>(firstMemo));
            for (auto& s : rhsFirst) {
                if (s == "ε") {
                    hasEpsilon = true;
                } else {
                    if (allFirsts.count(s)) {
                        cout << "冲突：非终结符 " << nt << " 的产生式 FIRST 集重叠于 " << s << endl;
                        isLL1 = false;
                    }
                    allFirsts.insert(s);
                }
            }
            // 填充预测分析表
            for (auto& term : rhsFirst) {
                if (term != "ε") {
                    if (parseTable.count({nt, term})) {
                        cout << "冲突：预测分析表中 (" << nt << ", " << term << ") 有多个产生式"
                             << endl;
                        isLL1 = false;
                    }
                    parseTable[{nt, term}] = rhs;
                }
            }
        }
        if (hasEpsilon) {
            for (auto& followSym : follow.at(nt)) {
                if (allFirsts.count(followSym)) {
                    cout << "冲突：非终结符 " << nt << " 的 FIRST 和 FOLLOW 重叠于 " << followSym
                         << endl;
                    isLL1 = false;
                }
                if (parseTable.count({nt, followSym})) {
                    cout << "冲突：预测分析表中 (" << nt << ", " << followSym << ") 有多个产生式"
                         << endl;
                    isLL1 = false;
                }
                parseTable[{nt, followSym}] = {}; // ε 产生式
            }
        }
    }
    return isLL1;
}

// ...existing code...

// 预测分析器实现
void parseInput(const Grammar& G, const map<pair<string, string>, vector<string>>& parseTable) {
    cout << "\n请输入待分析的符号串（以空格分隔，输入END结束）：";
    vector<string> input;
    string token;
    while (cin >> token && token != "END") {
        input.push_back(token);
    }
    input.push_back("$"); // 结束符

    vector<string> stack;
    stack.push_back("$");
    stack.push_back(G.nonterminals[0]); // 开始符号

    size_t ip = 0;
    cout << "\n分析过程：" << endl;
    while (!stack.empty()) {
        string top = stack.back();
        string cur = input[ip];
        cout << "栈顶: " << top << "，当前输入: " << cur << endl;
        if (top == cur && top == "$") {
            cout << "分析成功，输入符号串符合文法！" << endl;
            return;
        }
        if (find(G.terminals.begin(), G.terminals.end(), top) != G.terminals.end() || top == "$") {
            if (top == cur) {
                stack.pop_back();
                ++ip;
            } else {
                cout << "错误：终结符 " << top << " 与输入 " << cur << " 不匹配，分析失败！"
                     << endl;
                return;
            }
        } else {
            auto it = parseTable.find({top, cur});
            if (it == parseTable.end()) {
                cout << "错误：预测分析表无条目 (" << top << ", " << cur << ")，分析失败！" << endl;
                return;
            }
            stack.pop_back();
            const vector<string>& prod = it->second;
            if (!(prod.empty() || (prod.size() == 1 && (prod[0] == "ε" || prod[0] == "EPS")))) {
                // 逆序压入产生式右部
                for (auto rit = prod.rbegin(); rit != prod.rend(); ++rit) {
                    stack.push_back(*rit);
                }
            } else {
                // 空产生式，什么都不做
            }
        }
    }
    if (input[ip] == "$") {
        cout << "分析成功，输入符号串符合文法！" << endl;
    } else {
        cout << "错误：输入未完全分析，分析失败！" << endl;
    }
}

int main() {
    Grammar G;
    cout << "请输入非终结符数量：";
    int n;
    if (!(cin >> n)) {
        cerr << "输入无效，程序退出。\n";
        return 1;
    }
    string line;
    getline(cin, line);

    for (int i = 0; i < n; ++i) {
        cout << "请输入第" << i + 1 << "个非终结符名称：";
        string A;
        if (!getline(cin, A)) {
            cerr << "读取非终结符名称失败，程序退出。\n";
            return 1;
        }
        G.nonterminals.push_back(A);

        cout << "请输入非终结符 " << A << " 的产生式数量：";
        int m;
        if (!(cin >> m)) {
            cerr << "输入无效，程序退出。\n";
            return 1;
        }
        getline(cin, line);

        for (int j = 0; j < m; ++j) {
            cout << "请输入第" << j + 1
                 << "个产生式（符号以空格分隔，使用 EPS 或 ε 表示空产生式）：";
            if (!getline(cin, line)) {
                cerr << "读取产生式失败，程序退出。\n";
                return 1;
            }
            if (line.empty()) {
                G.prod[A].push_back(vector<string>());
                continue;
            }
            size_t l = line.find_first_not_of(" \t");
            if (l == string::npos) {
                G.prod[A].push_back(vector<string>());
                continue;
            }
            size_t r = line.find_last_not_of(" \t");
            string trimmed = line.substr(l, r - l + 1);
            if (trimmed == "EPS" || trimmed == "ε" || trimmed == "eps") {
                G.prod[A].push_back(vector<string>());
                continue;
            }
            bool hasSpace =
                (trimmed.find(' ') != string::npos || trimmed.find('\t') != string::npos);
            vector<string> toks;
            if (hasSpace) {
                istringstream ts(trimmed);
                string tok;
                while (ts >> tok)
                    toks.push_back(tok);
            } else {
                for (char c : trimmed)
                    toks.push_back(string(1, c));
            }
            G.prod[A].push_back(toks);
        }
    }

    // 推断终结符
    for (auto& p : G.prod) {
        for (auto& rhs : p.second) {
            for (auto& sym : rhs) {
                if (sym == "ε")
                    continue;
                if (find(G.nonterminals.begin(), G.nonterminals.end(), sym) ==
                    G.nonterminals.end()) {
                    if (find(G.terminals.begin(), G.terminals.end(), sym) == G.terminals.end())
                        G.terminals.push_back(sym);
                }
            }
        }
    }

    // 计算 FIRST 和 FOLLOW
    map<string, set<string>> firstMemo;
    for (auto& nt : G.nonterminals)
        FIRST(nt, G, firstMemo);

    auto follow = computeFOLLOW(G, firstMemo);

    // 判断 LL(1) 并生成预测分析表
    map<pair<string, string>, vector<string>> parseTable;
    bool ll1 = isLL1(G, firstMemo, follow, parseTable);

    cout << "\n判断结果：" << (ll1 ? "是 LL(1) 文法" : "不是 LL(1) 文法") << endl;

    cout << "\n预测分析表：" << endl;

    // 收集所有终结符列（包括 $）
    set<string> columns;
    for (auto& term : G.terminals)
        columns.insert(term);
    columns.insert("$");

    // 准备表头
    vector<string> headers = {"非终结符  "};
    // vector<string> headers = {"NT"};
    for (auto& col : columns)
        headers.push_back(col);

    // 固定每列宽度为10个字符
    const size_t CELL_WIDTH = 10;
    vector<size_t> colWidths(headers.size(), CELL_WIDTH);

    // 输出表头
    for (size_t i = 0; i < headers.size(); ++i) {
        if (i > 0)
            cout << " ";
        cout << left << setw(CELL_WIDTH) << headers[i];
    }
    cout << endl;

    // 输出分隔线
    for (size_t i = 0; i < colWidths.size(); ++i) {
        if (i > 0)
            cout << " ";
        cout << string(CELL_WIDTH, '-');
    }
    cout << endl;

    // 为每个非终结符输出一行
    for (auto& nt : G.nonterminals) {
        cout << left << setw(CELL_WIDTH) << nt;
        for (size_t i = 1; i < headers.size(); ++i) {
            cout << " ";
            string col = headers[i];
            auto key = make_pair(nt, col);
            string content;
            if (parseTable.count(key)) {
                vector<string> rhs = parseTable[key];
                content = nt + " -> ";
                if (rhs.empty()) {
                    content += "ε";
                } else {
                    for (size_t k = 0; k < rhs.size(); ++k) {
                        content += rhs[k];
                        if (k < rhs.size() - 1)
                            content += " ";
                    }
                }
            } else {
                content = "";
            }
            cout << left << setw(CELL_WIDTH) << content;
        }
        cout << endl;
    }

    while (1) {
        parseInput(G, parseTable);
    }
    return 0;
}