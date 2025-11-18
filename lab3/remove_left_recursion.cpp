#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Grammar representation
struct Grammar {
  vector<string> nonterminals; // sorted nonterminals
  vector<string> terminals;
  unordered_map<string, vector<vector<string>>> prod; // A -> { [α1], [α2] ... }
};

// Utility: print grammar
void printGrammar(const Grammar &G) {
  for (auto &A : G.nonterminals) {
    cout << A << " -> ";
    const auto &rules = G.prod.at(A);
    for (int i = 0; i < (int)rules.size(); i++) {
      if (rules[i].empty()) {
        cout << "ε";
      } else {
        for (auto &sym : rules[i])
          cout << sym << " ";
      }
      if (i + 1 != rules.size())
        cout << "| ";
    }
    cout << "\n";
  }
  cout << endl;
}

// Replace productions: Ai -> Aj ...   (where j < i)
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

// Eliminate direct left recursion of Ai
void eliminateDirectLeftRecursion(Grammar &G, const string &Ai) {
  vector<vector<string>> alpha; // Ai → Ai α
  vector<vector<string>> beta;  // Ai → β (β 不以 Ai 开头)

  for (auto &rhs : G.prod[Ai]) {
    if (rhs.size() > 0 && rhs[0] == Ai) {
      vector<string> rest(rhs.begin() + 1, rhs.end());
      alpha.push_back(rest);
    } else {
      beta.push_back(rhs);
    }
  }

  if (alpha.empty())
    return; // no direct left recursion

  // 如果没有 beta（即所有产生式都是左递归），把 beta 视作包含空产生式
  if (beta.empty()) {
    beta.push_back(vector<string>()); // 表示 ε
  }

  // Create new nonterminal Ai'
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
  Ai_new_rules.push_back(vector<string>()); // ε-production as empty vector

  G.prod[Ai] = new_Ai_rules;
  G.prod[Ai_new] = Ai_new_rules;
}

// Main algorithm: remove left recursion
void removeLeftRecursion(Grammar &G) {
  // 不对 nonterminals 做全局排序，保留用户给定的次序
  int n = G.nonterminals.size();
  for (int i = 0; i < n; i++) {
    string Ai = G.nonterminals[i];

    // Step 1: Replace Aj for j < i
    for (int j = 0; j < i; j++) {
      string Aj = G.nonterminals[j];
      replaceProduction(G, Ai, Aj);
    }

    // Step 2: Eliminate direct left recursion
    eliminateDirectLeftRecursion(G, Ai);
  }
}

int main() {
  Grammar G;

  // 输入非终结符
  cout << "请输入以空格分割的终结符 (e.g. A B C): ";
  string line;
  getline(cin, line);
  istringstream ss(line);
  string sym;
  while (ss >> sym)
    G.nonterminals.push_back(sym);

  // 终结符（可选）
  cout << "请输入以空格分割的非终结符 (可留空): ";
  getline(cin, line);
  ss.clear();
  ss.str(line);
  while (ss >> sym)
    G.terminals.push_back(sym);

  // 逐个读取每个非终结符的产生式
  for (auto &A : G.nonterminals) {
    cout << "请输入终结符 " << A << " 的产生式。"
         << "并用'|'表示分割,用'EPS'表示为空\n";
    cout << A << " -> ";
    getline(cin, line);
    if (line.empty()) {
      cout << "没有终结符 " << A << " 的产生式,跳过\n";
      continue;
    }

    // 按 '|' 分割替代式
    size_t pos = 0;
    while (pos < line.size()) {
      size_t bar = line.find('|', pos);
      string alt = (bar == string::npos) ? line.substr(pos)
                                         : line.substr(pos, bar - pos);
      // trim
      size_t l = alt.find_first_not_of(" \t");
      if (l == string::npos)
        alt = "";
      else {
        size_t r = alt.find_last_not_of(" \t");
        alt = alt.substr(l, r - l + 1);
      }

      if (alt == "EPS" || alt == "ε" || alt == "eps" || alt.empty()) {
        G.prod[A].push_back(vector<string>()); // ε
      } else {
        istringstream ts(alt);
        vector<string> toks;
        string tok;
        while (ts >> tok)
          toks.push_back(tok);
        G.prod[A].push_back(toks);
      }

      if (bar == string::npos)
        break;
      pos = bar + 1;
    }
  }

  cout << "\n原始语法为:\n";
  printGrammar(G);

  removeLeftRecursion(G);

  cout << "消去左递归后的语法为:\n";
  printGrammar(G);

  return 0;
}