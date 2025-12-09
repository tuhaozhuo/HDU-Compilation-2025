#include <fstream>
#include <queue>
#include <set>

#include "nfa_to_dfa.cpp"

// ---------- DFA 最小化 ----------
DFA minimize_dfa(const DFA& dfa, const vector<char>& alphabet) {
    // 步骤1: 分离接受和非接受状态
    set<int> accepting, non_accepting;
    for (auto& p : dfa.states) {
        if (p.second.is_accept) {
            accepting.insert(p.first);
        } else {
            non_accepting.insert(p.first);
        }
    }

    // 初始分区
    vector<set<int>> partitions = {non_accepting, accepting};
    vector<set<int>> new_partitions;

    // 映射状态到分区索引
    unordered_map<int, int> state_to_partition;
    for (size_t i = 0; i < partitions.size(); ++i) {
        for (int s : partitions[i]) {
            state_to_partition[s] = i;
        }
    }

    // 工作列表
    queue<set<int>> worklist;
    for (auto& part : partitions) {
        worklist.push(part);
    }

    while (!worklist.empty()) {
        set<int> current = worklist.front();
        worklist.pop();

        for (char a : alphabet) {
            // 找到通过'a'到达当前分区的状态
            set<int> predecessors;
            for (auto& p : dfa.states) {
                int state = p.first;
                auto it = p.second.trans.find(a);
                if (it != p.second.trans.end()) {
                    int next_state = it->second;
                    if (current.count(next_state)) {
                        predecessors.insert(state);
                    }
                }
            }

            // 对每个分区，检查是否需要分裂
            for (size_t i = 0; i < partitions.size(); ++i) {
                set<int>& part = partitions[i];
                set<int> intersect, diff;
                for (int s : part) {
                    if (predecessors.count(s)) {
                        intersect.insert(s);
                    } else {
                        diff.insert(s);
                    }
                }

                if (!intersect.empty() && !diff.empty()) {
                    // 分裂分区
                    partitions.erase(partitions.begin() + i);
                    partitions.push_back(intersect);
                    partitions.push_back(diff);

                    // 更新映射
                    for (int s : intersect) {
                        state_to_partition[s] = partitions.size() - 2;
                    }
                    for (int s : diff) {
                        state_to_partition[s] = partitions.size() - 1;
                    }

                    // 更新工作列表
                    if (worklist.front() == part) {
                        worklist.pop();
                        worklist.push(intersect);
                        worklist.push(diff);
                    } else {
                        worklist.push(intersect);
                        worklist.push(diff);
                    }
                    break;  // 只处理一个分区
                }
            }
        }
    }

    // 构建最小化DFA
    DFA min_dfa;
    unordered_map<int, int> partition_to_new_id;
    for (size_t i = 0; i < partitions.size(); ++i) {
        int new_id = min_dfa.new_state();
        partition_to_new_id[i] = new_id;
        // 选择代表状态
        int rep_state = *partitions[i].begin();
        min_dfa.states[new_id] = dfa.states.at(rep_state);
        min_dfa.states[new_id].id = new_id;
        if (partitions[i].count(dfa.start)) {
            min_dfa.start = new_id;
        }
        if (partitions[i].count(
                *dfa.accept_states
                     .begin())) {  // 简化，假设只有一个接受状态或处理多个
            min_dfa.states[new_id].is_accept = true;
            min_dfa.accept_states.insert(new_id);
        }
    }

    // 设置转移
    for (auto& p : min_dfa.states) {
        int new_id = p.first;
        int old_id =
            *partitions[state_to_partition[new_id]].begin();  // 代表状态
        for (auto& t : dfa.states.at(old_id).trans) {
            char a = t.first;
            int next_old = t.second;
            int next_part = state_to_partition[next_old];
            int next_new = partition_to_new_id[next_part];
            min_dfa.states[new_id].trans[a] = next_new;
        }
    }

    return min_dfa;
}

// ---------- 生成 NFA 的 .dot 文件 ----------
void generate_nfa_dot(const NFA& nfa, const string& filename) {
    ofstream dot_file(filename);
    dot_file << "digraph NFA {\n";
    dot_file << "  rankdir=LR;\n";
    dot_file << "  node [shape=circle];\n";

    // 接受状态用双圆（假设只有一个）
    if (nfa.accept != -1) {
        dot_file << "  " << nfa.accept << " [shape=doublecircle];\n";
    }

    // 开始状态
    dot_file << "  start [shape=point];\n";
    dot_file << "  start -> " << nfa.start << ";\n";

    // 转移
    for (auto& p : nfa.states) {
        int from = p.first;
        for (auto& t : p.second.trans) {
            char sym = t.first;
            for (int to : t.second) {
                string label = (sym == EPS) ? "ε" : string(1, sym);
                dot_file << "  " << from << " -> " << to << " [label=\""
                         << label << "\"];\n";
            }
        }
    }

    dot_file << "}\n";
    dot_file.close();
}

// ---------- 生成 DFA 的 .dot 文件 ----------
void generate_dfa_dot(const DFA& dfa, const string& filename) {
    ofstream dot_file(filename);
    dot_file << "digraph DFA {\n";
    dot_file << "  rankdir=LR;\n";
    dot_file << "  node [shape=circle];\n";

    // 接受状态用双圆
    for (int acc : dfa.accept_states) {
        dot_file << "  " << acc << " [shape=doublecircle];\n";
    }

    // 开始状态
    dot_file << "  start [shape=point];\n";
    dot_file << "  start -> " << dfa.start << ";\n";

    // 转移
    for (auto& p : dfa.states) {
        int from = p.first;
        for (auto& t : p.second.trans) {
            char sym = t.first;
            int to = t.second;
            dot_file << "  " << from << " -> " << to << " [label=\"" << sym
                     << "\"];\n";
        }
    }

    dot_file << "}\n";
    dot_file.close();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "请输入正规表达式(支持隐式连接、｜、*、():)\n";
    string regex;
    if (!getline(cin, regex)) return 0;
    regex.erase(remove_if(regex.begin(), regex.end(), ::isspace), regex.end());

    string with_concat = insert_concat(regex);
    string postfix = to_postfix(with_concat);

    cout << "显式连接: " << with_concat << "\n";
    cout << "后缀表达式(postfix): " << postfix << "\n";

    NFA nfa;
    try {
        nfa = build_from_postfix(postfix);
    } catch (const exception& e) {
        cerr << "构造 NFA 错误: " << e.what() << "\n";
        return 1;
    }

    cout << "\n=== 已成功构造 NFA ===\n";
    // cout << "\n=== 构造得到的 NFA ===\n";
    // nfa.print();

    // 从NFA到DFA
    DFA dfa = nfa_to_dfa(nfa);

    // 生成字母表
    unordered_set<char> alph_set;
    for (auto& p : dfa.states) {
        for (auto& kv : p.second.trans) {
            alph_set.insert(kv.first);
        }
    }
    vector<char> alphabet(alph_set.begin(), alph_set.end());
    sort(alphabet.begin(), alphabet.end());

    cout << "\n=== 已成功构造 DFA ===\n";
    // 打印DFA
    // dfa.print_table(alphabet);

    // 最小化DFA
    DFA min_dfa = minimize_dfa(dfa, alphabet);

    cout << "\n=== 已成功最小化 DFA ===\n";
    // 打印最小化DFA
    // cout << "\n=== 最小化 DFA ===\n";
    // min_dfa.print_table(alphabet);

    // 生成 .dot 文件
    generate_nfa_dot(nfa, "dot/nfa.dot");
    generate_dfa_dot(dfa, "dot/dfa.dot");
    generate_dfa_dot(min_dfa, "dot/min_dfa.dot");

    cout << "\n.dot 文件已生成：dot/nfa.dot, dot/dfa.dot, dot/min_dfa.dot\n";
    cout << "使用 graphviz 可视化：dot -Tpng dot/nfa.dot -o pic/nfa.png\n";

    // 测试
    cout << "请输入测试字符串(每行一个,遇空行结束):\n";
    vector<string> tests;
    string line;
    while (true) {
        if (!getline(cin, line)) break;
        if (line.empty()) break;
        tests.push_back(line);
    }

    cout << "\n=== 测试结果(基于最小化 DFA ) ===\n";
    for (auto& t : tests) {
        bool ok = matches_dfa(min_dfa, t);
        cout << "'" << t << "' -> " << (ok ? "ACCEPTED" : "REJECTED") << "\n";
    }

    return 0;
}