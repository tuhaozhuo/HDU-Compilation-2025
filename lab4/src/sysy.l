%option noyywrap
%option nounput
%option noinput
%option yylineno

%{

#include <cstdlib>
#include <string>

#include "sysy.tab.hpp"

using namespace std;

%}

/* --------- 模式定义（Definitions） --------- */

WhiteSpace      [ \t\r\n]+
LineComment     "//".*

Identifier      [a-zA-Z_][a-zA-Z0-9_]*

Decimal         [1-9][0-9]*
Octal           0[0-7]*
Hexadecimal     0[xX][0-9a-fA-F]+

Float1          [0-9]+\.[0-9]*([eE][+-]?[0-9]+)?
Float2          \.[0-9]+([eE][+-]?[0-9]+)?
Float3          [0-9]+([eE][+-]?[0-9]+)

%%

 
{WhiteSpace}      { /* skip */ }
{LineComment}     { /* skip */ }

 
"const"           { return CONST; }
"int"             { return INT; }
"void"            { return VOID; }
"float"           { return FLOAT; }
"if"              { return IF; }
"else"            { return ELSE; }
"while"           { return WHILE; }
"break"           { return BREAK; }
"continue"        { return CONTINUE; }
"return"          { return RETURN; }

 
{Identifier}      {
                     yylval.str_val = new string(yytext);
                     return IDENT;
                   }

 
{Float1}          {
                     yylval.float_val = strtof(yytext, nullptr);
                     return FLOAT_CONST;
                   }
{Float2}          {
                     yylval.float_val = strtof(yytext, nullptr);
                     return FLOAT_CONST;
                   }
{Float3}          {
                     yylval.float_val = strtof(yytext, nullptr);
                     return FLOAT_CONST;
                   }

 
{Hexadecimal}     {
                     yylval.int_val = strtol(yytext, nullptr, 0);
                     return INT_CONST;
                   }
{Octal}           {
                     yylval.int_val = strtol(yytext, nullptr, 0);
                     return INT_CONST;
                   }
{Decimal}         {
                     yylval.int_val = strtol(yytext, nullptr, 0);
                     return INT_CONST;
                   }

 
"&&"              { return AND; }
"||"              { return OR; }

 
"<="              { return LE; }
">="              { return GE; }
"=="              { return EQ; }
"!="              { return NE; }
"<"               { return '<'; }
">"               { return '>'; }

 
"+"               { return '+'; }
"-"               { return '-'; }
"*"               { return '*'; }
"/"               { return '/'; }
"%"               { return '%'; }
"="               { return '='; }
"!"               { return '!'; }
";"               { return ';'; }
","               { return ','; }
"("               { return '('; }
")"               { return ')'; }
"{"               { return '{'; }
"}"               { return '}'; }
"["               { return '['; }
"]"               { return ']'; }

 
.                 { return yytext[0]; }

%%