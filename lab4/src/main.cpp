#include <iostream>
#include <memory>
#include <string>

int yyparse(std::unique_ptr<std::string> &ast);

int main() {
  std::unique_ptr<std::string> ast;

  if (yyparse(ast) == 0) {
    std::cout << "AST: " << *ast << std::endl;
  } else {
    std::cout << "Parse failed." << std::endl;
  }
  return 0;
}