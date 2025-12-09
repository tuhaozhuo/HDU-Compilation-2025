#include <functional>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// ======================= Trie 节点 ==========================
struct TrieNode {
  map<string, TrieNode *> children;   // key: symbol(字符)
  vector<vector<string>> productions; // 存储到达此节点的候选式（剩余部分）
  bool endFlag = false;               // 是否是某个候选式的终点
};

// ======================= 文法表示 ==========================
struct Grammar {
  map<string, vector<vector<string>>> prods; // A -> list of productions
  map<string, int>
      newId; // 针对每个母符号的计数器，用于生成新的非终结符 A', A'', A'''
};

// 生成下一个非终结符名字
string newNonTerminal(const string &base, int id) {
  return base + string(id + 1, '\''); // S', S'', S'''...
}

// ======================= 将产生式插入 Trie ==========================
void insertTrie(TrieNode *root, const vector<string> &prod,
                const vector<string> &fullProd) {
  TrieNode *cur = root;
  for (auto &sym : prod) {
    if (!cur->children.count(sym))
      cur->children[sym] = new TrieNode();
    cur = cur->children[sym];
  }
  cur->endFlag = true;
  cur->productions.push_back(fullProd);
}

// ======================= 递归查找公共前缀（左因子） ==========================
void collectLeftFactoring(
    const string &A, TrieNode *node, vector<string> &path, Grammar &G,
    vector<pair<vector<string>, vector<vector<string>>>> &factors) {
  // 若当前节点存在多分支，或者该节点同时是某产生式的终点且有子节点（即一个产生式是另一个的前缀）
  bool needFactor = (node->children.size() >= 2) ||
                    (node->endFlag && !node->children.empty());

  if (needFactor && path.size() > 0) {
    // 收集属于该节点子树的所有候选式（完整产生式）
    vector<vector<string>> remain;
    // 递归收集子树中的产生式
    function<void(TrieNode *)> gather = [&](TrieNode *n) {
      for (auto &p : n->productions)
        remain.push_back(p);
      for (auto &ch : n->children)
        gather(ch.second);
    };
    gather(node);
    // 存储：公共前缀 path 与这些候选式
    factors.push_back({path, remain});
    // 在此节点已确定因子点，停止向下遍历以避免重叠/嵌套因子
    return;
  }

  // 继续向下DFS
  for (auto &nx : node->children) {
    path.push_back(nx.first);
    collectLeftFactoring(A, nx.second, path, G, factors);
    path.pop_back();
  }
}

// ======================= 应用左因子化 ==========================
void applyLeftFactoring(const string &A, Grammar &G) {
  auto &prodList = G.prods[A];
  if (prodList.size() <= 1)
    return;

  // 构建 Trie 树
  TrieNode *root = new TrieNode();
  for (auto &p : prodList)
    insertTrie(root, p, p);

  // 找出所有公共前缀（因子）
  vector<pair<vector<string>, vector<vector<string>>>> factors;
  vector<string> path;
  collectLeftFactoring(A, root, path, G, factors);

  if (factors.empty())
    return;

  // 构建新的产生式列表（替换原产生式）
  vector<vector<string>> newAprods;

  // 为每个因子生成新的非终结符名，并保存到 newNames 以便后续递归处理
  vector<string> newNames;
  for (auto &f : factors) {
    auto prefix = f.first;
    auto remain = f.second;
    string newA = newNonTerminal(A, G.newId[A]++);
    newNames.push_back(newA);
    // A → prefix newA
    auto s = prefix;
    s.push_back(newA);
    newAprods.push_back(s);

    // newA 的产生式 = remain 的后缀
    for (auto &p : remain) {
      vector<string> suffix(p.begin() + prefix.size(), p.end());
      if (suffix.empty())
        suffix.push_back("ε");
      G.prods[newA].push_back(suffix);
    }
  }

  // 处理未参与因子化的原始产生式（直接保留）
  for (auto &p : prodList) {
    bool covered = false;
    for (auto &f : factors) {
      auto &prefix = f.first;
      if (p.size() >= prefix.size() &&
          equal(prefix.begin(), prefix.end(), p.begin())) {
        covered = true;
        break;
      }
    }
    if (!covered)
      newAprods.push_back(p);
  }

  G.prods[A] = newAprods;

  // 对新生成的非终结符递归进行左因子化
  for (auto &newA : newNames) {
    applyLeftFactoring(newA, G);
  }
}

// ======================= 打印文法 ==========================
void printGrammar(Grammar &G) {
  for (auto &kv : G.prods) {
    cout << kv.first << " -> ";
    for (int i = 0; i < kv.second.size(); ++i) {
      // 将产生式中的符号紧密拼接（无空格），例如 applS'
      for (auto &sym : kv.second[i])
        cout << sym;
      if (i + 1 < kv.second.size())
        cout << " | ";
    }
    cout << "\n";
  }
}

// ======================= 主程序（交互输入） ==========================
int main() {
  Grammar G;

  cout << "请输入非终结符数量： ";
  int n;
  if (!(cin >> n)) {
    cerr << "输入的数量无效，程序退出。\n";
    return 1;
  }
  string line;
  getline(cin, line); // consume endline

  for (int i = 0; i < n; ++i) {
    cout << "请输入第" << i + 1 << "个非终结符名称：";
    string A;
    if (!getline(cin, A)) {
      cerr << "读取非终结符名称失败。\n";
      return 1;
    }

    cout << "请输入 " << A << " 的产生式数量： ";
    int m;
    if (!(cin >> m)) {
      cerr << "输入数量无效。\n";
      return 1;
    }
    getline(cin, line);

    for (int j = 0; j < m; ++j) {
      cout << "请输入第" << j + 1
           << "个产生式（符号以空格分隔，使用 EPS 或 ε 表示空产生式）：";
      if (!getline(cin, line)) {
        cerr << "读取产生式失败。\n";
        return 1;
      }
      istringstream iss(line);
      vector<string> prod;
      string tok;
      while (iss >> tok)
        prod.push_back(tok);
      if (prod.empty()) {
        prod.push_back("ε");
      } else {
        // 自动检测：若整行没有空格且只有一个 token，则将其拆为单字符符号
        if (line.find(' ') == string::npos && prod.size() == 1 &&
            prod[0] != "ε") {
          string w = prod[0];
          prod.clear();
          for (char c : w)
            prod.push_back(string(1, c));
        }
      }
      G.prods[A].push_back(prod);
    }
  }

  cout << "原始文法：\n";
  printGrammar(G);
  cout << "\n\n左因子化后文法：\n";

  // 先收集键以避免边遍历边修改 map
  vector<string> keys;
  for (auto &kv : G.prods)
    keys.push_back(kv.first);
  for (auto &k : keys)
    applyLeftFactoring(k, G);

  printGrammar(G);

  return 0;
}