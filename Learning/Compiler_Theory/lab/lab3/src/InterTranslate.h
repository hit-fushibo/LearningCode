#include "tree.h"
#include"SemAnl.h"

typedef struct Operand_* Operand;
struct Operand_ {
    enum { 
        VARIABLE_OP, 
        CONSTANT_OP, 
        FUNCTION_OP,//u.name
        TEMP_OP,
        LABEL_OP } kind;//ADDRESS_OP, 
    union {
        int var_no;
        int value;
        char name[32];
        //...
    } op_u;
};
typedef struct InterCode_* InterCode;
struct InterCode_
{
    enum {
        LABEL_IR,//LABEL x :
        FUNCTION_IR,//FUNCTION f :
        ASSIGN_IR,//op1 := op2
        ADD_IR,//res := op1 + op2
        SUB_IR,//x := y - z
        MUL_IR,//x := y * z
        DIV_IR,//x := y / z
        GETADDR_IR,//x := &y
        GETVALUE_IR,//x := *y
        PUTADDR_IR,//*x := y
        GOTO_IR,//GOTO x
        IFGOTO_IR,//IF op1 [relop] op2 GOTO op3
        RETURN_IR,//RETURN x
        DEC_IR,//DEC x [size]
        ARG_IR,//ARG x
        CALL_IR,//op1 := CALL op2,if(op1==NULL)call op2
		PARAM_IR,//PARAM x
		READ_IR,//READ x
		WRITE_IR//WRITE x
    } kind;
    union {
        struct { Operand op; } one;
        struct { Operand op1, op2; } two;
        struct { Operand res, op1, op2; } three;
        struct { Operand op1, op2, op3; char relop[32]; } four;
        struct { Operand x; int size; } dec;
    } u;
};

//双向链表 实现可以写成：
typedef struct InterCodes_* InterCodes;
struct InterCodes_ { InterCode code; InterCodes prev, next; };

typedef struct ArgList_* ArgList;
struct ArgList_{Operand arg;ArgList next;};

typedef struct IR_NodeList_* IR_NodeList;
struct IR_NodeList_{struct Node*node;IR_NodeList next;};


void InsertCode(InterCode c);
void print_operand(Operand op,FILE*fp);
void print_IR(FILE*fp);
Operand new_temp();
Operand new_label();
int Addr_or_not(char*name);
int get_var_addr_num(char*name);
int get_var_num(char*name);
Operand get_func_op(FieldList func);
Operand new_constant(int x);
Operand copy_operand(Operand x);
int get_size(Type t);
void translate_start(struct Node*r,FILE*fp);
void translate_Program(struct Node *r);
void translate_ExtDefList(struct Node *r);
void translate_ExtDef(struct Node *r);
void translate_FunDec(struct Node*r);
void translate_VarDec(struct Node*r);
void translate_VarList(struct Node*r);
void translate_ParamDec(struct Node*r);
void translate_CompSt(struct Node*r);
void translate_StmtList(struct Node*r);
void translate_Stmt(struct Node*r);
void translate_DefList(struct Node*r);
void translate_Def(struct Node*r);
void translate_DecList(struct Node*r);
void translate_Dec(struct Node*r);
Operand translate_left_Exp(struct Node*r);
void translate_Cond(struct Node*r, Operand label_true, Operand label_false);
void translate_Exp(struct Node*r, Operand place);
void translate_Args(struct Node*r,ArgList arg_list);
void get_addr(struct Node*r,Operand place);
void get_addr_array(struct Node*r,Operand place);
void get_addr_structure(struct Node*r,Operand place);
Type get_type(struct Node*r);