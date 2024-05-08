#ifndef DEF_SEMANL
#define DEF_SEMANL

#include "tree.h"
#include "SymTable.h"

int SemError;
void sem_Program(struct Node *r);
void sem_ExtDefList(struct Node *r);
void sem_ExtDef(struct Node *r);
void sem_ExtDecList(struct Node *r,Type t);
Type sem_Specifier(struct Node *r);
Type sem_StructSpecifier(struct Node*r);
FieldList sem_VarDec(struct Node*r,Type t);
FieldList sem_FunDec(struct Node*r,Type t);
void sem_VarList(struct Node*r);
void sem_ParamDec(struct Node*r);
void sem_CompSt(struct Node*r,Type t,FieldList pre);
void sem_StmtList(struct Node*r,Type func_return);
void sem_Stmt(struct Node*r,Type func_return);
void sem_DefList(struct Node*r,int struct_or_not);
void sem_Def(struct Node*r,int struct_or_not);
void sem_DecList(struct Node*r,Type t,int struct_or_not);
void sem_Dec(struct Node*r,Type t,int struct_or_not);
Type sem_Exp(struct Node*r);
int sem_Args(struct Node*r,FieldList parameter);

#endif