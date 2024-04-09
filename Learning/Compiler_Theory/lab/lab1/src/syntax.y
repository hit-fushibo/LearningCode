/*TODO :
重写yyerror

 */

/**************************/
%{
#include"lex.yy.c"
#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>
void print_tree(struct node* root,int depth);
struct node* create_gram_node(int is_null,char* name,char* value,int lineno);
void add_child(struct node* root,struct node* child);
void yyerror();
int is_error=0;
%}

%union{
    struct node* node;
}

/****token define****/


/***Terminal Symbol***/

%token <node> INT

%token <node> FLOAT

%token <node> ID

%token <node> SEMI 

%token <node> COMMA 

%token <node> ASSIGNOP

%token <node> RELOP 

%token <node> PLUS 

%token <node> MINUS 

%token <node> STAR 

%token <node> DIV 

%token <node> AND 

%token <node> OR 

%token <node> DOT 

%token <node> NOT 

%token <node> TYPE 

%token <node> LP 

%token <node> RP 

%token <node> LB 

%token <node> RB 

%token <node> LC 

%token <node> RC 

%token <node> STRUCT 

%token <node> RETURN 

%token <node> IF 

%token <node> ELSE

%token <node> WHILE


/***Non-terminal symbol***/

%type <node> Program

%type <node> ExtDefList

%type <node> ExtDef

%type <node> Specifier

%type <node> ExtDecList

%type <node> FunDec

%type <node> CompSt

%type <node> VarDec

%type <node> StructSpecifier

%type <node> OptTag

%type <node> Tag

%type <node> DefList

%type <node> Def

%type <node> DecList

%type <node> Dec

%type <node> VarList

%type <node> ParamDec

%type <node> StmtList

%type <node> Stmt

%type <node> Exp

%type <node> Args


/***error***/
%type error


/***associativity***/
%left LP
%left RP
%left LB
%left RB
%left LC
%left RC
%left DOT
%left STAR
%left DIV
%left PLUS
%left MINUS
%left RELOP
%left AND
%left OR

%right NOT
%right ASSIGNOP


/**lower than else**/
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE



%%
/**************************/

/****high-level def****/
Program : ExtDefList {
    $$=create_gram_node(0,"Program","",yylineno);
    add_child($$,$1);
    if(is_error==0)
    {
        print_tree($$,1);
    }
}
;

ExtDefList : ExtDef ExtDefList {$$=create_gram_node(0,"ExtDefList","",yylineno);add_child($$,$1);add_child($$,$2);}
    | /*epsilon*/ {$$=create_gram_node(1,"ExtDefList","",yylineno);}
;

ExtDef :  Specifier ExtDecList error SEMI {is_error=1;}
    | Specifier error SEMI {is_error=1;}
    | Specifier ExtDecList SEMI {$$=create_gram_node(0,"ExtDef","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);}
    | Specifier SEMI {$$=create_gram_node(0,"ExtDef","",yylineno);add_child($$,$1);add_child($$,$2);}
    | Specifier FunDec CompSt {$$=create_gram_node(0,"ExtDef","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);}
;

ExtDecList : VarDec {$$=create_gram_node(0,"ExtDecList","",yylineno);add_child($$,$1);}
    | VarDec COMMA ExtDecList {$$=create_gram_node(0,"ExtDecList","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);}
;

/****Specifiers****/
Specifier : TYPE {$$=create_gram_node(0,"Specifier","",yylineno);add_child($$,$1);}
    | StructSpecifier {$$=create_gram_node(0,"Specifier","",yylineno);add_child($$,$1);}
;

StructSpecifier : STRUCT OptTag LC DefList error RC {is_error=1;}
    | STRUCT OptTag LC DefList RC {$$=create_gram_node(0,"StructSpecifier","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);add_child($$,$4);add_child($$,$5);}
    | STRUCT Tag {$$=create_gram_node(0,"StructSpecifier","",yylineno);add_child($$,$1);add_child($$,$2);}
;

OptTag : ID {$$=create_gram_node(0,"OptTag","",yylineno);add_child($$,$1);}
    | /*epsilon*/ {$$=create_gram_node(1,"OptTag","",yylineno);}
;

Tag : ID {$$=create_gram_node(0,"Tag","",yylineno);add_child($$,$1);}
;

/****Declarators****/

VarDec : ID {$$=create_gram_node(0,"VarDec","",yylineno);add_child($$,$1);}
    | VarDec LB INT error RB {is_error=1;}
    | VarDec LB INT RB {$$=create_gram_node(0,"VarDec","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);add_child($$,$4);}
;

FunDec : ID LP VarList error RP {is_error=1;}
    | ID LP error RP {is_error=1;}
    | ID LP VarList RP {$$=create_gram_node(0,"FunDec","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);add_child($$,$4);}
    | ID LP RP {$$=create_gram_node(0,"FunDec","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);}
;

VarList : ParamDec COMMA VarList {$$=create_gram_node(0,"VarList","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);}
    | ParamDec {$$=create_gram_node(0,"VarList","",yylineno);add_child($$,$1);}
;

ParamDec : Specifier VarDec {$$=create_gram_node(0,"ParamDec","",yylineno);add_child($$,$1);add_child($$,$2);}
;

/****Statements****/
CompSt : LC DefList StmtList error RC {is_error=1;} 
    | LC DefList StmtList RC {$$=create_gram_node(0,"CompSt","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);add_child($$,$4);}
;

StmtList : Stmt StmtList {$$=create_gram_node(0,"StmtList","",yylineno);add_child($$,$1);add_child($$,$2);}
    | /*epsilon*/ {$$=create_gram_node(1,"StmtList","",yylineno);}
;

Stmt : Exp error SEMI{is_error=1;}
    | RETURN Exp error SEMI{is_error=1;}
    | IF LP Exp error RP Stmt %prec LOWER_THAN_ELSE{is_error=1;}
    | IF LP Exp error RP Stmt ELSE Stmt {is_error=1;}
    | WHILE LP Exp error RP Stmt {is_error=1;}
    | Exp SEMI{$$=create_gram_node(0,"Stmt","",yylineno);add_child($$,$1);add_child($$,$2);}
    | CompSt{$$=create_gram_node(0,"Stmt","",yylineno);add_child($$,$1);}
    | RETURN Exp SEMI{$$=create_gram_node(0,"Stmt","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);}
    | IF LP Exp RP Stmt %prec LOWER_THAN_ELSE{$$=create_gram_node(0,"Stmt","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);add_child($$,$4);add_child($$,$5);}
    | IF LP Exp RP Stmt ELSE Stmt {$$=create_gram_node(0,"Stmt","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);add_child($$,$4);add_child($$,$5);add_child($$,$6);add_child($$,$7);}
    | WHILE LP Exp RP Stmt {$$=create_gram_node(0,"Stmt","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);add_child($$,$4);add_child($$,$5);}
;

/****Local Definitions****/
DefList : Def DefList {$$=create_gram_node(0,"DefList","",yylineno);add_child($$,$1);add_child($$,$2);}
    | /*epsilon*/ {$$=create_gram_node(1,"DefList","",yylineno);}
;

Def : Specifier DecList error SEMI {is_error=1;}
    | Specifier DecList SEMI {$$=create_gram_node(0,"Def","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);}
;

DecList : Dec {$$=create_gram_node(0,"DecList","",yylineno);add_child($$,$1);}
    | Dec COMMA DecList {$$=create_gram_node(0,"DecList","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);}
;

Dec : VarDec {$$=create_gram_node(0,"Dec","",yylineno);add_child($$,$1);}
    | VarDec ASSIGNOP Exp {$$=create_gram_node(0,"Dec","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);}
;

/****Expressions****/
Exp : Exp ASSIGNOP Exp {$$=create_gram_node(0,"Exp","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);}
    | Exp AND Exp {$$=create_gram_node(0,"Exp","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);}
    | Exp OR Exp {$$=create_gram_node(0,"Exp","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);}
    | Exp RELOP Exp {$$=create_gram_node(0,"Exp","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);}
    | Exp PLUS Exp {$$=create_gram_node(0,"Exp","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);}
    | Exp MINUS Exp {$$=create_gram_node(0,"Exp","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);}
    | Exp STAR Exp {$$=create_gram_node(0,"Exp","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);}
    | Exp DIV Exp {$$=create_gram_node(0,"Exp","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);}
    | LP Exp error RP {is_error=1;}
    | LP Exp RP {$$=create_gram_node(0,"Exp","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);}
    | MINUS Exp {$$=create_gram_node(0,"Exp","",yylineno);add_child($$,$1);add_child($$,$2);}
    | NOT Exp {$$=create_gram_node(0,"Exp","",yylineno);add_child($$,$1);add_child($$,$2);}
    | ID LP Args error RP {is_error=1;}
    | ID LP error RP {is_error=1;}
    | Exp LB Exp error RB {is_error=1;}
    | ID LP Args RP {$$=create_gram_node(0,"Exp","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);add_child($$,$4);}
    | ID LP RP {$$=create_gram_node(0,"Exp","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);}
    | Exp LB Exp RB {$$=create_gram_node(0,"Exp","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);add_child($$,$4);}
    | Exp DOT ID {$$=create_gram_node(0,"Exp","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);}
    | ID {$$=create_gram_node(0,"Exp","",yylineno);add_child($$,$1);}
    | INT {$$=create_gram_node(0,"Exp","",yylineno);add_child($$,$1);}
    | FLOAT {$$=create_gram_node(0,"Exp","",yylineno);add_child($$,$1);}
;

Args : Exp COMMA Args {$$=create_gram_node(0,"Args","",yylineno);add_child($$,$1);add_child($$,$2);add_child($$,$3);}
    | Exp {$$=create_gram_node(0,"Args","",yylineno);add_child($$,$1);}
;


%%
/**************************/

struct node* create_gram_node(int is_null, char* name, char* value, int lineno) {
    struct node* gram_node=(struct node *)malloc(sizeof(struct node));
    gram_node->is_null=is_null;
    gram_node->name=(char*)malloc(strlen(name)+2);
    gram_node->value=(char*)malloc(strlen(value)+2);
    strcpy(gram_node->name,name);
    strcpy(gram_node->value,value);
    gram_node->lineno=lineno;
    gram_node->right_bro=NULL;
    gram_node->children=NULL;
    return gram_node;
}

void add_child(struct node* root, struct node* child) {
    if (root == NULL || child == NULL) {
        fprintf(stderr, "Invalid input: root or child is NULL");
        return;
    }
    if (root->children == NULL) {
        root->children = child;
        root->lineno=child->lineno;
    } else {
        struct node* temp = root->children;
        while (temp->right_bro != NULL) {
            temp = temp->right_bro;
        }
        temp->right_bro = child;
    }
}

void print_tree(struct node *root, int depth)
{
    if (root != NULL && root->is_null==0)
    {
        for (int i = 0; i < depth; i++)
        {
            printf("  ");
        }
        // 结构体属性输出
        printf("%s",root->name);
        if(strcmp(root->name,"ID")==0){
            printf(" :%s",root->value);
        }
        if(strcmp(root->name,"TYPE")==0){
            printf(" :%s",root->value);
        }
        if(strcmp(root->name,"INT")==0||strcmp(root->name,"FLOAT")==0){
            printf(" :%s",root->value);
        }
        printf(" (%d)\n",root->lineno);
    }
    if (root->children != NULL)
    {
        print_tree(root->children, depth + 1);
    }
    if (root->right_bro != NULL)
    {
        print_tree(root->right_bro, depth);
    }
}
void yyerror()
{
    printf("Error type B at line %d: syntax error\n",yylineno);
}
