CXX = clang++
CXXFLAGS = -std=c++11 -Iinclude  # 假设有include目录，添加其他必要flags
SRC_DIR = src
EXEC_DIR = exec

# 查找src目录下的所有.cpp文件
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
# 生成对应的可执行文件路径：exec/文件名（去掉扩展名）
EXECS = $(patsubst $(SRC_DIR)/%.cpp, $(EXEC_DIR)/%, $(SRCS))

# 默认目标：构建所有可执行文件
all: $(EXEC_DIR) $(EXECS)

# 创建exec目录
$(EXEC_DIR):
	mkdir -p $(EXEC_DIR)

# 规则：为每个源文件编译可执行文件
$(EXEC_DIR)/%: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# 清理目标
clean:
	rm -rf $(EXEC_DIR)

.PHONY: all clean