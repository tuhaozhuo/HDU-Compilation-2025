#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 文法表示
struct Grammar {
  vector<string> nonterminals; // 非终结符（按用户给定次序）
  vector<string> terminals;
  unordered_map<string, vector<vector<string>>>
      prod; // 产生式映射：A -> { [α1], [α2] ... }
};

// 打印文法
void printGrammar(const Grammar &G) {
  for (auto &A : G.nonterminals) {
    cout << A << " -> ";
    const auto &rules = G.prod.at(A);
    for (int i = 0; i < (int)rules.size(); i++) {
      if (rules[i].empty()) {
        cout << "ε";
      } else {
        for (auto &sym : rules[i])
          cout << sym;
      }
      if (i + 1 != rules.size())
        cout << " | ";
    }
    cout << "\n";
  }
  cout << endl;
}

// 替换产生式：Ai -> Aj ...（其中 j < i）
void replaceProduction(Grammar &G, const string &Ai, const string &Aj) {
  vector<vector<string>> newRules;

  for (auto &rhs : G.prod[Ai]) {
    if (rhs.size() > 0 && rhs[0] == Aj) {
      // Ai -> Aj γ  => Ai -> (Aj 的每个候选) γ
      vector<vector<string>> AjRules = G.prod[Aj];
      for (auto &aj_rhs : AjRules) {
        // aj_rhs 可能为空（表示 ε），合并时直接接上 rhs 的剩余部分
        vector<string> merged = aj_rhs;
        merged.insert(merged.end(), rhs.begin() + 1, rhs.end());
        // 如果 merged 表示 ε（即空），保持为空 vector
        newRules.push_back(merged);
      }
    } else {
      newRules.push_back(rhs);
    }
  }
  G.prod[Ai] = newRules;
}

// 消除 Ai 的直接左递归
void eliminateDirectLeftRecursion(Grammar &G, const string &Ai) {
  vector<vector<string>> alpha; // alpha：形如 Ai → Ai α 的右侧部分
  vector<vector<string>> beta; // beta：形如 Ai → β 的右侧部分（β 不以 Ai 开头）

  for (auto &rhs : G.prod[Ai]) {
    if (rhs.size() > 0 && rhs[0] == Ai) {
      vector<string> rest(rhs.begin() + 1, rhs.end());
      alpha.push_back(rest);
    } else {
      beta.push_back(rhs);
    }
  }

  if (alpha.empty())
    return; // 没有直接左递归

  // 如果没有 beta（即所有产生式都是左递归），把 beta 视作包含空产生式
  if (beta.empty()) {
    beta.push_back(vector<string>()); // 表示 ε
  }

  // 创建新的非终结符 Ai'
  string Ai_new = Ai + "'";
  // 插入到 nonterminals 中紧随 Ai 后面（保持顺序）
  auto it = find(G.nonterminals.begin(), G.nonterminals.end(), Ai);
  if (it != G.nonterminals.end())
    G.nonterminals.insert(it + 1, Ai_new);
  else
    G.nonterminals.push_back(Ai_new);

  vector<vector<string>> Ai_new_rules;

  // Ai → β Ai'
  vector<vector<string>> new_Ai_rules;
  for (auto &b : beta) {
    vector<string> t = b;
    t.push_back(Ai_new);
    new_Ai_rules.push_back(t);
  }

  // Ai' → α Ai' | ε
  for (auto &a : alpha) {
    vector<string> t = a;
    t.push_back(Ai_new);
    Ai_new_rules.push_back(t);
  }
  Ai_new_rules.push_back(vector<string>()); // 将 ε 产生式表示为空向量

  G.prod[Ai] = new_Ai_rules;
  G.prod[Ai_new] = Ai_new_rules;
}

// 主算法：消除左递归
void removeLeftRecursion(Grammar &G) {
  // 不对 nonterminals 做全局排序，保留用户给定的次序
  int n = G.nonterminals.size();
  for (int i = 0; i < n; i++) {
    string Ai = G.nonterminals[i];

    // 步骤1：对 j < i 的 Aj 做替换
    for (int j = 0; j < i; j++) {
      string Aj = G.nonterminals[j];
      replaceProduction(G, Ai, Aj);
    }

    // 步骤2：消除直接左递归
    eliminateDirectLeftRecursion(G, Ai);
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
  getline(cin, line); // consume endline

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
      cerr << "输入无效。\n";
      return 1;
    }
    getline(cin, line); // consume endline

    for (int j = 0; j < m; ++j) {
      cout << "请输入第" << j + 1
           << "个产生式（符号以空格分隔，使用 EPS 或 ε 表示空产生式）：";
      if (!getline(cin, line)) {
        cerr << "读取产生式失败，程序退出。\n";
        return 1;
      }
      // 自动检测：若行含空格则按空格切分；若无空格则把单词拆为单字符符号
      if (line.empty()) {
        // 视为 epsilon
        G.prod[A].push_back(vector<string>());
        continue;
      }
      // trim
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

      // 检查是否包含空格
      bool hasSpace = (trimmed.find(' ') != string::npos ||
                       trimmed.find('\t') != string::npos);
      vector<string> toks;
      if (hasSpace) {
        istringstream ts(trimmed);
        string tok;
        while (ts >> tok)
          toks.push_back(tok);
      } else {
        // 无空格：把单词拆成单字符符号
        for (char c : trimmed)
          toks.push_back(string(1, c));
      }
      G.prod[A].push_back(toks);
    }
  }

  cout << "\n原始文法：\n";
  printGrammar(G);

  removeLeftRecursion(G);
  cout << "消除左递归后的文法：\n";
  printGrammar(G);

  return 0;
}