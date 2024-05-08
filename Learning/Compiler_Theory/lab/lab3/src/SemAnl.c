#include <stdio.h>
#include "SemAnl.h"
#include "SymTable.h"
extern int stack_top;

void add_read_write(){
    FieldList new_func=(FieldList)malloc(sizeof(struct FieldList_));
    new_func->var_num=-1;
    new_func->addr_or_not=0;
    strcpy(new_func->name,"read");
    new_func->tail=NULL;
    Type func_type=(Type)malloc(sizeof(struct Type_));
    func_type->can_be_left=0;
    new_func->type=func_type;
    func_type->kind=FUNCTION;
    func_type->line=-1;
    Type int_type=(Type)malloc(sizeof(struct Type_));
    int_type->can_be_left=0;
    int_type->kind=BASIC;
    int_type->line=-1;
    int_type->u.basic=0;
    func_type->u.func.return_type=int_type;
    func_type->u.func.defined=1;
    func_type->u.func.parameter=NULL;
    insert_fieldlist(new_func);
    FieldList my_write=(FieldList)malloc(sizeof(struct FieldList_));
    my_write->var_num=-1;
    my_write->addr_or_not=0;
    strcpy(my_write->name,"write");
    my_write->tail=NULL;
    func_type=(Type)malloc(sizeof(struct Type_));
    func_type->can_be_left=0;
    my_write->type=func_type;
    func_type->kind=FUNCTION;
    func_type->line=-1;
    int_type=CopyType(int_type);
    func_type->u.func.return_type=int_type;
    func_type->u.func.defined=1;
    func_type->u.func.parameter=NULL;
    FieldList write_para=(FieldList)malloc(sizeof(struct FieldList_));
    strcpy(write_para->name,"\0");
    write_para->tail=NULL;
    write_para->type=CopyType(int_type);
    write_para->var_num=-1;
    write_para->addr_or_not=0;
    my_write->type->u.func.parameter=write_para;
    insert_fieldlist(my_write);
}

void sem_Program(struct Node *r){
    stack_top=-1;
    new_symbol_table();
    add_read_write();
    sem_ExtDefList(r->first_child);
    FINAL_SYMBOL_TABLE=pop_symbol_table();
    FieldList p=FINAL_SYMBOL_TABLE;
    for(;p!=NULL;p=p->tail){
        if(p->type->kind==FUNCTION&&p->type->u.func.defined==0){
            SemError++;
            printf("Error type 18 at Line %d: 函数进行了声明，但没有被定义\n",p->type->line);
        }
    }
}

void sem_ExtDefList(struct Node *r){
    if(r!=NULL){
        sem_ExtDef(r->first_child);
        sem_ExtDefList(r->first_child->sibling);
    }
}

void sem_ExtDef(struct Node *r){
    struct Node*p=r->first_child;
    Type t=sem_Specifier(p);
    p=p->sibling;
    if(strcmp(p->Node_Type,"ExtDecList")==0){
        sem_ExtDecList(p,t);
    }
    else if(strcmp(p->Node_Type,"FunDec")==0){
        FieldList func=sem_FunDec(p,t);
        FieldList search=can_new_search(func->name,0);
        p=p->sibling;
        if(strcmp(p->Node_Type,"CompSt")==0){
            func->type->u.func.defined=1;
            if(search!=NULL&&search->type->u.func.defined==1){
                SemError++;
                printf("Error type 4 at Line %d: 函数\"%s\"出现重复定义(即同样的函数名出现了不止一次定义)\n",r->line,func->name);
            }
            else if(search!=NULL&&search->type->u.func.defined==0){
                search->type->u.func.defined=1;
                if(func_compare(search,func)!=0){
                    SemError++;
                    printf("Error type 19 at Line %d: 函数的多次声明互相冲突,或者声明与定义之间互相冲突\n",search->type->line);
                    search->type=func->type;
                }
            } 
            else insert_fieldlist(func);
            sem_CompSt(p,t,func);
        }
        else{
            if(search!=NULL){
                if(func_compare(search,func)!=0){
                    SemError++;
                    printf("Error type 19 at Line %d: 函数的多次声明互相冲突,或者声明与定义之间互相冲突\n",r->line);
                }
            }
            else insert_fieldlist(func);
        }
    }
}

FieldList sem_FunDec(struct Node*r,Type t){
    struct Node*child=r->first_child;
    FieldList new_func=(FieldList)malloc(sizeof(struct FieldList_));
    new_func->var_num=-1;
    new_func->addr_or_not=0;
    strcpy(new_func->name,child->content.my_char);
    new_func->tail=NULL;
    Type func_type=(Type)malloc(sizeof(struct Type_));
    func_type->can_be_left=0;
    new_func->type=func_type;
    func_type->kind=FUNCTION;
    func_type->line=r->line;
    func_type->u.func.return_type=t;
    func_type->u.func.defined=0;
    if(strcmp(child->sibling->sibling->Node_Type,"RP")!=0){
        new_symbol_table();
        sem_VarList(child->sibling->sibling);
        func_type->u.func.parameter=pop_symbol_table();
    }
    else func_type->u.func.parameter=NULL;
    return new_func;
}

void sem_ExtDecList(struct Node *r,Type t){
    struct Node*child=r->first_child;
    FieldList var=sem_VarDec(child,t);
    FieldList search=can_new_search(var->name,1);
    if(search==NULL)insert_fieldlist(var);
    else{
        SemError++;
        printf("Error type 3 at Line %d: 变量\"%s\"出现重复定义，或变量与前面定义过的结构体名字重复\n",child->line,var->name);
    }
    if(child->sibling!=NULL){
        child=child->sibling->sibling;
        sem_ExtDecList(child,t);
    }
}

Type sem_Specifier(struct Node *r){
    struct Node*p=r->first_child;
    if(strcmp(p->Node_Type,"TYPE")==0){
        Type t=(Type)malloc(sizeof(struct Type_));
        t->can_be_left=0;
        t->kind=BASIC;
        if(strcmp(p->content.my_char,"int")==0)t->u.basic=0;
        else t->u.basic=1;
        return t;
    }
    else return sem_StructSpecifier(p);
}

Type sem_StructSpecifier(struct Node*r){
    struct Node*p=r->first_child;
    p=p->sibling;
    if(strcmp(p->Node_Type,"OptTag")==0){
        struct Node*def_list=p->sibling->sibling;
        p=p->first_child;
        FieldList search=can_new_search(p->content.my_char,2);
        if(search!=NULL){
            SemError++;
            printf("Error type 16 at Line %d: 结构体的名字\"%s\"与前面定义过的结构体或变量的名字重复\n",p->line,p->content.my_char);
            return new_error_type();
        }
        FieldList new_struct=(FieldList)malloc(sizeof(struct FieldList_));
        strcpy(new_struct->name,p->content.my_char);
        new_struct->var_num=-1;
        new_struct->addr_or_not=0;
        Type t=(Type)malloc(sizeof(struct Type_));
        t->can_be_left=0;
        t->kind=STRUCTURE;
        new_symbol_table();
        sem_DefList(def_list,0);
        t->u.structure=pop_symbol_table();
        new_struct->type=t;
        insert_fieldlist(new_struct);
        return t;
    }
    else if(strcmp(p->Node_Type,"LC")==0){
        p=p->sibling;
        Type t=(Type)malloc(sizeof(struct Type_));
        t->can_be_left=0;
        t->kind=STRUCTURE;
        new_symbol_table();
        sem_DefList(p,0);
        t->u.structure=pop_symbol_table();
        return t;
    }
    else{
        FieldList search=can_use_search(p->first_child->content.my_char,2);
        if(search==NULL||search->type->kind!=STRUCTURE){
            SemError++;
            printf("Error type 17 at Line %d: 直接使用未定义过的结构体\"%s\"来定义变量\n",p->line,p->first_child->content.my_char);
            return new_error_type();
        }
        else return CopyType(search->type);
    }
}

FieldList sem_VarDec(struct Node*r,Type t){
    FieldList p=(FieldList)malloc(sizeof(struct FieldList_));
    p->var_num=-1;
    p->addr_or_not=0;
    struct Node*child=r->first_child;
    if(strcmp(child->Node_Type,"ID")==0){
        strcpy(p->name,child->content.my_char);
        p->type=CopyType(t);
        p->tail=NULL;
        return p;
    }
    else{
        Type cur_type=(Type)malloc(sizeof(struct Type_));
        cur_type->can_be_left=0;
        cur_type->kind=ARRAY;
        cur_type->u.array.elem=CopyType(t);
        cur_type->u.array.size=child->sibling->sibling->content.my_int;
        return sem_VarDec(child,cur_type);
    }
}

void sem_VarList(struct Node*r){
    struct Node*child=r->first_child;
    sem_ParamDec(child);
    if(child->sibling!=NULL){
        child=child->sibling->sibling;
        sem_VarList(child);
    }
}

void sem_ParamDec(struct Node*r){
    Type t=sem_Specifier(r->first_child);
    FieldList res=sem_VarDec(r->first_child->sibling,t);
    FieldList search=can_new_search(res->name,1);
    if(search==NULL)insert_fieldlist(res);
    else{
        SemError++;
        printf("Error type 3 at Line %d: 变量\"%s\"出现重复定义，或变量与前面定义过的结构体名字重复\n",r->first_child->sibling->line,res->name);
        res->type=CopyType(search->type);
        insert_fieldlist(res);
    }
}

void sem_CompSt(struct Node*r,Type t,FieldList pre){
    new_symbol_table();
    if(pre!=NULL){
        //pre is function define
        for(FieldList p=pre->type->u.func.parameter;p!=NULL;p=p->tail)
            insert_fieldlist(CopyFieldList(p));
    }
    struct Node*p=r->first_child->sibling;
    if(strcmp(p->Node_Type,"DefList")==0){
        sem_DefList(p,1);
        p=p->sibling;
    }
    if(strcmp(p->Node_Type,"StmtList")==0){
        //t is the type of return value
        sem_StmtList(p,t);
    }
    r->compst_symbol_table=pop_symbol_table();
}

void sem_StmtList(struct Node*r,Type func_return){
    if(r!=NULL){
        sem_Stmt(r->first_child,func_return);
        sem_StmtList(r->first_child->sibling,func_return);
    }
}

void sem_Stmt(struct Node*r,Type func_return){
    struct Node*child=r->first_child;
    if(strcmp(child->Node_Type,"Exp")==0)sem_Exp(child);
    else if(strcmp(child->Node_Type,"CompSt")==0)sem_CompSt(child,func_return,NULL);
    else if(strcmp(child->Node_Type,"RETURN")==0){
        Type exp_return=sem_Exp(child->sibling);
        if(type_compare(exp_return,func_return)==1){
            SemError++;
            printf("Error type 8 at Line %d: return语句的返回类型与函数定义的返回类型不匹配\n",child->line);
        }
    }
    else if(strcmp(child->Node_Type,"WHILE")==0){
        //WHILE LP EXP RP Stmt
        child=child->sibling->sibling;
        Type exp_return=sem_Exp(child);
        //if(exp_return->kind!=BASIC||exp_return->u.basic!=0)//error but don't care
        child=child->sibling->sibling;
        sem_Stmt(child,func_return);
    }
    else{
        child=child->sibling->sibling;
        Type exp_return=sem_Exp(child);
        //if(exp_return->kind!=BASIC||exp_return->u.basic!=0)//error but don't care
        child=child->sibling->sibling;
        sem_Stmt(child,func_return);
        if(child->sibling!=NULL){
            //IF LP Exp RP Stmt ELSE Stmt
            child=child->sibling->sibling;
            sem_Stmt(child,func_return);
        }
    }
}


void sem_DefList(struct Node*r,int struct_or_not){
    //0-struct,1-compst
    if(r!=NULL){
        sem_Def(r->first_child,struct_or_not);
        sem_DefList(r->first_child->sibling,struct_or_not);
    }
}

void sem_Def(struct Node*r,int struct_or_not){
    Type t=sem_Specifier(r->first_child);
    sem_DecList(r->first_child->sibling,t,struct_or_not);
}

void sem_DecList(struct Node*r,Type t,int struct_or_not){
    struct Node*child=r->first_child;
    sem_Dec(child,t,struct_or_not);
    if(child->sibling!=NULL)
        sem_DecList(child->sibling->sibling,t,struct_or_not);
}

void sem_Dec(struct Node*r,Type t,int struct_or_not){
    FieldList var=sem_VarDec(r->first_child,t);
    FieldList search=can_new_search(var->name,1);
    if(struct_or_not==0){
        if(search!=NULL||(search==NULL&&r->first_child->sibling!=NULL)){
            SemError++;
            printf("Error type 15 at Line %d: 结构体\"%s\"中域名重复定义(指同一结构体中)，或在定义时对域进行初始化\n",r->first_child->line,search->name);
        }
        else insert_fieldlist(var);
    }
    else{
        if(search!=NULL){
            SemError++;
            printf("Error type 3 at Line %d: 变量\"%s\"出现重复定义，或变量与前面定义过的结构体名字重复\n",r->first_child->line,search->name);
        }
        else if(r->first_child->sibling==NULL)insert_fieldlist(var);
        else{ //VarDec ASSIGNOP Exp
            Type exp_type=sem_Exp(r->first_child->sibling->sibling);
            if(type_compare(var->type,exp_type)==0)insert_fieldlist(var);
            else{
                SemError++;
                printf("Error type 5 at Line %d: 赋值号两边的表达式类型不匹配\n",r->first_child->sibling->line);
            }
        }
    }
}

Type sem_Exp(struct Node*r){
    struct Node*child=r->first_child;
    if(strcmp(child->Node_Type,"Exp")==0){
        Type exp_type=sem_Exp(child);
        child=child->sibling;
        if(strcmp(child->Node_Type,"ASSIGNOP")==0){
            Type another_exp_type=sem_Exp(child->sibling);
            if(type_compare(exp_type,another_exp_type)!=0){
                SemError++;
                printf("Error type 5 at Line %d: 赋值号两边的表达式类型不匹配\n",child->line);
                return new_error_type();
            }
            else if(exp_type->can_be_left==0){
                SemError++;
                printf("Error type 6 at Line %d: 赋值号左边出现一个只有右值的表达式\n",child->line);
                return new_error_type();
            }
            else return exp_type;
        }
        else if(strcmp(child->Node_Type,"AND")==0
            ||strcmp(child->Node_Type,"OR")==0){
            Type another_exp_type=sem_Exp(child->sibling);
            if(type_compare(exp_type,another_exp_type)!=0||exp_type->kind!=BASIC||exp_type->u.basic!=0){
                SemError++;
                printf("Error type 7 at Line %d: 操作数类型不匹配或操作数类型与操作符不匹配\n",child->line);
                return new_error_type();
            }
            else return exp_type;
        }
        else if(strcmp(child->Node_Type,"LB")==0){
            //Exp LB Exp RB
            Type num = sem_Exp(child->sibling);
            if(exp_type->kind!=ARRAY){
                SemError++;
                printf("Error type 10 at Line %d: 对非数组型变量使用“[…]”（数组访问）操作符\n",child->line);
                Type res=new_error_type();
                res->can_be_left=1;
                return res;
            }
            else if(num->kind!=BASIC||num->u.basic==1){
                SemError++;
                printf("Error type 12 at Line %d: 数组访问操作符“[…]”中出现非整数\n",child->line);
                Type res=new_error_type();
                res->can_be_left=1;
                return res;
            }
            else{
                Type res=exp_type->u.array.elem;
                res->can_be_left=1;
                return res;
            }
        }
        else if(strcmp(child->Node_Type,"DOT")==0){
            //Exp DOT ID
            if(exp_type->kind!=STRUCTURE){
                SemError++;
                printf("Error type 13 at Line %d: 对非结构体型变量使用“.”操作符\n",child->line);
                return new_error_type();
            }
            for(FieldList p=exp_type->u.structure;p!=NULL;p=p->tail)
                if(strcmp(child->sibling->content.my_char,p->name)==0){
                    Type res=CopyType(p->type);
                    res->can_be_left=1;
                    return res;
                }
            SemError++;
            printf("Error type 14 at Line %d: 访问结构体中未定义过的域\n",child->line);
            Type res=new_error_type();
            res->can_be_left=1;
            return res;
        }
        else if(strcmp(child->Node_Type,"RELOP")==0){
            Type another_exp_type=sem_Exp(child->sibling);
            if(type_compare(exp_type,another_exp_type)!=0
            ||(exp_type->kind!=BASIC&&exp_type->kind!=ERROR)
            ||(another_exp_type->kind!=BASIC&&another_exp_type->kind!=ERROR)){
                SemError++;
                printf("Error type 7 at Line %d: 操作数类型不匹配或操作数类型与操作符不匹配\n",child->line);
                return new_error_type();
            }
            Type res=(Type)malloc(sizeof(struct Type_));
            res->can_be_left=0;
            res->kind=BASIC;
            res->u.basic=0;
            return res;
        }
        else{
            Type another_exp_type=sem_Exp(child->sibling);
            if(type_compare(exp_type,another_exp_type)!=0
            ||(exp_type->kind!=BASIC&&exp_type->kind!=ERROR)
            ||(another_exp_type->kind!=BASIC&&another_exp_type->kind!=ERROR)){
                SemError++;
                printf("Error type 7 at Line %d: 操作数类型不匹配或操作数类型与操作符不匹配\n",child->line);
                return new_error_type();
            }
            else return exp_type;
        }
    }
    else if(strcmp(child->Node_Type,"LP")==0)return sem_Exp(child->sibling);
    else if(strcmp(child->Node_Type,"MINUS")==0){
        Type exp_type=sem_Exp(child->sibling);
        if(exp_type->kind!=BASIC){
            SemError++;
            printf("Error type 7 at Line %d: 操作数类型不匹配或操作数类型与操作符不匹配\n",child->line);
            return new_error_type();
        }
        else return exp_type;
    }
    else if(strcmp(child->Node_Type,"NOT")==0){
        Type exp_type=sem_Exp(child->sibling);
        if(exp_type->kind!=BASIC||exp_type->u.basic!=0){
            SemError++;
            printf("Error type 7 at Line %d: 操作数类型不匹配或操作数类型与操作符不匹配\n",child->line);
            return new_error_type();
        }
        else return exp_type;
    }
    else if(strcmp(child->Node_Type,"INT")==0){
        Type res=(Type)malloc(sizeof(struct Type_));
        res->can_be_left=0;
        res->kind=BASIC;
        res->u.basic=0;
        return res;
    }
    else if(strcmp(child->Node_Type,"FLOAT")==0){
        Type res=(Type)malloc(sizeof(struct Type_));
        res->can_be_left=0;
        res->kind=BASIC;
        res->u.basic=1;
        return res;
    }
    else{ //ID
        if(child->sibling!=NULL){
            //ID LP RP
            //ID LP Args RP
            FieldList search_func=can_use_search(child->content.my_char,0);
            FieldList search_other=can_use_search(child->content.my_char,1);
            if(search_func==NULL){
                if(search_other!=NULL){
                    SemError++;
                    printf("Error type 11 at Line %d: 对普通变量使用“(…)”或“()”（函数调用）操作符\n",child->line);
                    return new_error_type();
                }
                else{
                    SemError++;
                    printf("Error type 2 at Line %d: 函数在调用时未经定义\n",child->line);
                    return new_error_type();
                }
            }
            else{
                if(child->sibling->sibling->sibling==NULL)return search_func->type->u.func.return_type;
                else{
                    int args_legal=sem_Args(child->sibling->sibling,search_func->type->u.func.parameter);
                    if(args_legal==0)return search_func->type->u.func.return_type;
                    else{
                        SemError++;
                        printf("Error type 9 at Line %d: 函数调用时实参与形参的数目或类型不匹配\n",r->line);
                        return new_error_type();
                    }
                }
            }
        }
        else{
            //ID
            FieldList search_func=can_use_search(child->content.my_char,0);
            FieldList search_var=can_use_search(child->content.my_char,1);
            //FieldList search_func=NULL;
            //FieldList search_var=NULL;
            if(search_var!=NULL){
                Type res=CopyType(search_var->type);
                res->can_be_left=1;
                return res;
            }
            else if(search_func!=NULL){
                Type res=CopyType(search_func->type);
                res->can_be_left=1;
                return res;
            }
            else{
                SemError++;
                printf("Error type 1 at Line %d: 变量在使用时未经定义\n",child->line);
                Type res=new_error_type();
                res->can_be_left=1;
                return res;
            }
        }

    }
}

int sem_Args(struct Node*r,FieldList parameter){
    //0-legal,1-illegal
    if(parameter==NULL)return 1;
    struct Node*child=r->first_child;
    Type exp_type=sem_Exp(child);
    if(type_compare(exp_type,parameter->type)!=0)return 1;
    if(child->sibling!=NULL){
        child=child->sibling->sibling;
        return sem_Args(child,parameter->tail);
    }
    else if(parameter->tail!=NULL)return 1;
    else return 0;
}

