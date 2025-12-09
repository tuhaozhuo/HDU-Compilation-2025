#!/bin/bash

# 编译源代码
echo "开始编译源代码"
clang++ -std=c++11 src/dfa_minimize.cpp -o exec/lab2

echo "开始可视化"

# 检查 dot/ 目录是否存在
if [ ! -d "dot" ]; then
    echo "错误: dot/ 目录不存在"
    exit 1
fi

# 检查 pic/ 目录是否存在，如果不存在则创建
if [ ! -d "pic" ]; then
    mkdir pic
fi

# 遍历 dot/ 目录下的所有 .dot 文件
for file in dot/*.dot; do
    if [ -f "$file" ]; then
        # 获取文件名（不含扩展名）
        base=$(basename "$file" .dot)
        # 生成 PNG 文件
        dot -Tpng "$file" -o "pic/${base}.png"
        echo "生成: pic/${base}.png"
    fi
done

echo "可视化完成"