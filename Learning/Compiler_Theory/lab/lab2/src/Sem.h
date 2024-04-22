#ifndef _SEM_H_
#define _SEM_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"table.h"
#include"MFT.h"

//错误定义
typedef struct error_* error;
struct error_
{
    int error_type;
    int lineno;
    error tail;
};

error error_head=NULL;

int Analyze_Program(struct node* root);
int Analyze_ExtDefList(struct node* root);
int Analyze_ExtDef(struct node* root);
int Analyze_ExtDecList(struct node* root);

int Analyze_Specifier(struct node* root);
int Analyze_P_Specifier(struct node* root);
int Analyze_StructSpecifier(struct node* root);
int Analyze_P_StructSpecifier(struct node* root);
char* Analyze_OptTag(struct node* root);
char* Analyze_Tag(struct node* root);

symbol Analyze_VarDec(struct node* root);
symbol Analyze_P_VarDec(struct node* root);
int Analyze_FunDec(struct node* root);
int Analyze_VarList(struct node* root);
int Analyze_ParamDec(struct node* root);

int Analyze_CompSt(struct node* root);
int Analyze_StmtList(struct node* root);
int Analyze_Stmt(struct node* root);

symbol Analyze_DefList(struct node* root);
symbol Analyze_Def(struct node* root);
symbol Analyze_DecList(struct node* root);
symbol Analyze_Dec(struct node* root);

int Analyze_Exp(struct node* root);
int Analyze_Args(struct node* root);

void add_error(int error_type,int lineno);
void print_error(error head);
int type2array_code(Type t);
FieldList prase_struct_help_func(struct node*root);
int prase_struct(struct node* root);

#endif