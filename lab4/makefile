FLEX=/opt/homebrew/opt/flex/bin/flex  # 改成本地的flex、bison路径
BISON=/opt/homebrew/opt/bison/bin/bison
CXX=clang++ # Windows系统下建议换成g++
CXXFLAGS=-std=c++11

SRC_DIR=src
EXE_DIR=exe
TEST_DIR=test

LEX_SRC=$(SRC_DIR)/sysy.l
YACC_SRC=$(SRC_DIR)/sysy.y
MAIN_SRC=$(SRC_DIR)/main.cpp

LEX_CPP=$(SRC_DIR)/sysy.lex.cpp
YACC_CPP=$(SRC_DIR)/sysy.tab.cpp
YACC_HPP=$(SRC_DIR)/sysy.tab.hpp

OUT=$(EXE_DIR)/lab4

all: $(OUT)

$(LEX_CPP): $(LEX_SRC)
	@$(FLEX) -o $(LEX_CPP) $(LEX_SRC)
	@echo "[1/3] FLEX文件生成完成" 

$(YACC_CPP): $(YACC_SRC)
	@$(BISON) -d -o $(YACC_CPP) $(YACC_SRC)
	@echo "[2/3] BISON文件生成完成"

$(OUT): $(LEX_CPP) $(YACC_CPP) $(MAIN_SRC)
	@$(CXX) $(CXXFLAGS) $(LEX_CPP) $(YACC_CPP) $(MAIN_SRC) -o $(OUT)
	@echo "[3/3] lab4程序编译完成"


only:
	@if [ -f $(LEX_CPP) ] && [ -f $(YACC_CPP) ] && [ -f $(MAIN_SRC) ]; then \
        $(CXX) $(CXXFLAGS) $(LEX_CPP) $(YACC_CPP) $(MAIN_SRC) -o $(OUT); \
        echo "[1/1] lab4程序编译完成"; \
    else \
        echo "Error: Required files ($(LEX_CPP), $(YACC_CPP), $(MAIN_SRC)) not found. Run 'make' first."; \
    fi


test: $(OUT)
	@echo "开始编译测试用例"
	@index=0; \
	for file in "$(TEST_DIR)"/*.sy; do \
		if [ -f "$$file" ]; then \
            index=$$((index + 1)); \
            filename=$$(basename "$$file"); \
            base_name="$${filename%.*}"; \
            echo "=============================="; \
            echo "[$$index] 测试用例: $$filename"; \
            "$(OUT)" < "$$file"; \
            status=$$?; \
            if [ $$status -eq 0 ]; then \
				echo "结果: 测试用例 $$base_name 编译成功"; \
            else \
				echo "结果: 测试用例 $$base_name 编译失败 (退出码: $$status)"; \
			fi; \
		fi; \
	done


clean:
	rm -rf $(LEX_CPP) $(YACC_CPP) $(YACC_HPP)


.PHONY: all only test clean