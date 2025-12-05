#include "AST.hpp"
#include <iostream>
#include <memory>

using namespace std;

int yyparse(unique_ptr<BaseAST> &ast);

int main() {
  unique_ptr<BaseAST> ast;

  int ret = yyparse(ast);

  // 解析成功：打印 AST，返回 0
  if (ret == 0 && ast) {
    ast->Dump();
    cout << endl;
    return 0;
  }

  // 解析失败：错误信息已由 yyerror 打印，这里只返回非 0 退出码
  cerr << "Parse failed." << endl;
  return 1;
}