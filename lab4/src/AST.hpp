#pragma once
#include <iostream>

static void PrintIndent(int level) {
  for (int i = 0; i < level; i++)
    std::cout << "  ";
}

// Base
class BaseAST {
public:
  virtual ~BaseAST() = default;
  virtual void Dump() const = 0;
};

// CompUnit ::= FuncDef
class CompUnitAST : public BaseAST {
public:
  std::unique_ptr<BaseAST> func_def;
  void Dump() const override {
    static int level = 0;
    PrintIndent(level);
    std::cout << "CompUnit\n";
    level++;
    func_def->Dump();
    level--;
  }
};

// FuncDef ::= FuncType IDENT Block
class FuncDefAST : public BaseAST {
public:
  std::unique_ptr<BaseAST> func_type;
  std::string ident;
  std::unique_ptr<BaseAST> block;
  void Dump() const override {
    static int level = 0;
    PrintIndent(level);
    std::cout << "FuncDef: " << ident << "\n";

    level++;
    func_type->Dump();
    block->Dump();
    level--;
  }
};

class FuncTypeAST : public BaseAST {
public:
  std::string type; // "int"
  FuncTypeAST(const std::string &t) : type(t) {}
  void Dump() const override {
    static int level = 0;
    PrintIndent(level);
    std::cout << "FuncType: " << type << "\n";
  }
};

class BlockAST : public BaseAST {
public:
  std::unique_ptr<BaseAST> stmt;
  void Dump() const override {
    static int level = 0;
    PrintIndent(level);
    std::cout << "Block\n";
    level++;
    stmt->Dump();
    level--;
  }
};

// ------ Stmt ------
// Stmt ::= "return" Exp ";"
class StmtAST : public BaseAST {
public:
  std::unique_ptr<BaseAST> exp; // return 的返回值
  void Dump() const override {
    static int level = 0;
    PrintIndent(level);
    std::cout << "ReturnStmt\n";
    level++;
    exp->Dump();
    level--;
  }
};

// ------ Exp ------
// Exp ::= UnaryExp
class ExpAST : public BaseAST {
public:
  std::unique_ptr<BaseAST> unary_exp;
  void Dump() const override {
    static int level = 0;
    PrintIndent(level);
    std::cout << "Exp\n";
    level++;
    unary_exp->Dump();
    level--;
  }
};

// ------ PrimaryExp ------
// PrimaryExp ::= "(" Exp ")" | Number
class PrimaryExpAST : public BaseAST {
public:
  std::unique_ptr<BaseAST> exp_or_num; // 统一保存
  bool is_parenthesis = false;

  void Dump() const override {
    static int level = 0;
    PrintIndent(level);
    std::cout << "PrimaryExp\n";
    level++;
    exp_or_num->Dump();
    level--;
  }
};

// Number ::= INT_CONST
class NumberAST : public BaseAST {
public:
  int value;
  NumberAST(int v) : value(v) {}
  void Dump() const override {
    static int level = 0;
    PrintIndent(level);
    std::cout << "Number: " << value << "\n";
  }
};

// ------ UnaryExp ------
// 1) PrimaryExp
// 2) UnaryOp UnaryExp
class UnaryExpAST : public BaseAST {
public:
  bool is_primary;
  std::unique_ptr<BaseAST> primary;

  std::string op; // "+", "-", "!"
  std::unique_ptr<BaseAST> unary_exp;

  void Dump() const override {
    static int level = 0;
    if (is_primary) {
      PrintIndent(level);
      std::cout << "UnaryExp (Primary)\n";
      level++;
      primary->Dump();
      level--;
    } else {
      PrintIndent(level);
      std::cout << "UnaryExp (Op: " << op << ")\n";
      level++;
      unary_exp->Dump();
      level--;
    }
  }
};

// UnaryOp ::= "+" | "-" | "!"
class UnaryOpAST : public BaseAST {
public:
  std::string op;
  UnaryOpAST(const std::string &o) : op(o) {}
  void Dump() const override {
    static int level = 0;
    PrintIndent(level);
    std::cout << "UnaryOp: " << op << "\n";
  }
};