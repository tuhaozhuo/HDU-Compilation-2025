#include "regex_to_nfa.cpp"

// ---------- DFA 数据结构 ----------
struct DFAState {
    int id;
    vector<int> nfa_subset; 
    unordered_map<char, int> trans; // 字符对应的下一个状态
    bool is_accept = false;
    DFAState(int _id = 0): id(_id) {}
};

struct DFA {
    unordered_map<int, DFAState> states;
    int start = -1;
    unordered_set<int> accept_states;
    int id_counter = 0;

    int new_state() {
        int id = id_counter++;
        states.emplace(id, DFAState(id));
        return id;
    }

    void print_table(const vector<char>& alphabet) const {
        // 打印DNF的基本信息
        cout << "\nDNF states (total" << states.size() << "):\n";
        cout << "Start: " << start << ", Accept states:";
        for (int a : accept_states) cout << " " << a;
        cout << "\n\n";

        // 建立从DFAid映射到子集字符串的map
        unordered_map<int, string> subset_str;
        for (auto &p : states) {
            int id = p.first;
            const auto &sub = p.second.nfa_subset;
            string s = "{";
            for (size_t i = 0; i < sub.size(); ++i) {
                if (i) s += ",";
                s += to_string(sub[i]);
            }
            s += "}";
            subset_str[id] = s;
        }

        // 打印表头
        cout << left << setw(8) << "DNF_ID" << setw(20) << "NFA_subset";
        for (char a : alphabet) {
            string col(1,a);
            cout << setw(8) << col;
        }
        cout << setw(10) << "Accept" << "\n";

        vector<int> keys;
        for (auto &p : states) keys.push_back(p.first);
        sort(keys.begin(), keys.end());
        for (int id : keys) {
            const DFAState &ds = states.at(id);
            cout << left << setw(8) << id << setw(20) << subset_str.at(id);
            for (char a : alphabet) {
                auto it = ds.trans.find(a);
                if (it == ds.trans.end()) cout << setw(8) << "-";
                else cout << setw(8) << it->second;
            }
            cout << setw(10) << (ds.is_accept ? "YES" : "NO") << "\n";
        }
    }
};

// ---------- 子集构造法 ----------
DFA nfa_to_dfa(const NFA &nfa) {
    // 确定字母表
    unordered_set<char> alph_set;
    for (auto &p : nfa.states) {
        for (auto &kv : p.second.trans) {
            char sym = kv.first;
            if (sym != EPS) alph_set.insert(sym);
        }
    }
    vector<char> alphabet(alph_set.begin(), alph_set.end());
    sort(alphabet.begin(), alphabet.end());

    DFA dfa;
    // 把子集字符串的值映射到DFA的id上
    unordered_map<string, int> subset_map;

    auto subset_key = [&](const unordered_set<int>& sset)->string {
        vector<int> v(sset.begin(), sset.end());
        sort(v.begin(), v.end());
        string k;
        for (int x : v) { k += to_string(x); k.push_back(',');}
        return k;
    };

    // 开始节点闭包
    unordered_set<int> start_set;
    start_set.insert(nfa.start);
    start_set = epsilon_closure(start_set, nfa);
    string start_key = subset_key(start_set);
    int start_id = dfa.new_state();
    subset_map[start_key] = start_id;
    // 把子集存进DFAState
    {
        vector<int> vv(start_set.begin(), start_set.end());
        dfa.states[start_id].nfa_subset = vv;
        if (start_set.count(nfa.accept)) { 
            dfa.states[start_id].is_accept = true;
            dfa.accept_states.insert(start_id);
        }
    }
    dfa.start = start_id;

    // BFS遍历
    queue<string> q;
    q.push(start_key);

    while (!q.empty()) {
        string cur_key = q.front();
        q.pop();
        int cur_dfa_id = subset_map[cur_key];
        // 从key中重新设set
        unordered_set<int> cur_set;
        if (!cur_key.empty()) {
            string tmp;
            for (char ch : cur_key) {
                if (ch == ',') {
                    if (!tmp.empty()) {
                        cur_set.insert(stoi(tmp));
                        tmp.clear();
                    }
                } else tmp.push_back(ch);
            }
        }
        // 对字母表上的每一个符号执行move和闭包
        for (char a : alphabet) {
            unordered_set<int> move_res = move_set(cur_set, a, nfa);
            if (move_res.empty()) continue;
            unordered_set<int> closure_res = epsilon_closure(move_res, nfa);
            string key = subset_key(closure_res);
            if (!subset_map.count(key)) {
                int nid = dfa.new_state();
                subset_map[key] = nid;
                // 保存子集
                vector<int> vv(closure_res.begin(), closure_res.end());
                sort(vv.begin(), vv.end());
                dfa.states[nid].nfa_subset = vv;
                if (closure_res.count(nfa.accept)) {
                    dfa.states[nid].is_accept = true;
                    dfa.accept_states.insert(nid);
                }
                q.push(key);
            }
            int target_dfa = subset_map[key];
            dfa.states[cur_dfa_id].trans[a] = target_dfa;
        }
    }
    return dfa;
}

// ---------- 模拟DFA ----------
bool matches_dfa(const DFA &dfa, const string &s) {
    int cur = dfa.start;
    for (char c : s) {
        auto it = dfa.states.at(cur).trans.find(c);
        if (it == dfa.states.at(cur).trans.end()) return false;
        cur = it->second;
    }
    return dfa.states.at(cur).is_accept;
}

// ---------- Utilities ----------
string read_line_trim() {
    string s;
    if (!getline(cin, s)) return "";
    // 去掉空格
    s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
    return s;
}

// ---------- main ----------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "请输入正规表达式(支持隐式连接、｜、*、():)\n";
    // string regex = read_line_trim();
    string regex;
    if (!getline(cin, regex)) return 0;
    regex.erase(remove_if(regex.begin(), regex.end(), ::isspace), regex.end());

    string with_concat = insert_concat(regex);
    string postfix = to_postfix(with_concat);

    cout << "显式连接: " << with_concat << "\n";
    cout << "后缀表达式(postfix): " << postfix << "\n";

    NFA nfa;
    try { nfa = build_from_postfix(postfix); }
    catch (const exception &e) { cerr << "构造 NFA 错误: " << e.what() << "\n"; return 1; }

    cout << "\n=== 构造得到的 NFA ===\n";
    nfa.print();

    // 从NFA到DFA
    DFA dfa = nfa_to_dfa(nfa);

    // 生成字母表
    unordered_set<char> alph_set;
    for (auto &p : dfa.states) for (auto &kv : p.second.trans) alph_set.insert(kv.first);
    vector<char> alphabet(alph_set.begin(), alph_set.end());
    sort(alphabet.begin(), alphabet.end());

    // 打印DFA
    dfa.print_table(alphabet);

    // 测试
    cout << "请输入测试字符串(每行一个,遇空行结束):\n";
    vector<string> tests;
    string line;
    while (true) {
        if (!getline(cin, line)) break;
        if (line.empty()) break;
        tests.push_back(line);
    }

    cout << "\n=== 测试结果(基于 DFA ) ===\n";
    for (auto &t :tests) {
        bool ok = matches_dfa(dfa, t);
        cout << "'" << t << "' -> " << (ok ? "ACCEPTED" : "REJECTED") << "\n";
    }

    return 0;
    
}