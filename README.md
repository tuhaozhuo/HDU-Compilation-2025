# HDU-Compilation-2025

> 本仓库收录了 HDU 2025学年《编译原理实践课》的课程作业代码。主要使用 C++ 为 `sys` 实现一个编译器前端。后续内容将不定期更新。

---

## 目录结构

HDU-Compilation-2025/
├─ lab1/       # 编译器基础实验
├─ lab2/       # 词法分析器设计与实现
├─ lab3/       # 尚未完成
├─ lab4/       # 尚未完成    
└─ README.md

---

## 实验内容简介

### Lab 1: 认识编译器
- 学习编译器的基本工作流程。
- 了解 Clang 及其相关操作。
- 练习编译、调试和分析示例程序。

### Lab 2: 词法分析器设计
- 掌握正则表达式在词法分析中的应用。
- 实现 **Regex → NFA → DFA** 的自动转换。
- 构建基础的词法分析器，用于后续编译器前端开发。

### Lab 3: 语法分析器设计

### Lab 4: 编译器开发与实现
---

## 使用说明

1. 克隆仓库：
```bash
git clone git@github.com:tuhaozhuo/HDU-Compilation-2025.git
```
2.	进入实验目录，按各自实验 README 或注释执行代码
```
cd ./Compilation
```
3.	编译 C++ 源码：
```bash
clang -std=c++17 lab2/nfa_to_dfa.cpp -o nfa_to_dfa
./nfa_to_dfa
```