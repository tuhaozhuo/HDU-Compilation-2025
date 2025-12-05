/**
 * @file AST.hpp
 * @brief SysY 语法分析阶段使用的抽象语法树（AST）定义。
 *
 * 为了方便本实验，我们不区分过多具体节点类型，而是使用一个通用的
 * `NodeAST` 结点来表示语法树节点，通过字符串标签与子节点列表来描述结构。
 * 这样既能覆盖 SysY 的全部语法，又可以让语义分析 / 中间代码生成在后续
 * 实验中按需扩展。
 */

#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

/**
 * @brief 简单缩进打印工具函数，用空格表示树状结构。
 */
inline void PrintIndent(int level) {
  for (int i = 0; i < level; i++) {
    std::cout << "  ";
  }
}

/**
 * @brief AST 所有结点的基类。
 *
 * 这里只保留一个抽象接口 `Dump`，用于打印调试语法树结构。
 * 之后如果需要做语义分析或生成中间代码，可以在派生类中
 * 添加更多接口。
 */
class BaseAST {
public:
  virtual ~BaseAST() = default;

  /// 打印当前结点及其子树，主要用于调试和对拍。
  virtual void Dump() const = 0;
};

/**
 * @brief 通用语法树结点。
 *
 * - `name` 用来描述当前结点的语义标签，例如 `"FuncDef main"`、
 *   `"If"`, `"Add"`, `"IntConst(1)"` 等。
 * - `children` 保存所有子结点，按语法树从左到右的顺序排列。
 *
 * 通过这种“标签 + 子结点列表”的方式，可以覆盖 SysY 语言的全部
 * 语法结构，而不需要为每一种产生式都写一个 C++ 类。
 */
class NodeAST : public BaseAST {
public:
  std::string name;
  std::vector<std::unique_ptr<BaseAST>> children;

  explicit NodeAST(const std::string &n) : name(n) {}

  /// 向当前结点添加一个子结点。
  void Add(std::unique_ptr<BaseAST> child) {
    children.push_back(std::move(child));
  }

  /// 递归打印整棵子树。
  void Dump() const override {
    // 这里使用 static 局部变量来保存缩进层级，便于嵌套打印。
    // 由于 Dump 总是从根结点开始调用，因此这样使用是安全的。
    static int level = 0;
    PrintIndent(level);
    std::cout << name << "\n";
    level++;
    for (const auto &child : children) {
      if (child) {
        child->Dump();
      }
    }
    level--;
  }
};

/**
 * @brief 方便构造“叶子结点”的小工具函数。
 *
 * 在 Bison 动作代码中可以直接使用：
 *   `auto node = new NodeAST("IntConst(1)");`
 * 或者：
 *   `auto leaf = MakeLeaf("Break");`
 */
inline std::unique_ptr<BaseAST> MakeLeaf(const std::string &tag) {
  return std::unique_ptr<BaseAST>(new NodeAST(tag));
}
