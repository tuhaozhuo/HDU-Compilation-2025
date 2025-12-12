# HDU-Compilation-2025

> 本仓库收录了 HDU 2025 学年《编译原理实践课》的课程作业代码。主要使用 C++ 为 `SysY` 语言实现一个编译器前端，涵盖词法分析、语法分析等关键模块。

## 实验环境

- **操作系统**: macOS 14.8
- **编译器**: Clang 16.0.0
- **可视化工具**: Dot 14.0.4
- **词法分析工具**: Flex 2.6.4
- **语法分析工具**: Bison 2.3

**注意**: `exe` 目录下的可执行文件`.exec`仅适用于 macOS 环境。在其他平台（如 Linux/Windows）上运行时，若无对应`.exe`文件，请使用 GCC 或 Clang 自行编译源码。

### 依赖安装

在 macOS 上，使用 Homebrew 安装依赖：

```bash
brew install flex bison clang dot
```
对于其他系统，请参考官方文档安装相应工具。

## 实验内容简介
Lab 1: 认识编译器
- 学习编译器的基本工作流程。

- 熟悉 Clang 编译器及其调试工具。

- 通过示例程序练习编译、调试和性能分析。

Lab 2: 词法分析器设计

- 掌握正则表达式在词法分析中的应用。

- 实现 Regex → NFA → DFA 的自动转换算法。

- 构建基础词法分析器，为后续编译器前端奠定基础。

Lab 3: 语法分析器设计

- 掌握语法分析的基本流程。

- 实现消去左递归、提取左公共因子、求解 FIRST 集和 FOLLOW 集的算法。

- 构建基础语法分析器，包括 LL(1) 文法判断和预测分析表生成。

Lab 4: 编译器开发与实现

- 使用 Flex 和 Bison 工具辅助开发编译器前端。

- 实现 SysY 语言的词法和语法分析，生成抽象语法树 (AST)。

## 项目结构
```text
.
├── README.md         # 项目说明
├── lab1
├── lab2
│   ├── dot           # 可视化文件
│   ├── exe           # 可执行文件
│   ├── lab2.sh       # 编译、测试脚本
│   ├── pic           # 可视化图片
│   └── src           # 源代码
├── lab3
│   ├── exe           # 可执行文件
│   ├── makefile      # 编译脚本
│   └── src           # 源代码
└── lab4
    ├── exe           # 可执行文件
    ├── makefile      # 编译脚本
    ├── src           # 源代码
    └── test          # 测试用例
```

## 使用说明
1. 克隆仓库
```bash
git clone https://github.com/tuhaozhuo/HDU-Compilation-2025.git
cd HDU-Compilation-2025/Compilation
```
2. 编译和运行各实验
- lab2
```bash
cd lab2
./lab2.sh  # 编译并运行词法分析器
```

- lab3
```bash
cd lab3
make  # 编译语法分析器
./exe/ll1  # 运行 LL(1) 判断程序
```

- lab4
```bash
cd lab4
make       # 生成 Flex/Bison 文件并编译
# 或 make only  # 仅编译（若已生成中间文件）
make test  # 运行测试脚本，遍历 test/ 目录中的用例
```
3. 测试
各实验的`test/`目录包含测试用例。
运行`make test`可自动测试 Lab 4 的编译器前端。

## 常见问题
- 编译错误: 确保 Flex 和 Bison 已正确安装，并使用 make clean 清理后重新编译。
- 平台兼容性: Windows 用户可使用 WSL 或 MinGW 环境。
- 依赖版本: 若遇到版本冲突，尝试更新工具。