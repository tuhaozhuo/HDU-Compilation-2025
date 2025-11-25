#include <algorithm>
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

set<string> FIRST(const string &symbol, const Grammar &G,
                  map<string, set<string>> &firstMemo);

set<string> FIRST_string(const vector<string> &symbols, const Grammar &G,
                         map<string, set<string>> &firstMemo) {
  set<string> res;
  bool allNullable = true;
  for (auto &sym : symbols) {
    set<string> fs = FIRST(sym, G, firstMemo);
    for (auto &s : fs)
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

// FIRST 单符号
set<string> FIRST(const string &symbol, const Grammar &G,
                  map<string, set<string>> &firstMemo) {
  if (firstMemo.count(symbol))
    return firstMemo[symbol];
  set<string> res;
  if (find(G.terminals.begin(), G.terminals.end(), symbol) !=
      G.terminals.end()) {
    res.insert(symbol);
    firstMemo[symbol] = res;
    return res;
  }
  for (auto &rhs : G.prod.at(symbol)) {
    if (rhs.empty()) {
      res.insert("ε");
      continue;
    }
    bool nullable = true;
    for (auto &s : rhs) {
      set<string> fs = FIRST(s, G, firstMemo);
      for (auto &x : fs)
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

// FOLLOW 集计算
map<string, set<string>> computeFOLLOW(const Grammar &G,
                                       map<string, set<string>> &firstMemo) {
  map<string, set<string>> follow;
  for (auto &nt : G.nonterminals)
    follow[nt] = {};
  follow[G.nonterminals[0]].insert("$"); // 开始符号
  bool changed = true;
  while (changed) {
    changed = false;
    for (auto &p : G.prod) {
      string A = p.first;
      for (auto &rhs : p.second) {
        for (int i = 0; i < rhs.size(); i++) {
          string B = rhs[i];
          if (find(G.nonterminals.begin(), G.nonterminals.end(), B) ==
              G.nonterminals.end())
            continue;
          vector<string> beta(rhs.begin() + i + 1, rhs.end());
          set<string> fBeta = FIRST_string(beta, G, firstMemo);
          int before = follow[B].size();
          for (auto &s : fBeta)
            if (s != "ε")
              follow[B].insert(s);
          if (fBeta.find("ε") != fBeta.end() || beta.empty()) {
            for (auto &s : follow[A])
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

int main() {
  Grammar G;
  cout << "请输入非终结符数量：";
  int n;
  if (!(cin >> n)) {
    cerr << "输入无效，程序退出。\n";
    return 1;
  }
  string line;
  getline(cin, line); // 吃掉行尾

  // 逐个读取非终结符及其产生式
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
      // 处理空或 epsilon
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

      // 若包含空格则按空格分割符号；否则将单词拆为单字符符号
      bool hasSpace = (trimmed.find(' ') != string::npos ||
                       trimmed.find('\t') != string::npos);
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

  // 自动推断终结符集合（出现在产生式中但不在非终结符列表中的符号）
  for (auto &p : G.prod) {
    for (auto &rhs : p.second) {
      for (auto &sym : rhs) {
        if (sym == "ε")
          continue;
        if (find(G.nonterminals.begin(), G.nonterminals.end(), sym) ==
            G.nonterminals.end()) {
          if (find(G.terminals.begin(), G.terminals.end(), sym) ==
              G.terminals.end())
            G.terminals.push_back(sym);
        }
      }
    }
  }

  // 计算 FIRST
  map<string, set<string>> firstMemo;
  for (auto &nt : G.nonterminals)
    FIRST(nt, G, firstMemo);

  cout << "FIRST 集合:\n";
  for (auto &nt : G.nonterminals) {
    cout << "FIRST(" << nt << ") = { ";
    for (auto &s : firstMemo[nt])
      cout << s << " ";
    cout << "}\n";
  }

  auto follow = computeFOLLOW(G, firstMemo);
  cout << "\nFOLLOW 集合:\n";
  for (auto &nt : G.nonterminals) {
    cout << "FOLLOW(" << nt << ") = { ";
    for (auto &s : follow[nt])
      cout << s << " ";
    cout << "}\n";
  }

  return 0;
}