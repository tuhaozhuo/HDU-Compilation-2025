# HDU-Compilation-2025

> 本仓库收录了 HDU 2025学年《编译原理实践课》的课程作业代码。主要使用 C++ 为 `sysY` 实现一个编译器前端。

---
## 实验环境
- macOS: 14.8
- clang: 16.0.0

注意：exec可执行文件仅适用于macOS环境。在其他环境运行时，请使用GCC等编译器自行编译。

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
- 掌握语法分析的基本流程
- 实现 消去左递归、提取左公共因子、求解FIRST集FOLLOW集 算法
- 构建基础的语法分析器，用于后续编译器前端开发

### Lab 4: 编译器开发与实现
- 使用`Flex`、`Bison`等工具辅助开发编译器前端

---

## 使用说明

1. 克隆仓库：
```bash
git clone git@github.com:tuhaozhuo/HDU-Compilation-2025.git
```
2.	进入实验目录
```
cd ./Compilation
```
3.	编译 C++ 源码：
```bash
# 我为每个实验都编写了 makefile 或 sh脚本，只需要执行以下命令即可

# lab2
cd ./lab2
./lab2.sh

# lab3
cd ./lab3
make

# lab4
./lab4.sh
```