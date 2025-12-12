%code requires {
  #include <memory>
  #include <string>
  #include "AST.hpp"
}

%{

#include <iostream>
#include <memory>
#include <string>
#include "AST.hpp"

// 声明 lexer 函数和错误处理函数
int yylex();
void yyerror(std::unique_ptr<BaseAST> &ast, const char *s);

// Flex 提供的当前行号（在 sysy.l 中启用了 %option yylineno）
extern int yylineno;
// 当前触发错误附近的词法单元文本，由 Flex 提供
extern char *yytext;

using namespace std;

%}

// 定义 parser 函数和错误处理函数的附加参数：
// 通过该参数把最终构建好的 AST 根结点传回 main 函数
%parse-param { std::unique_ptr<BaseAST> &ast }

// 让 Bison 生成更详细的错误信息
%define parse.error verbose

// yylval 的联合体定义：用于在词法/语法之间传递信息
%union {
  std::string *str_val;  // 标识符名等
  int int_val;           // 整型常量
  float float_val;       // 浮点常量
  BaseAST *ast_val;      // AST 结点
}

// ---------- token 声明 ----------
%token CONST VOID INT FLOAT RETURN IF ELSE WHILE BREAK CONTINUE
%token <str_val> IDENT
%token <int_val> INT_CONST
%token <float_val> FLOAT_CONST
%token AND OR EQ NE LE GE

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

// ---------- 非终结符类型 ----------
%type <ast_val> CompUnit
%type <ast_val> CompUnitItems CompUnitItem
%type <ast_val> Decl ConstDecl VarDecl
%type <ast_val> FuncDef
%type <ast_val> Block BlockItems BlockItemsOpt BlockItem
%type <ast_val> Stmt
%type <ast_val> Exp Cond
%type <ast_val> LOrExp LAndExp EqExp RelExp AddExp MulExp UnaryExp PrimaryExp
%type <ast_val> Number
%type <ast_val> LVal
%type <ast_val> FuncRParams FuncRParamsOpt

// ---------- 运算符优先级与结合性 ----------
%left OR
%left AND
%left EQ NE
%left '<' '>' LE GE
%left '+' '-'
%left '*' '/' '%'
%right '!' UPLUS UMINUS

%%

// =================== 编译单元 ===================
// 支持多个函数定义和全局变量 / 常量声明。
CompUnit
  : CompUnitItems {
      ast = std::unique_ptr<BaseAST>($1);
    }
  ;

CompUnitItems
  : CompUnitItem {
      auto node = new NodeAST("CompUnit");
      node->Add(std::unique_ptr<BaseAST>($1));
      $$ = node;
    }
  | CompUnitItems CompUnitItem {
      auto node = static_cast<NodeAST *>($1);
      node->Add(std::unique_ptr<BaseAST>($2));
      $$ = node;
    }
  ;

CompUnitItem
  : Decl   { $$ = $1; }
  | FuncDef { $$ = $1; }
  ;

// =================== 声明 ===================
// BType 仅用于语法约束，此处不单独建 AST 结点。
BType
  : INT
  | FLOAT
  ;

Decl
  : ConstDecl { $$ = $1; }
  | VarDecl   { $$ = $1; }
  ;

ConstDecl
  : CONST BType ConstDefList ';' {
      $$ = new NodeAST("ConstDecl");
    }
  ;

ConstDefList
  : ConstDef
  | ConstDefList ',' ConstDef
  ;

ConstDef
  : IDENT ConstArrayDimsOpt '=' ConstInitVal
  ;

ConstArrayDimsOpt
  : /* empty */
  | ConstArrayDimsOpt '[' ConstExp ']'
  ;

ConstInitVal
  : Exp
  | '{' ConstInitValListOpt '}'
  ;

ConstInitValListOpt
  : /* empty */
  | ConstInitValList
  ;

ConstInitValList
  : ConstInitVal
  | ConstInitValList ',' ConstInitVal
  ;

ConstExp
  : Exp
  ;

VarDecl
  : BType VarDefList ';' {
      $$ = new NodeAST("VarDecl");
    }
  ;

VarDefList
  : VarDef
  | VarDefList ',' VarDef
  ;

VarDef
  : IDENT VarArrayDimsOpt
  | IDENT VarArrayDimsOpt '=' InitVal
  ;

VarArrayDimsOpt
  : /* empty */
  | VarArrayDimsOpt '[' Exp ']'
  ;

InitVal
  : Exp
  | '{' InitValListOpt '}'
  ;

InitValListOpt
  : /* empty */
  | InitValList
  ;

InitValList
  : InitVal
  | InitValList ',' InitVal
  ;

// =================== 函数定义 ===================
/* 函数返回类型统一用两类：void 和 BType(int/float) */

FuncDef
  : VOID IDENT '(' FuncFParamsOpt ')' Block {
      std::string name = *$2;
      delete $2;
      auto node = new NodeAST("FuncDef " + name);
      node->Add(std::unique_ptr<BaseAST>($6)); // Block
      $$ = node;
    }
  | BType IDENT '(' FuncFParamsOpt ')' Block {
      std::string name = *$2;
      delete $2;
      auto node = new NodeAST("FuncDef " + name);
      node->Add(std::unique_ptr<BaseAST>($6)); // Block
      $$ = node;
    }
  ;

FuncFParamsOpt
  : /* empty */
  | FuncFParams
  ;

FuncFParams
  : FuncFParam
  | FuncFParams ',' FuncFParam
  ;

FuncFParam
  : BType IDENT {
      // 标量形参，当前不单独在 AST 中展示
    }
  | BType IDENT FuncFParamArrayDims {
      // 数组形参，同样暂不在 AST 中细化维度信息
    }
  ;

FuncFParamArrayDims
  : '[' Exp ']'
  | FuncFParamArrayDims '[' Exp ']'
  ;

// =================== 语句块 ===================
Block
  : '{' BlockItemsOpt '}' {
      auto node = new NodeAST("Block");
      if ($2) {
        node->Add(std::unique_ptr<BaseAST>($2));
      }
      $$ = node;
    }
  ;

BlockItemsOpt
  : /* empty */ { $$ = nullptr; }
  | BlockItems  { $$ = $1; }
  ;

BlockItems
  : BlockItem {
      auto list = new NodeAST("BlockItems");
      list->Add(std::unique_ptr<BaseAST>($1));
      $$ = list;
    }
  | BlockItems BlockItem {
      auto list = static_cast<NodeAST *>($1);
      list->Add(std::unique_ptr<BaseAST>($2));
      $$ = list;
    }
  ;

BlockItem
  : Decl { $$ = $1; }
  | Stmt { $$ = $1; }
  ;

// =================== 语句 ===================
Stmt
  : LVal '=' Exp ';' {
      auto node = new NodeAST("Assign");
      node->Add(std::unique_ptr<BaseAST>($1));
      node->Add(std::unique_ptr<BaseAST>($3));
      $$ = node;
    }
  | Exp ';' {
      auto node = new NodeAST("ExprStmt");
      node->Add(std::unique_ptr<BaseAST>($1));
      $$ = node;
    }
  | ';' {
      $$ = new NodeAST("EmptyStmt");
    }
  | Block {
      $$ = $1;
    }
  | IF '(' Cond ')' Stmt %prec LOWER_THAN_ELSE {
      auto node = new NodeAST("If");
      node->Add(std::unique_ptr<BaseAST>($3)); // 条件
      node->Add(std::unique_ptr<BaseAST>($5)); // then
      $$ = node;
    }
  | IF '(' Cond ')' Stmt ELSE Stmt {
      auto node = new NodeAST("IfElse");
      node->Add(std::unique_ptr<BaseAST>($3)); // 条件
      node->Add(std::unique_ptr<BaseAST>($5)); // then
      node->Add(std::unique_ptr<BaseAST>($7)); // else
      $$ = node;
    }
  | WHILE '(' Cond ')' Stmt {
      auto node = new NodeAST("While");
      node->Add(std::unique_ptr<BaseAST>($3)); // 条件
      node->Add(std::unique_ptr<BaseAST>($5)); // 循环体
      $$ = node;
    }
  | BREAK ';' {
      $$ = new NodeAST("Break");
    }
  | CONTINUE ';' {
      $$ = new NodeAST("Continue");
    }
  | RETURN Exp ';' {
      auto node = new NodeAST("Return");
      node->Add(std::unique_ptr<BaseAST>($2));
      $$ = node;
    }
  | RETURN ';' {
      $$ = new NodeAST("ReturnVoid");
    }
  ;

// =================== 左值（变量 / 数组元素） ===================
LVal
  : IDENT {
      std::string name = *$1;
      delete $1;
      $$ = new NodeAST("LVal " + name);
    }
  | IDENT LValArrayDims {
      std::string name = *$1;
      delete $1;
      // 为简化实现，这里不单独展示每一维的信息
      $$ = new NodeAST("LValArray " + name);
    }
  ;

LValArrayDims
  : '[' Exp ']'
  | LValArrayDims '[' Exp ']'
  ;

// =================== 表达式 ===================
Exp
  : LOrExp { $$ = $1; }
  ;

Cond
  : LOrExp { $$ = $1; }
  ;

LOrExp
  : LAndExp { $$ = $1; }
  | LOrExp OR LAndExp {
      auto node = new NodeAST("||");
      node->Add(std::unique_ptr<BaseAST>($1));
      node->Add(std::unique_ptr<BaseAST>($3));
      $$ = node;
    }
  ;

LAndExp
  : EqExp { $$ = $1; }
  | LAndExp AND EqExp {
      auto node = new NodeAST("&&");
      node->Add(std::unique_ptr<BaseAST>($1));
      node->Add(std::unique_ptr<BaseAST>($3));
      $$ = node;
    }
  ;

EqExp
  : RelExp { $$ = $1; }
  | EqExp EQ RelExp {
      auto node = new NodeAST("==");
      node->Add(std::unique_ptr<BaseAST>($1));
      node->Add(std::unique_ptr<BaseAST>($3));
      $$ = node;
    }
  | EqExp NE RelExp {
      auto node = new NodeAST("!=");
      node->Add(std::unique_ptr<BaseAST>($1));
      node->Add(std::unique_ptr<BaseAST>($3));
      $$ = node;
    }
  ;

RelExp
  : AddExp { $$ = $1; }
  | RelExp '<' AddExp {
      auto node = new NodeAST("<");
      node->Add(std::unique_ptr<BaseAST>($1));
      node->Add(std::unique_ptr<BaseAST>($3));
      $$ = node;
    }
  | RelExp '>' AddExp {
      auto node = new NodeAST(">");
      node->Add(std::unique_ptr<BaseAST>($1));
      node->Add(std::unique_ptr<BaseAST>($3));
      $$ = node;
    }
  | RelExp LE AddExp {
      auto node = new NodeAST("<=");
      node->Add(std::unique_ptr<BaseAST>($1));
      node->Add(std::unique_ptr<BaseAST>($3));
      $$ = node;
    }
  | RelExp GE AddExp {
      auto node = new NodeAST(">=");
      node->Add(std::unique_ptr<BaseAST>($1));
      node->Add(std::unique_ptr<BaseAST>($3));
      $$ = node;
    }
  ;

AddExp
  : MulExp { $$ = $1; }
  | AddExp '+' MulExp {
      auto node = new NodeAST("+");
      node->Add(std::unique_ptr<BaseAST>($1));
      node->Add(std::unique_ptr<BaseAST>($3));
      $$ = node;
    }
  | AddExp '-' MulExp {
      auto node = new NodeAST("-");
      node->Add(std::unique_ptr<BaseAST>($1));
      node->Add(std::unique_ptr<BaseAST>($3));
      $$ = node;
    }
  ;

MulExp
  : UnaryExp { $$ = $1; }
  | MulExp '*' UnaryExp {
      auto node = new NodeAST("*");
      node->Add(std::unique_ptr<BaseAST>($1));
      node->Add(std::unique_ptr<BaseAST>($3));
      $$ = node;
    }
  | MulExp '/' UnaryExp {
      auto node = new NodeAST("/");
      node->Add(std::unique_ptr<BaseAST>($1));
      node->Add(std::unique_ptr<BaseAST>($3));
      $$ = node;
    }
  | MulExp '%' UnaryExp {
      auto node = new NodeAST("%");
      node->Add(std::unique_ptr<BaseAST>($1));
      node->Add(std::unique_ptr<BaseAST>($3));
      $$ = node;
    }
  ;

UnaryExp
  : PrimaryExp { $$ = $1; }
  | '+' UnaryExp %prec UPLUS {
      auto node = new NodeAST("unary+");
      node->Add(std::unique_ptr<BaseAST>($2));
      $$ = node;
    }
  | '-' UnaryExp %prec UMINUS {
      auto node = new NodeAST("unary-");
      node->Add(std::unique_ptr<BaseAST>($2));
      $$ = node;
    }
  | '!' UnaryExp {
      auto node = new NodeAST("!");
      node->Add(std::unique_ptr<BaseAST>($2));
      $$ = node;
    }
  | IDENT '(' FuncRParamsOpt ')' {
      std::string name = *$1;
      delete $1;
      auto node = new NodeAST("Call " + name);
      if ($3) {
        node->Add(std::unique_ptr<BaseAST>($3));
      }
      $$ = node;
    }
  ;

FuncRParamsOpt
  : /* empty */ { $$ = nullptr; }
  | FuncRParams  { $$ = $1; }
  ;

FuncRParams
  : Exp {
      auto list = new NodeAST("Args");
      list->Add(std::unique_ptr<BaseAST>($1));
      $$ = list;
    }
  | FuncRParams ',' Exp {
      auto list = static_cast<NodeAST *>($1);
      list->Add(std::unique_ptr<BaseAST>($3));
      $$ = list;
    }
  ;

PrimaryExp
  : '(' Exp ')' { $$ = $2; }
  | LVal        { $$ = $1; }
  | Number      { $$ = $1; }
  ;

Number
  : INT_CONST {
      auto node = new NodeAST("IntConst(" + std::to_string($1) + ")");
      $$ = node;
    }
  | FLOAT_CONST {
      auto node = new NodeAST("FloatConst");
      $$ = node;
    }
  ;

%%

// =================== 错误处理 ===================
// 当语法分析出错时，Bison 会调用该函数。
void yyerror(std::unique_ptr<BaseAST> &ast, const char *s) {
  std::cerr << "Syntax error at line " << yylineno
            << " near \"" << (yytext ? yytext : (char*)"<eof>") << "\": "
            << s << std::endl;
}


