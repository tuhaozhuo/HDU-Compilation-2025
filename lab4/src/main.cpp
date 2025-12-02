#include "AST.hpp"
#include <iostream>
#include <memory>

using namespace std;

int yyparse(unique_ptr<BaseAST> &ast);

int main() {
  unique_ptr<BaseAST> ast;

  if (yyparse(ast) == 0) {
    ast->Dump();
    cout << endl;
  } else {
    cout << "Parse failed." << endl;
  }
  return 0;
}