#!/bin/bash

# 定义源文件夹路径
SOURCE_DIR="test"

# 定义目标输出文件夹路径
OUTPUT_DIR="output"

# 创建输出文件夹（如果不存在）
mkdir -p "$OUTPUT_DIR"

# 遍历源文件夹中的所有.sy文件
for file in "$SOURCE_DIR"/*.sy; do
    if [ -f "$file" ]; then  # 确保是文件
        # 获取文件名（不包含路径）
        filename=$(basename "$file")
        # 获取不带扩展名的文件名
        base_name="${filename%.*}"
        
        # 编译文件（clang）
        clang -x c -std=c99 -Wall -Wextra -o "$OUTPUT_DIR/$base_name" "$file"
        # 编译文件（compiler）
        # ./compiler < "$file"

        # 检查编译是否成功
        if [ $? -eq 0 ]; then
            echo "编译成功: $file -> $OUTPUT_DIR/$base_name"
        else
            echo "编译失败: $file"
        fi
    fi
done

echo "所有文件编译完成。可执行文件已保存到 $OUTPUT_DIR 文件夹中。"