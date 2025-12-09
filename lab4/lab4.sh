#!/bin/bash

echo "开始编译源代码"
make

echo "开始编译测试用例"

# 定义源文件夹路径
SOURCE_DIR="test"

# 定义目标输出文件夹路径
OUTPUT_DIR="output"

# 创建输出文件夹（如果不存在）
mkdir -p "$OUTPUT_DIR"

# 计数用来标记是第几个测试用例
index=0

# 遍历源文件夹中的所有.sy文件
for file in "$SOURCE_DIR"/*.sy; do
    if [ -f "$file" ]; then  # 确保是文件
        index=$((index + 1))

        # 获取文件名（不包含路径）
        filename=$(basename "$file")
        # 获取不带扩展名的文件名
        base_name="${filename%.*}"

        echo "=============================="
        echo "[$index] 测试用例: $filename"

        ./compiler < "$file"
        status=$?

        if [ $status -eq 0 ]; then
            echo "结果: 测试用例 $base_name 编译成功"
        else
            echo "结果: 测试用例 $base_name 编译失败 (退出码: $status)"
        fi
    fi
done

echo "========== 所有测试用例运行完成 =========="