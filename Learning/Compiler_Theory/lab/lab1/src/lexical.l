%{
#include"syntax.tab.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int is_null;
    char* name; //node type:INT/FLOAT...
    char* value; //if ID,TYPE,INT,FLOAT
    int lineno; //line
    struct node* right_bro; //the point of its right bro
    struct node* children; //the point of its first child
};
char *int2str(int num);
char *float2str(float num);
struct node* create_token_node(char* name,char*value,int lineno);
extern int is_error;
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
    yylval.node=create_token_node("TYPE",yytext,yylineno);
    return TYPE;
}

{STRUCT} {
    yylval.node = create_token_node("STRUCT", yytext, yylineno);
    return STRUCT;
}

{RETURN} {
    yylval.node = create_token_node("RETURN", yytext, yylineno);
    return RETURN;
}

{IF} {
    yylval.node = create_token_node("IF", yytext, yylineno);
    return IF;
}

{ELSE} {
    yylval.node = create_token_node("ELSE", yytext, yylineno);
    return ELSE;
}

{WHILE} {
    yylval.node = create_token_node("WHILE", yytext, yylineno);
    return WHILE;
}

{INT} {
    yylval.node = create_token_node("INT", yytext, yylineno);
    return INT;
}

{FLOAT} {
    yylval.node = create_token_node("FLOAT", yytext, yylineno);
    return FLOAT;
}

{ID} {
    yylval.node = create_token_node("ID", yytext, yylineno);
    return ID;
}

{SEMI} {
    yylval.node = create_token_node("SEMI", yytext, yylineno);
    return SEMI;
}

{COMMA} {
    yylval.node = create_token_node("COMMA", yytext, yylineno);
    return COMMA;
}

{ASSIGNOP} {
    yylval.node = create_token_node("ASSIGNOP", yytext, yylineno);
    return ASSIGNOP;
}

{RELOP} {
    yylval.node = create_token_node("RELOP", yytext, yylineno);
    return RELOP;
}

{PLUS} {
    yylval.node = create_token_node("PLUS", yytext, yylineno);
    return PLUS;
}

{MINUS} {
    yylval.node = create_token_node("MINUS", yytext, yylineno);
    return MINUS;
}

{STAR} {
    yylval.node = create_token_node("STAR", yytext, yylineno);
    return STAR;
}

{DIV} {
    yylval.node = create_token_node("DIV", yytext, yylineno);
    return DIV;
}

{AND} {
    yylval.node = create_token_node("AND", yytext, yylineno);
    return AND;
}

{OR} {
    yylval.node = create_token_node("OR", yytext, yylineno);
    return OR;
}

{DOT} {
    yylval.node = create_token_node("DOT", yytext, yylineno);
    return DOT;
}

{NOT} {
    yylval.node = create_token_node("NOT", yytext, yylineno);
    return NOT;
}

{LP} {
    yylval.node = create_token_node("LP", yytext, yylineno);
    return LP;
}

{RP} {
    yylval.node = create_token_node("RP", yytext, yylineno);
    return RP;
}

{LB} {
    yylval.node = create_token_node("LB", yytext, yylineno);
    return LB;
}

{RB} {
    yylval.node = create_token_node("RB", yytext, yylineno);
    return RB;
}

{LC} {
    yylval.node = create_token_node("LC", yytext, yylineno);
    return LC;
}

{RC} {
    yylval.node = create_token_node("RC", yytext, yylineno);
    return RC;
}



\n

\t

{space}+


. {
    is_error=1;
    printf("Error type A at line %d:Mysterious character \"%s\".\n",yylineno,yytext);

}

%%
char *int2str(int num) 
{
    char *str = (char *)malloc(20 * sizeof(char)); // 分配足够大的内存空间
    sprintf(str, "%d", num); // 使用sprintf将整数转换为字符串
    return str;
}

char *float2str(float num) 
{
    char *str = (char *)malloc(20 * sizeof(char)); // 分配足够大的内存空间
    sprintf(str, "%f", num); // 使用sprintf将浮点数转换为字符串
    return str;
}
struct node* create_token_node(char* name,char*value,int lineno)
{
    struct node* gram_node=(struct node *)malloc(sizeof(struct node));
    gram_node->is_null=0;
    gram_node->name=(char*)malloc(strlen(name)+2);
    gram_node->value=(char*)malloc(strlen(value)+2);
    strcpy(gram_node->name,name);
    strcpy(gram_node->value,value);
    gram_node->lineno=lineno;
    gram_node->right_bro=NULL;
    gram_node->children=NULL;
    return gram_node;
}