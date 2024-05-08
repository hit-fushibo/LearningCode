#include "InterTranslate.h"
#include <stdio.h>
#include <assert.h>
InterCodes inter_code_head;
InterCodes inter_code_tail;
int v_count,t_count,label_count;

void InsertCode(InterCode c){
    InterCodes p=(InterCodes)malloc(sizeof(struct InterCodes_));
    p->code=c;
    p->next=NULL;
    if(inter_code_head==NULL){
        inter_code_head=p;
        inter_code_tail=p;
        p->prev=NULL;
    }
    else{
        inter_code_tail->next=p;
        p->prev=inter_code_tail;
        inter_code_tail=p;
    }
}
void print_operand(Operand op,FILE*fp){
    if(op->kind==VARIABLE_OP)fprintf(fp,"v%d",op->op_u.var_no);
    else if(op->kind==CONSTANT_OP)fprintf(fp,"#%d",op->op_u.value);
    else if(op->kind==FUNCTION_OP)fprintf(fp,"%s",op->op_u.name);
    else if(op->kind==TEMP_OP)fprintf(fp,"t%d",op->op_u.var_no);
    else if(op->kind==LABEL_OP)fprintf(fp,"label%d",op->op_u.var_no);
}

void print_IR(FILE*fp){
    for(InterCodes c=inter_code_head;c!=NULL;c=c->next){
        InterCode p=c->code;
        if(p->kind==LABEL_IR){//LABEL x :
            fprintf(fp,"LABEL label%d :\n",p->u.one.op->op_u.var_no);
        }
        else if(p->kind==FUNCTION_IR){//FUNCTION f :
            fprintf(fp,"FUNCTION %s :\n",p->u.one.op->op_u.name);
        }
        else if(p->kind==ASSIGN_IR){//op1 := op2
            print_operand(p->u.two.op1,fp);
            fprintf(fp," := ");
            print_operand(p->u.two.op2,fp);
            fprintf(fp,"\n");
        }
        else if(p->kind==ADD_IR){//res := op1 + op2
            print_operand(p->u.three.res,fp);
            fprintf(fp," := ");
            print_operand(p->u.three.op1,fp);
            fprintf(fp," + ");
            print_operand(p->u.three.op2,fp);
            fprintf(fp,"\n");
        }
        else if(p->kind==SUB_IR){//x := y - z
            print_operand(p->u.three.res,fp);
            fprintf(fp," := ");
            print_operand(p->u.three.op1,fp);
            fprintf(fp," - ");
            print_operand(p->u.three.op2,fp);
            fprintf(fp,"\n");
        }
        else if(p->kind==MUL_IR){//x := y * z
            print_operand(p->u.three.res,fp);
            fprintf(fp," := ");
            print_operand(p->u.three.op1,fp);
            fprintf(fp," * ");
            print_operand(p->u.three.op2,fp);
            fprintf(fp,"\n");
        }
        else if(p->kind==DIV_IR){//x := y / z
            print_operand(p->u.three.res,fp);
            fprintf(fp," := ");
            print_operand(p->u.three.op1,fp);
            fprintf(fp," / ");
            print_operand(p->u.three.op2,fp);
            fprintf(fp,"\n");
        }
        else if(p->kind==GETADDR_IR){//x := &y
            print_operand(p->u.two.op1,fp);
            fprintf(fp," := &");
            print_operand(p->u.two.op2,fp);
            fprintf(fp,"\n");
        }
        else if(p->kind==GETVALUE_IR){//x := *y
            print_operand(p->u.two.op1,fp);
            fprintf(fp," := *");
            print_operand(p->u.two.op2,fp);
            fprintf(fp,"\n");
        }
        else if(p->kind==PUTADDR_IR){//*x := y
            fprintf(fp,"*");
            print_operand(p->u.two.op1,fp);
            fprintf(fp," := ");
            print_operand(p->u.two.op2,fp);
            fprintf(fp,"\n");
        }
        else if(p->kind==GOTO_IR){//GOTO x
            fprintf(fp,"GOTO ");
            print_operand(p->u.one.op,fp);
            fprintf(fp,"\n");
        }
        else if(p->kind==IFGOTO_IR){//IF op1 [relop] op2 GOTO op3
            fprintf(fp,"IF ");
            print_operand(p->u.four.op1,fp);
            fprintf(fp," %s ",p->u.four.relop);
            print_operand(p->u.four.op2,fp);
            fprintf(fp," GOTO ");
            print_operand(p->u.four.op3,fp);
            fprintf(fp,"\n");
        }
        else if(p->kind==RETURN_IR){//RETURN x
            fprintf(fp,"RETURN ");
            print_operand(p->u.one.op,fp);
            fprintf(fp,"\n");
        }
        else if(p->kind==DEC_IR){//DEC x [size]
            fprintf(fp,"DEC ");
            print_operand(p->u.dec.x,fp);
            fprintf(fp," %d\n",p->u.dec.size);
        }
        else if(p->kind==ARG_IR){//ARG x
            fprintf(fp,"ARG ");
            print_operand(p->u.one.op,fp);
            fprintf(fp,"\n");
        }
        else if(p->kind==CALL_IR){//op1 := CALL op2,if(op1==NULL)call op2
            print_operand(p->u.two.op1,fp);
                fprintf(fp," := ");
            fprintf(fp,"CALL ");
            print_operand(p->u.two.op2,fp);
            fprintf(fp,"\n");
        }
        else if(p->kind==PARAM_IR){//PARAM x
            fprintf(fp,"PARAM ");
            print_operand(p->u.one.op,fp);
            fprintf(fp,"\n");
        }
        else if(p->kind==READ_IR){//READ x
            fprintf(fp,"READ ");
            print_operand(p->u.one.op,fp);
            fprintf(fp,"\n");
        }
        else if(p->kind==WRITE_IR){//WRITE x
            fprintf(fp,"WRITE ");
            print_operand(p->u.one.op,fp);
            fprintf(fp,"\n");
        }
    }
}

Operand new_temp(){
    Operand res=(Operand)malloc(sizeof(struct Operand_));
    res->kind=TEMP_OP;
    ++t_count;
    res->op_u.var_no=t_count;
    return res;
}

Operand new_label(){
    Operand res=(Operand)malloc(sizeof(struct Operand_));
    res->kind=LABEL_OP;
    ++label_count;
    res->op_u.var_no=label_count;
    return res;
}

int get_var_num(char*name){
    FieldList search=can_use_search(name,1);
    if(search==NULL){printf("var %s not defined in symbol table!!!\n",name);assert(0);}
    if(search->var_num>=0)return search->var_num;
    else{
        ++v_count;
        search->var_num=v_count;
        return v_count;
    }
}

int Addr_or_not(char*name){
    //1 is a addr
    FieldList search=can_use_search(name,1);
    if(search==NULL||search->addr_or_not!=1)return 0;
    else return 1;
}

int get_var_addr_num(char*name){
    FieldList search=can_use_search(name,1);
    if(search==NULL){printf("var %s not defined in symbol table!!!\n",name);assert(0);}
    if(search->var_num>=0)return search->var_num;
    else{
        ++v_count;
        search->var_num=v_count;
        search->addr_or_not=1;
        return v_count;
    }
}

Operand get_func_op(FieldList func){
    Operand res=(Operand)malloc(sizeof(struct Operand_));
    res->kind=FUNCTION_OP;
    strcpy(res->op_u.name,func->name);
    return res;
}

Operand new_constant(int x){
    Operand res=(Operand)malloc(sizeof(struct Operand_));
    res->kind=CONSTANT_OP;
    res->op_u.value=x;
    return res;
}

Operand copy_operand(Operand x){
    Operand y=(Operand)malloc(sizeof(struct Operand_));
    y->kind=x->kind;
    y->op_u=x->op_u;
    return y;
}

int get_size(Type t){
    if(t==NULL)return 0;
    if(t->kind==BASIC)return 4;
    else if(t->kind==ARRAY)return t->u.array.size*get_size(t->u.array.elem);
    else if(t->kind==STRUCTURE){
        int res=0;
        for(FieldList p=t->u.structure;p!=NULL;p=p->tail)res+=get_size(p->type);
        return res;
    }
    else return 0;
}



void translate_start(struct Node*r,FILE*fp){
    inter_code_head=NULL;
    inter_code_tail=NULL;
    v_count=0;t_count=0;label_count=0;
    stack_top=0;
    SYMBOL_TALBE_STACK[stack_top]=FINAL_SYMBOL_TABLE;
    translate_Program(r);
    print_IR(fp);
}

void translate_Program(struct Node *r){
    translate_ExtDefList(r->first_child);
}

void translate_ExtDefList(struct Node *r){
    if(r!=NULL){
        translate_ExtDef(r->first_child);
        translate_ExtDefList(r->first_child->sibling);
    }
}

void translate_ExtDef(struct Node *r){
    struct Node*p=r->first_child;
    p=p->sibling;
    if(strcmp(p->Node_Type,"FunDec")==0){
        if(strcmp(p->sibling->Node_Type,"CompSt")==0){
            stack_top++;
            SYMBOL_TALBE_STACK[stack_top]=p->sibling->compst_symbol_table;
        }
        translate_FunDec(p);
        p=p->sibling;
        if(strcmp(p->Node_Type,"CompSt")==0){
            translate_CompSt(p);
        }
    }
}

void translate_FunDec(struct Node*r){
    struct Node*child=r->first_child;
    InterCode new_code=(InterCode)malloc(sizeof(struct InterCode_));
    new_code->kind=FUNCTION_IR;
    new_code->u.one.op=(Operand)malloc(sizeof(struct Operand_));
    new_code->u.one.op->kind=FUNCTION_OP;
    strcpy(new_code->u.one.op->op_u.name,child->content.my_char);
    InsertCode(new_code);
    if(strcmp(child->sibling->sibling->Node_Type,"RP")!=0){
        //ID LP VarList RP
        translate_VarList(child->sibling->sibling);
    }
}

void translate_VarDec(struct Node*r){//only used in dec
    struct Node*child=r->first_child;
    if(strcmp(child->Node_Type,"ID")==0){
        FieldList search=can_use_search(child->content.my_char,1);
        if(search->type->kind==STRUCTURE||search->type->kind==ARRAY){
            InterCode code=(InterCode)malloc(sizeof(struct InterCode_));
            Operand op=(Operand)malloc(sizeof(struct Operand_));
            op->kind=VARIABLE_OP;
            op->op_u.var_no=get_var_num(child->content.my_char);
            code->kind=DEC_IR;
            code->u.dec.size=get_size(search->type);
            code->u.dec.x=op;
            InsertCode(code);
        }
    }
    else{
        translate_VarDec(child);
    }
}

void translate_VarList(struct Node*r){
    struct Node*child=r->first_child;
    translate_ParamDec(child);
    if(child->sibling!=NULL){
        child=child->sibling->sibling;
        translate_VarList(child);
    }
}

void translate_ParamDec(struct Node*r){
    struct Node*var_dec=r->first_child->sibling;
    if(strcmp(var_dec->first_child->Node_Type,"ID")==0){
        InterCode code=(InterCode)malloc(sizeof(struct InterCode_));
        Operand op=(Operand)malloc(sizeof(struct Operand_));
        op->kind=VARIABLE_OP;
        FieldList search=can_use_search(var_dec->first_child->content.my_char,1);
        if(search->type->kind==STRUCTURE)
            op->op_u.var_no=get_var_addr_num(var_dec->first_child->content.my_char);
        else
            op->op_u.var_no=get_var_num(var_dec->first_child->content.my_char);
        code->kind=PARAM_IR;
        code->u.one.op=op;
        InsertCode(code);
    }
    else{//VarDec [INT]
        struct Node*child=var_dec->first_child;
        while(strcmp(child->Node_Type,"ID")!=0)child=child->first_child;
        InterCode code=(InterCode)malloc(sizeof(struct InterCode_));
        Operand op=(Operand)malloc(sizeof(struct Operand_));
        op->kind=VARIABLE_OP;
        op->op_u.var_no=get_var_addr_num(child->content.my_char);
        code->kind=PARAM_IR;
        code->u.one.op=op;
        InsertCode(code);
    }
}

void translate_CompSt(struct Node*r){
    struct Node*p=r->first_child->sibling;
    if(strcmp(p->Node_Type,"DefList")==0){
        translate_DefList(p);
        p=p->sibling;
    }
    if(strcmp(p->Node_Type,"StmtList")==0){
        translate_StmtList(p);
    }
    stack_top--;
}

void translate_StmtList(struct Node*r){
    if(r!=NULL){
        translate_Stmt(r->first_child);
        translate_StmtList(r->first_child->sibling);
    }
}

void translate_Stmt(struct Node*r){
    struct Node*child=r->first_child;
    if(strcmp(child->Node_Type,"Exp")==0){
        translate_Exp(child,NULL);
    }
    else if(strcmp(child->Node_Type,"CompSt")==0){
        stack_top++;
        SYMBOL_TALBE_STACK[stack_top]=child->compst_symbol_table;
        translate_CompSt(child);
    }
    else if(strcmp(child->Node_Type,"RETURN")==0){
        Operand t1=new_temp();
        translate_Exp(child->sibling,t1);//code1
        InterCode code2=(InterCode)malloc(sizeof(struct InterCode_));
        code2->kind=RETURN_IR;
        code2->u.one.op=t1;
        InsertCode(code2);
    }
    else if(strcmp(child->Node_Type,"WHILE")==0){
        //WHILE LP EXP RP Stmt
        Operand label1=new_label();
        Operand label2=new_label();
        Operand label3=new_label();
        //[LABEL label1]
        InterCode l1=(InterCode)malloc(sizeof(struct InterCode_));
        l1->kind=LABEL_IR;
        l1->u.one.op=label1;
        InsertCode(l1);
        //code1
        child=child->sibling->sibling;
        translate_Cond(child,label2,label3);
        //[LABEL label2]
        InterCode l2=(InterCode)malloc(sizeof(struct InterCode_));
        l2->kind=LABEL_IR;
        l2->u.one.op=label2;
        InsertCode(l2);
        //code2
        child=child->sibling->sibling;
        translate_Stmt(child); 
        //[GOTO label1]
        InterCode goto_l1=(InterCode)malloc(sizeof(struct InterCode_));
        goto_l1->kind=GOTO_IR;
        goto_l1->u.one.op=copy_operand(label1);
        InsertCode(goto_l1);
        //[LABEL label3]
        InterCode l3=(InterCode)malloc(sizeof(struct InterCode_));
        l3->kind=LABEL_IR;
        l3->u.one.op=label3;
        InsertCode(l3);
    }
    else{//IF LP Exp RP
        Operand label1=new_label();
        Operand label2=new_label();
        //code1
        child=child->sibling->sibling;
        translate_Cond(child,label1,label2);
        //[LABEL label1]
        InterCode l1=(InterCode)malloc(sizeof(struct InterCode_));
        l1->kind=LABEL_IR;
        l1->u.one.op=label1;
        InsertCode(l1);
        //code2
        child=child->sibling->sibling;
        translate_Stmt(child);
        if(child->sibling!=NULL){
            //IF LP Exp RP Stmt ELSE Stmt
            Operand label3=new_label();
            //[GOTO label3]
            InterCode goto_l3=(InterCode)malloc(sizeof(struct InterCode_));
            goto_l3->kind=GOTO_IR;
            goto_l3->u.one.op=copy_operand(label3);
            InsertCode(goto_l3);
            //[LABEL label2]
            InterCode l2=(InterCode)malloc(sizeof(struct InterCode_));
            l2->kind=LABEL_IR;
            l2->u.one.op=label2;
            InsertCode(l2);
            //code3
            child=child->sibling->sibling;
            translate_Stmt(child);
            //[LABEL label3]
            InterCode l3=(InterCode)malloc(sizeof(struct InterCode_));
            l3->kind=LABEL_IR;
            l3->u.one.op=label3;
            InsertCode(l3);
        }
        else{
            //[LABEL label2]
            InterCode l2=(InterCode)malloc(sizeof(struct InterCode_));
            l2->kind=LABEL_IR;
            l2->u.one.op=label2;
            InsertCode(l2);
        }
    }
}

void translate_DefList(struct Node*r){
    //0-struct,1-compst
    if(r!=NULL){
        translate_Def(r->first_child);
        translate_DefList(r->first_child->sibling);
    }
}

void translate_Def(struct Node*r){
    translate_DecList(r->first_child->sibling);
}

void translate_DecList(struct Node*r){
    struct Node*child=r->first_child;
    translate_Dec(child);
    if(child->sibling!=NULL)
        translate_DecList(child->sibling->sibling);
}

void translate_Dec(struct Node*r){
    struct Node*var_dec=r->first_child;
    struct Node*exp=NULL;
    if(r->first_child->sibling!=NULL)exp=r->first_child->sibling->sibling;
    if(exp==NULL)//VarDec
        translate_VarDec(var_dec);
    else{//VarDec ASSIGNOP Exp
        Operand t1=new_temp();
        translate_Exp(exp,t1);
        InterCode code=(InterCode)malloc(sizeof(struct InterCode_));
        Operand var_op=(Operand)malloc(sizeof(struct Operand_));
        var_op->kind=VARIABLE_OP;
        var_op->op_u.var_no=get_var_num(var_dec->first_child->content.my_char);
        code->kind=ASSIGN_IR;
        code->u.two.op1=var_op;
        code->u.two.op2=t1;
        InsertCode(code);
    }
}

Operand translate_left_Exp(struct Node*r){
    if(strcmp(r->first_child->Node_Type,"ID")==0){
        Operand res=(Operand)malloc(sizeof(struct Operand_));
        res->kind=VARIABLE_OP;
        res->op_u.var_no=get_var_num(r->first_child->content.my_char);
        return res;
    }
    else {
        Operand addr=new_temp();
        get_addr(r,addr);
        return addr;
    }
    return NULL;
}

void translate_Cond(struct Node*r, Operand label_true, Operand label_false){
    struct Node*child=r->first_child;
    if(strcmp(child->Node_Type,"Exp")==0){
        if(strcmp(child->sibling->Node_Type,"AND")==0){
            Operand label1=new_label();
            translate_Cond(child,label1,label_false);//code1
            //[LABEL label1]
            InterCode l1=(InterCode)malloc(sizeof(struct InterCode_));
            l1->kind=LABEL_IR;
            l1->u.one.op=label1;
            InsertCode(l1);
            child=child->sibling;
            translate_Cond(child->sibling,label_true,label_false);//code2
        }
        else if(strcmp(child->sibling->Node_Type,"OR")==0){
            Operand label1=new_label();
            translate_Cond(child,label_true,label1);//code1
            //[LABEL label1]
            InterCode l1=(InterCode)malloc(sizeof(struct InterCode_));
            l1->kind=LABEL_IR;
            l1->u.one.op=label1;
            InsertCode(l1);
            child=child->sibling;
            translate_Cond(child->sibling,label_true,label_false);//code2
        }
        else if(strcmp(child->sibling->Node_Type,"RELOP")==0){
            Operand t1=new_temp();
            Operand t2=new_temp();
            translate_Exp(child,t1);//code1
            child=child->sibling;
            translate_Exp(child->sibling,t2);//code2
            //code3:[IF t1 op t2 GOTO label_true]
            InterCode c2=(InterCode)malloc(sizeof(struct InterCode_));
            c2->kind=IFGOTO_IR;
            c2->u.four.op1=copy_operand(t1);
            c2->u.four.op2=copy_operand(t2);
            c2->u.four.op3=copy_operand(label_true);
            strcpy(c2->u.four.relop,child->content.my_char);
            InsertCode(c2);
            //[GOTO label_false]
            InterCode c3=(InterCode)malloc(sizeof(struct InterCode_));
            c3->kind=GOTO_IR;
            c3->u.one.op=copy_operand(label_false);
            InsertCode(c3);
        }
        else{
            Operand t1=new_temp();
            translate_Exp(r,t1);//code1
            //code2:[IF t1 != #0 GOTO label_true]
            InterCode c2=(InterCode)malloc(sizeof(struct InterCode_));
            c2->kind=IFGOTO_IR;
            c2->u.four.op1=copy_operand(t1);
            Operand t2=new_constant(0);
            c2->u.four.op2=copy_operand(t2);
            c2->u.four.op3=copy_operand(label_true);
            strcpy(c2->u.four.relop,"!=");
            InsertCode(c2);
            //[GOTO label_false]
            InterCode c3=(InterCode)malloc(sizeof(struct InterCode_));
            c3->kind=GOTO_IR;
            c3->u.one.op=copy_operand(label_false);
            InsertCode(c3);
        }
    }
    else if(strcmp(child->Node_Type,"NOT")==0){
        translate_Cond(child->sibling,label_false,label_true);
    }
    else{
            Operand t1=new_temp();
            translate_Exp(r,t1);//code1
            //code2:[IF t1 != #0 GOTO label_true]
            InterCode c2=(InterCode)malloc(sizeof(struct InterCode_));
            c2->kind=IFGOTO_IR;
            c2->u.four.op1=copy_operand(t1);
            Operand t2=new_constant(0);
            c2->u.four.op2=copy_operand(t2);
            c2->u.four.op3=copy_operand(label_true);
            strcpy(c2->u.four.relop,"!=");
            InsertCode(c2);
            //[GOTO label_false]
            InterCode c3=(InterCode)malloc(sizeof(struct InterCode_));
            c3->kind=GOTO_IR;
            c3->u.one.op=copy_operand(label_false);
            InsertCode(c3);
        }
}

void get_addr(struct Node*r,Operand place){
    if(strcmp(r->first_child->Node_Type,"ID")==0){
        InterCode c1=(InterCode)malloc(sizeof(struct InterCode_));
        if(Addr_or_not(r->first_child->content.my_char)!=1)
            c1->kind=GETADDR_IR;
        else c1->kind=ASSIGN_IR;
        c1->u.two.op1=copy_operand(place);
        Operand v2=(Operand)malloc(sizeof(struct Operand_));
        v2->kind=VARIABLE_OP;
        v2->op_u.var_no=get_var_num(r->first_child->content.my_char);
        c1->u.two.op2=v2;
        InsertCode(c1);
    }
    else if(strcmp(r->first_child->Node_Type,"Exp")==0){
        if(strcmp(r->first_child->sibling->Node_Type,"LB")==0)get_addr_array(r,place);
        else if(strcmp(r->first_child->sibling->Node_Type,"DOT")==0)get_addr_structure(r,place);
    }
}

Type get_type(struct Node*r){
    struct Node*child=r->first_child;
    if(strcmp(child->Node_Type,"Exp")==0){
        Type exp_type=sem_Exp(child);
        child=child->sibling;
        if(strcmp(child->Node_Type,"LB")==0){
            //Exp LB Exp RB
            Type num = sem_Exp(child->sibling);
            Type res=exp_type->u.array.elem;
            res->can_be_left=1;
            return res;
        }
        else if(strcmp(child->Node_Type,"DOT")==0){
            //Exp DOT ID
            for(FieldList p=exp_type->u.structure;p!=NULL;p=p->tail)
                if(strcmp(child->sibling->content.my_char,p->name)==0){
                    Type res=CopyType(p->type);
                    res->can_be_left=1;
                    return res;
                }
        }
        else return NULL;
    }
    else if(strcmp(child->Node_Type,"LP")==0)return sem_Exp(child->sibling);
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
            return CopyType(search_func->type->u.func.return_type);
        }
        else{
            //ID
            FieldList search_func=can_use_search(child->content.my_char,0);
            FieldList search_var=can_use_search(child->content.my_char,1);
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
            else return NULL;
        }
    }
}

void get_addr_array(struct Node*r,Operand place){
    //r->exp1 [exp2]
    struct Node*pre=r;
    struct Node*exp1=r->first_child;
    struct Node*exp2=r->first_child->sibling->sibling;
    IR_NodeList head=(IR_NodeList)malloc(sizeof(struct IR_NodeList_));
    head->next=NULL;
    head->node=NULL;
    while(strcmp(exp1->Node_Type,"Exp")==0&&strcmp(exp1->sibling->Node_Type,"LB")==0){
        //to be write,if a.op[1]
        exp2=exp1->sibling->sibling;
        IR_NodeList p=(IR_NodeList)malloc(sizeof(struct IR_NodeList_));
        p->node=exp2;
        p->next=head->next;
        head->next=p;
        pre=exp1;
        exp1=exp1->first_child;
    }
    //place:=&exp1
    Operand t=new_temp();
    get_addr(pre,place);
    Type type=get_type(pre);
    //FieldList search=can_use_search(exp1->content.my_char,1);
    //Type type=search->type;
    type=type->u.array.elem;
    for(IR_NodeList pp=head->next;pp!=NULL;pp=pp->next){
        translate_Exp(pp->node,t);
        //t:=t*size
        InterCode c3=(InterCode)malloc(sizeof(struct InterCode_));
        c3->kind=MUL_IR;
        c3->u.three.res=copy_operand(t);
        c3->u.three.op1=copy_operand(t);
        c3->u.three.op2=new_constant(get_size(type));
        InsertCode(c3);
        //place=place+t
        c3=(InterCode)malloc(sizeof(struct InterCode_));
        c3->kind=ADD_IR;
        c3->u.three.res=copy_operand(place);
        c3->u.three.op1=copy_operand(t);
        c3->u.three.op2=copy_operand(place);
        InsertCode(c3);
        type=type->u.array.elem;
    }
}

void get_addr_structure(struct Node*r,Operand place){
    //exp DOT ID
    struct Node*pre=r;
    struct Node*exp1=r->first_child;
    struct Node*exp2=r->first_child->sibling->sibling;
    IR_NodeList head=(IR_NodeList)malloc(sizeof(struct IR_NodeList_));
    head->next=NULL;
    head->node=NULL;
    while(strcmp(exp1->Node_Type,"Exp")==0&&strcmp(exp1->sibling->Node_Type,"DOT")==0){
        exp2=exp1->sibling->sibling;
        IR_NodeList p=(IR_NodeList)malloc(sizeof(struct IR_NodeList_));
        p->node=exp2;
        p->next=head->next;
        head->next=p;
        pre=exp1;
        exp1=exp1->first_child;
    }
    //place:=&exp1
    Operand t=new_temp();
    get_addr(pre,place);
    Type type=get_type(pre);
    FieldList cur_fieldlist_head=type->u.structure;
    //FieldList search=can_use_search(exp1->content.my_char,2);
    //FieldList cur_fieldlist_head=search->type->u.structure;
    for(IR_NodeList pp=head->next;pp!=NULL;pp=pp->next){
        //name=pp->node->content.my_char
        //place=place+t
        while(strcmp(cur_fieldlist_head->name,pp->node->content.my_char)!=0){
            InterCode c3=(InterCode)malloc(sizeof(struct InterCode_));
            c3->kind=ADD_IR;
            c3->u.three.res=copy_operand(place);
            c3->u.three.op1=new_constant(get_size(cur_fieldlist_head->type));
            c3->u.three.op2=copy_operand(place);
            InsertCode(c3);
            cur_fieldlist_head=cur_fieldlist_head->tail;
        }
        cur_fieldlist_head=cur_fieldlist_head->type->u.structure;
    }
}

void translate_Exp(struct Node*r, Operand place){
    if(place==NULL)place=new_temp();
    struct Node*child=r->first_child;
    if(strcmp(child->Node_Type,"Exp")==0){
        if(strcmp(child->sibling->Node_Type,"ASSIGNOP")==0){
            struct Node*exp_node1=child;
            struct Node*exp_node2=child->sibling->sibling;
            Operand variable=translate_left_Exp(exp_node1);
            Operand t1=new_temp();
            translate_Exp(exp_node2,t1);
            //[variable:=t1]
            InterCode c1=(InterCode)malloc(sizeof(struct InterCode_));
            if(variable->kind==VARIABLE_OP) c1->kind=ASSIGN_IR;
            else c1->kind=PUTADDR_IR;
            c1->u.two.op1=copy_operand(variable);
            c1->u.two.op2=t1;
            InsertCode(c1);
            //[place:=variable]
            InterCode c2=(InterCode)malloc(sizeof(struct InterCode_));
            c2->kind=ASSIGN_IR;
            c2->u.two.op1=copy_operand(place);
            c2->u.two.op2=copy_operand(variable);
            InsertCode(c2);
        }
        else if(strcmp(child->sibling->Node_Type,"LB")==0){
            //Exp LB Exp RB[]
            Operand addr=new_temp();
            get_addr_array(r,addr);
            InterCode c1=(InterCode)malloc(sizeof(struct InterCode_));
            if(get_type(r)->kind==BASIC)
                c1->kind=GETVALUE_IR;
            else c1->kind=ASSIGN_IR;
            c1->u.two.op1=copy_operand(place);
            c1->u.two.op2=addr;
            InsertCode(c1);
        }
        else if(strcmp(child->sibling->Node_Type,"DOT")==0){
            //Exp DOT ID
            Operand addr=new_temp();
            get_addr_structure(r,addr);
            InterCode c1=(InterCode)malloc(sizeof(struct InterCode_));
            if(get_type(r)->kind==BASIC)
                c1->kind=GETVALUE_IR;
            else c1->kind=ASSIGN_IR;
            c1->u.two.op1=copy_operand(place);
            c1->u.two.op2=addr;
            InsertCode(c1);
        }
        else if(strcmp(child->sibling->Node_Type,"AND")==0
            ||strcmp(child->sibling->Node_Type,"OR")==0
            ||strcmp(child->sibling->Node_Type,"RELOP")==0){
            Operand label1=new_label();
            Operand label2=new_label();
            //[place := #0]
            InterCode c1=(InterCode)malloc(sizeof(struct InterCode_));
            c1->kind=ASSIGN_IR;
            c1->u.two.op1=copy_operand(place);
            c1->u.two.op2=new_constant(0);
            InsertCode(c1);
            translate_Cond(r,label1,label2);
            //[LABEL label1]
            InterCode l1=(InterCode)malloc(sizeof(struct InterCode_));
            l1->kind=LABEL_IR;
            l1->u.one.op=label1;
            InsertCode(l1);
            //[place := #1]
            if(place!=NULL){
                InterCode c2=(InterCode)malloc(sizeof(struct InterCode_));
                c2->kind=ASSIGN_IR;
                c2->u.two.op1=copy_operand(place);
                c2->u.two.op2=new_constant(1);
                InsertCode(c2);
            }
            //[LABEL label2]
            InterCode l2=(InterCode)malloc(sizeof(struct InterCode_));
            l2->kind=LABEL_IR;
            l2->u.one.op=label2;
            InsertCode(l2);
        }
        else{//+-*/
            struct Node*exp_node1=child;
            struct Node*exp_node2=child->sibling->sibling;
            struct Node*exp_sym=child->sibling;
            Operand t1=new_temp();
            Operand t2=new_temp();
            translate_Exp(exp_node1,t1);
            translate_Exp(exp_node2,t2);
            //[place := t1 relop t2]
            if(place!=NULL){
                InterCode c3=(InterCode)malloc(sizeof(struct InterCode_));
                if(strcmp(exp_sym->Node_Type,"PLUS")==0)c3->kind=ADD_IR;
                else if(strcmp(exp_sym->Node_Type,"MINUS")==0)c3->kind=SUB_IR;
                else if(strcmp(exp_sym->Node_Type,"STAR")==0)c3->kind=MUL_IR;
                else if(strcmp(exp_sym->Node_Type,"DIV")==0)c3->kind=DIV_IR;
                else print_tree(r,0);
                c3->u.three.res=copy_operand(place);
                c3->u.three.op1=t1;
                c3->u.three.op2=t2;
                InsertCode(c3);
            }
        }
    }
    else if(strcmp(child->Node_Type,"LP")==0)translate_Exp(child->sibling,place);
    else if(strcmp(child->Node_Type,"MINUS")==0){
        struct Node*exp_node=child->sibling;
        Operand t1=new_temp();
        translate_Exp(exp_node,t1);
        //[place := #0 - t1]
        if(place!=NULL){
            InterCode c2=(InterCode)malloc(sizeof(struct InterCode_));
            c2->kind=SUB_IR;
            c2->u.three.res=copy_operand(place);
            c2->u.three.op1=new_constant(0);
            c2->u.three.op2=t1;
            InsertCode(c2);
        }
    }
    else if(strcmp(child->Node_Type,"NOT")==0){
        Operand label1=new_label();
        Operand label2=new_label();
        //[place := #0]
        if(place!=NULL){
            InterCode c1=(InterCode)malloc(sizeof(struct InterCode_));
            c1->kind=ASSIGN_IR;
            c1->u.two.op1=copy_operand(place);
            c1->u.two.op2=new_constant(0);
            InsertCode(c1);
        }
        translate_Cond(r,label1,label2);
        //[LABEL label1]
        InterCode l1=(InterCode)malloc(sizeof(struct InterCode_));
        l1->kind=LABEL_IR;
        l1->u.one.op=label1;
        InsertCode(l1);
        //[place := #1]
        if(place!=NULL){
            InterCode c2=(InterCode)malloc(sizeof(struct InterCode_));
            c2->kind=ASSIGN_IR;
            c2->u.two.op1=copy_operand(place);
            c2->u.two.op2=new_constant(1);
            InsertCode(c2);
        }
        //[LABEL label2]
        InterCode l2=(InterCode)malloc(sizeof(struct InterCode_));
        l2->kind=LABEL_IR;
        l2->u.one.op=label2;
        InsertCode(l2);
    }
    else if(strcmp(child->Node_Type,"INT")==0){
        // [place := #value]
        if(place!=NULL){
            InterCode c1=(InterCode)malloc(sizeof(struct InterCode_));
            c1->kind=ASSIGN_IR;
            c1->u.two.op1=copy_operand(place);
            c1->u.two.op2=new_constant(child->content.my_int);
            InsertCode(c1);
        }
    }
    else if(strcmp(child->Node_Type,"FLOAT")==0){
        // [place := #value]
        //to be change,because there is no float
        if(place!=NULL){
            InterCode c1=(InterCode)malloc(sizeof(struct InterCode_));
            c1->kind=ASSIGN_IR;
            c1->u.two.op1=copy_operand(place);
            c1->u.two.op2=new_constant(child->content.my_int);
            InsertCode(c1);
        }
    }
    else{ //ID
        if(child->sibling!=NULL){
            FieldList search_func=can_use_search(child->content.my_char,0);
            if(child->sibling->sibling->sibling==NULL){//ID LP RP
                if(strcmp(search_func->name,"read")==0){
                    // [READ place]
                    if(place!=NULL){
                        InterCode c1=(InterCode)malloc(sizeof(struct InterCode_));
                        c1->kind=READ_IR;
                        c1->u.one.op=copy_operand(place);
                        InsertCode(c1);
                    }
                }
                else{
                    // [place := CALL function.name]
                    InterCode c1=(InterCode)malloc(sizeof(struct InterCode_));
                    c1->kind=CALL_IR;
                    if(place!=NULL)c1->u.two.op1=copy_operand(place);
                    else {
                        Operand t_place=new_temp();
                        c1->u.two.op1=t_place;
                    }
                    c1->u.two.op2=get_func_op(search_func);
                    InsertCode(c1);
                }
            }
            else{//ID LP Args RP
                ArgList arg_list=(ArgList)malloc(sizeof(struct ArgList_));
                arg_list->next=NULL;
                translate_Args(child->sibling->sibling,arg_list);
                if(strcmp(search_func->name,"write")==0){
                    //[WRITE arg_list[1]]
                    InterCode c1=(InterCode)malloc(sizeof(struct InterCode_));
                    c1->kind=WRITE_IR;
                    if(arg_list->next==NULL){printf("error write func!\n");assert(0);}
                    c1->u.one.op=copy_operand(arg_list->next->arg);
                    InsertCode(c1);
                    //[place := #0]
                    if(place!=NULL){
                        InterCode c2=(InterCode)malloc(sizeof(struct InterCode_));
                        c2->kind=ASSIGN_IR;
                        c2->u.two.op1=copy_operand(place);
                        c2->u.two.op2=new_constant(0);
                        InsertCode(c2);
                    }
                }
                else{
                    //for i = 1 to length(arg_list) code2 = code2 + [ARG arg_list[i]]
                    for(ArgList p=arg_list->next;p!=NULL;p=p->next){
                        InterCode c1=(InterCode)malloc(sizeof(struct InterCode_));
                        c1->kind=ARG_IR;
                        c1->u.one.op=copy_operand(p->arg);
                        InsertCode(c1);
                    }
                    //[place := CALL function.name]
                    InterCode c2=(InterCode)malloc(sizeof(struct InterCode_));
                    c2->kind=CALL_IR;
                    if(place!=NULL)c2->u.two.op1=copy_operand(place);
                    else {
                        Operand t_place=new_temp();
                        c2->u.two.op1=t_place;
                    }
                    c2->u.two.op2=get_func_op(search_func);
                    InsertCode(c2);
                }
            }
        }
        else{
            //ID
            FieldList search_func=can_use_search(child->content.my_char,0);
            FieldList search_var=can_use_search(child->content.my_char,1);
            if(search_var!=NULL){
                //[place := variable.name]
                if(place!=NULL){
                    InterCode c1=(InterCode)malloc(sizeof(struct InterCode_));
                    if((search_var->type->kind==STRUCTURE||search_var->type->kind==ARRAY)&&search_var->addr_or_not!=1)
                        c1->kind=GETADDR_IR;
                    else c1->kind=ASSIGN_IR;
                    c1->u.two.op1=copy_operand(place);
                    int var_num=get_var_num(search_var->name);
                    Operand tmp=(Operand)malloc(sizeof(struct Operand_));
                    tmp->kind=VARIABLE_OP;
                    tmp->op_u.var_no=var_num;
                    c1->u.two.op2=tmp;
                    InsertCode(c1);
                }
            }
            else if(search_func!=NULL){
                if(place!=NULL){
                    InterCode c1=(InterCode)malloc(sizeof(struct InterCode_));
                    c1->kind=ASSIGN_IR;
                    c1->u.two.op1=copy_operand(place);
                    int var_num=get_var_num(search_func->name);
                    Operand tmp=(Operand)malloc(sizeof(struct Operand_));
                    tmp->kind=VARIABLE_OP;
                    tmp->op_u.var_no=var_num;
                    c1->u.two.op2=tmp;
                    InsertCode(c1);
                }
            }
        }
    }
}

void translate_Args(struct Node*r,ArgList arg_list){
    struct Node*child=r->first_child;
    Operand t1=new_temp();
    translate_Exp(child,t1);
    ArgList tmp=(ArgList)malloc(sizeof(struct ArgList_));
    tmp->arg=t1;
    tmp->next=arg_list->next;
    arg_list->next=tmp;
    if(child->sibling!=NULL){
        child=child->sibling->sibling;
        return translate_Args(child,arg_list);
    }
}

