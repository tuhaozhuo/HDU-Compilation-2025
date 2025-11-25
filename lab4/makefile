FLEX=/opt/homebrew/opt/flex/bin/flex
BISON=/opt/homebrew/opt/bison/bin/bison
CXX=clang++
CXXFLAGS=-std=c++11

SRC_DIR=src
OUT=compiler

LEX_SRC=$(SRC_DIR)/sysy.l
YACC_SRC=$(SRC_DIR)/sysy.y
MAIN_SRC=$(SRC_DIR)/main.cpp

LEX_CPP=$(SRC_DIR)/sysy.lex.cpp
YACC_CPP=$(SRC_DIR)/sysy.tab.cpp
YACC_HPP=$(SRC_DIR)/sysy.tab.hpp

all: $(OUT)

$(LEX_CPP): $(LEX_SRC)
	@$(FLEX) -o $(LEX_CPP) $(LEX_SRC)
	@echo "[1/3] FLEX文件生成完成"

$(YACC_CPP): $(YACC_SRC)
	@$(BISON) -d -o $(YACC_CPP) $(YACC_SRC)
	@echo "[2/3] BISON文件生成完成"

$(OUT): $(LEX_CPP) $(YACC_CPP) $(MAIN_SRC)
	@$(CXX) $(CXXFLAGS) $(LEX_CPP) $(YACC_CPP) $(MAIN_SRC) -o $(OUT)
	@echo "[3/3] compiler程序编译完成"


.PHONY: all