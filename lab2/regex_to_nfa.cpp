#include <iostream>
#include <vector>
#include <unordered_set>
#include <iomanip> // nfa_to_dfa要用
using namespace std;

// 用0来表示Epsilon
const char EPS = '\0';

// ---------- state 及 NFA数据结构 ----------
struct State {
    int id;
    // 建立一个map（表示路径）：char是字符，vector<int>是下个状态id
    unordered_map<char, vector<int>> trans;
    State(int _id = 0): id(_id) {} 
};

struct NFA {
    unordered_map<int, State> states;  // id -> State 方便按id查找
    int start = -1;
    int accept = -1;
    int id_counter = 0;

    int new_state() {
        int id = id_counter++;
        states.emplace(id, State(id));
        return id;
    }

    void add_transition(int from, char symbol, int to) {
        states[from].trans[symbol].push_back(to);
    }

    void print() const {
        cout << "NFA states (total " << states.size() << "):\n";
        cout << "Start state:" << start << ", Accept state:" << accept << "\n";
        for (auto &p : states) {
            const State &st = p.second;
            cout << " State " << st.id << ":\n";
            for (auto &kv : st.trans) {  // kv是map中的键值对
                char sym = kv.first;     // kv.first是转换符号，kv.second是目标状态列表
                for (int tgt : kv.second) {
                    if (sym == EPS) cout << " -- ε --> " << tgt << "\n";
                    else cout << " -- '" << sym << "' --> " << tgt << "\n";
                }
            }
        }
    }
};

struct Fragment {
    int start;
    int accept;
    Fragment(int s = -1, int a = -1) : start(s), accept(a) {}
};

// ---------- 插入显式连接符'.' ----------
string insert_concat(const string &regex) {
    string out;
    string ops = "|.*()";
    for (size_t i = 0; i < regex.size();++i) {
        char c1 = regex[i];
        out.push_back(c1);
        if (i+1 < regex.size()) {
            char c2 = regex[i+1];

            bool left_atom = (c1 != '|' && c1 != '(');
            bool right_atom = (c2 != '|' && c2 != ')' && c2 != '*');

            if (left_atom && right_atom) {
                out.push_back('.');
            }
        }
    }
    return out;
}

// ---------- 中缀转后缀（shunitng-yard逆波兰表示法） ----------

int precedence(char op) {
    if (op == '*') return 3;
    if (op == '.') return 2;
    if (op == '|') return 1;
    return 0;
}

string to_postfix(const string &regex) {
    string output;
    stack<char> st;
    for (size_t i = 0; i < regex.size(); ++i) {
        char c = regex[i];
        if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                output.push_back(st.top());
                st.pop();
            }
            if (!st.empty() && st.top() == '(') {
                st.pop();
            }
        } else if (c == '|' || c == '.' || c == '*') {
            // '*'是后缀单目运算符，优先级最高直接入栈
            if (c == '*') {
                st.push(c);
            } else {
                while (!st.empty() && precedence(st.top()) > precedence(c)) {
                    output.push_back(st.top());
                    st.pop();
                }
                st.push(c);
            }
        } else {
            output.push_back(c);
        }
    }
    while (!st.empty()) {
        output.push_back(st.top());
        st.pop();
    }
    return output;
}

// ---------- 打印后缀正则表达式 ----------
string human_print_postfix(const string &postfix) {
    string r;
    for (char c : postfix) {
        if (c == EPS) r += "ε";
        else r.push_back(c);
    }
    return r;
}

// ---------- 用 Thompson 方法构造 NFA ----------
NFA build_from_postfix(const string &postfix) {
    NFA nfa;
    stack<Fragment> st;
    for (size_t i = 0; i < postfix.size(); ++i) {
        char token = postfix[i];
        if (token == '.') {
            // '.':先后弹出B和A，并连接 A.accept ->eps-> B.start
            Fragment B = st.top(); st.pop();
            Fragment A = st.top(); st.pop();
            nfa.add_transition(A.accept, EPS, B.start);
            st.push(Fragment(A.start, B.accept));
        } else if (token == '|') {
            // '|':先后弹出B和A，并创建一个新start s 和 accept t
            Fragment B = st.top(); st.pop();
            Fragment A = st.top(); st.pop();
            int s = nfa.new_state();
            int t = nfa.new_state();
            nfa.add_transition(s, EPS, A.start);
            nfa.add_transition(s, EPS, B.start);
            nfa.add_transition(A.accept, EPS, t);
            nfa.add_transition(B.accept, EPS, t);
            st.push(Fragment(s, t));
        } else if (token == '*') {
            // '*':弹出A，并创建s和t，s ->eps-> A.start and s->eps->t; A.accept->eps->A.start and ->eps->t
            Fragment A = st.top(); st.pop();
            int s = nfa.new_state();
            int t = nfa.new_state();
            nfa.add_transition(s, EPS, A.start);
            nfa.add_transition(s, EPS, t);
            nfa.add_transition(A.accept, EPS, A.start);
            nfa.add_transition(A.accept, EPS, t);
            st.push(Fragment(s, t));
        } else {
            int s = nfa.new_state();
            int t = nfa.new_state();
            nfa.add_transition(s, token, t);
            st.push(Fragment(s, t));
        }
    }
    if (st.size() != 1) {
        // 说明不完整，最终情况应该是合成一个的NFA
        throw runtime_error("该正则表达式有误(最终堆栈大小不等于1)");
    }
    Fragment res = st.top(); st.pop();
    nfa.start = res.start;
    nfa.accept = res.accept;
    return nfa;
}

// ---------- 模拟 NFA (epsilon-closure & move) ----------
void epsilon_closure_from(int state, unordered_set<int>& visited, const NFA &nfa) {
    if (visited.count(state)) return;
    visited.insert(state);
    auto it = nfa.states.find(state);
    if (it == nfa.states.end()) return;
    const State &st = it->second;
    auto mit = st.trans.find(EPS);
    if (mit != st.trans.end()) {
        for (int tgt : mit->second) {
            epsilon_closure_from(tgt, visited, nfa);
        }
    }
}

unordered_set<int> epsilon_closure(const unordered_set<int> &stateset, const NFA &nfa) {
    unordered_set<int> res;
    for (int s : stateset) epsilon_closure_from(s, res, nfa);
    return res;
}

unordered_set<int> move_set(const unordered_set<int> &stateset, char symbol, const NFA &nfa) {
    unordered_set<int> res;
    for (int s : stateset) {
        auto it = nfa.states.find(s);
        if (it == nfa.states.end()) continue;
        const  State &st = it->second;
        auto mit = st.trans.find(symbol);
        if (mit != st.trans.end()) {
            for (int tgt : mit->second) res.insert(tgt);
        }
    }
    return res;
}

bool matches_nfa(const NFA &nfa, const string &s) {
    unordered_set<int> cur; cur.insert(nfa.start);
    cur = epsilon_closure(cur, nfa);
    for (char c : s) {
        unordered_set<int> mv = move_set(cur, c, nfa);
        cur = epsilon_closure(mv, nfa);
        if (cur.empty()) return false;
    }
    return cur.count(nfa.accept) > 0;
}


// ---------- Main ----------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "请输入正则表达式(支持:连接隐式,|,*,(),):\n";
    string regex;
    if (!getline(cin, regex)) return 0;

    regex.erase(remove_if(regex.begin(), regex.end(), ::isspace), regex.end());
    string with_concat = insert_concat(regex);
    string postfix = to_postfix(with_concat);

    cout << "处理后(显式连接): " << with_concat << "\n";
    cout << "后缀表达式(postfix): " << postfix << "\n";

    NFA nfa;
    try {
        nfa = build_from_postfix(postfix);
    } catch (const exception &e) {
        cerr << "构造 NFA 时出错: " << e.what() << "\n";
        return 1;
    }

    cout << "\n构造得到的 NFA:\n";
    nfa.print();

    cout << "\n请输入若干测试字符串(每行一个,空行结束时输入):\n";
    vector<string> tests;
    string line;
    while (true) {
        if (!getline(cin, line)) break;
        if (line.empty()) break;
        tests.push_back(line);
    }

    cout << "\n测试结束:\n";
    for (auto &t : tests) {
        bool ok = matches_nfa(nfa, t);
        cout << "'" << t << "' : " << (ok ? "ACCEPTED" : "REJECTED") << "\n";
    }
    return 0;
    
}