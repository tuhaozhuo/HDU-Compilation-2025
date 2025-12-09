#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

// 简单缩进打印工具函数，用空格表示树状结构。

inline void PrintIndent(int level) {
    for (int i = 0; i < level; i++) {
        std::cout << "  ";
    }
}

// AST 所有结点的基类。
class BaseAST {
   public:
    virtual ~BaseAST() = default;

    /// 打印当前结点及其子树，主要用于调试和对拍。
    virtual void Dump() const = 0;
};

// 通用语法树结点。
class NodeAST : public BaseAST {
   public:
    std::string name;
    std::vector<std::unique_ptr<BaseAST>> children;

    explicit NodeAST(const std::string& n) : name(n) {}

    /// 向当前结点添加一个子结点。
    void Add(std::unique_ptr<BaseAST> child) {
        children.push_back(std::move(child));
    }

    /// 递归打印整棵子树。
    void Dump() const override {
        // 这里使用 static 局部变量来保存缩进层级，便于嵌套打印。
        static int level = 0;
        PrintIndent(level);
        std::cout << name << "\n";
        level++;
        for (const auto& child : children) {
            if (child) {
                child->Dump();
            }
        }
        level--;
    }
};

// 构造“叶子结点”的工具函数。
inline std::unique_ptr<BaseAST> MakeLeaf(const std::string& tag) {
    return std::unique_ptr<BaseAST>(new NodeAST(tag));
}
