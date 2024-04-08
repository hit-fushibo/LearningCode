%{
/*TODO:
多叉树定义
属性值计算
 */
#include"syntax.tab.h"
%}

%option yylineno

space " "
digits [0-9]
letter [_a-zA-Z]



INT 0|[1-9]{digits}{0,31}

FLOAT {digits}+\.{digits}+

ID {letter}({letter}|{digits}){0,31}

SEMI ";"

COMMA ","

ASSIGNOP "="

RELOP ">"|"<"|">="|"<="|"=="|"!="

PLUS "+"

MINUS "-"

STAR "*"

DIV "/"

AND "&&"

OR "||"

DOT "."

NOT "!"

TYPE "int"|"float"

LP "("

RP ")"

LB "["

RB "]"

LC "{"

RC "}"

STRUCT "struct"

RETURN "return"

IF "if"

ELSE "else"

WHILE "while"

%%

{TYPE} {
    return TYPE;
}

{STRUCT} {
    return STRUCT;
}

{RETURN} {
    return RETURN;
}

{IF} {
    return IF;
}

{ELSE} {
    return ELSE;
}

{WHILE} {
    return WHILE;
}

{INT} {
    return INT;
}

{FLOAT} {
    return FLOAT;
}

{ID} {
    return ID;
}

{SEMI} {
    return SEMI;
}

{COMMA} {
    return COMMA;
}

{ASSIGNOP} {
    return ASSIGNOP;
}

{RELOP} {
    return RELOP;
}

{PLUS} {
    return PLUS;
}

{MINUS} {
    return MINUS;
}

{STAR} {
    return STAR;
}

{DIV} {
    return DIV;
}

{AND} {
    return AND;
}

{OR} {
    return OR;
}

{DOT} {
    return DOT;
}

{NOT} {
    return NOT;
}

{LP} {
    return LP;
}

{RP} {
    return RP;
}

{LB} {
    return LB;
}

{RB} {
    return RB;
}

{LC} {
    return LC;
}

{RC} {
    return RC;
}


\n

\t

{space}+


. {
    printf("Error type A at line %d:Mysterious character \"%s\".\n",yylineno,yytext);

}

%%
