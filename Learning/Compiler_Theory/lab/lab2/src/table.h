#ifndef _TABLE_H_
#define _TABLE_H_

#include <stdlib.h>
#include <string.h>

typedef struct Type_ *Type;
typedef struct FieldList_ *FieldList;
typedef struct symbol_ *symbol;

struct Type_
{
    enum
    {
        BASIC=0,
        ARRAY=1,
        STRUCTURE=2,
        FUNC=3
    } kind;
    union
    {
        int basic; // 0 int,1 float
        FieldList func_param;//函数参数类型
        struct
        {
            Type elem;
            int size;
        } array;//数组类型
        FieldList structure;//结构体各个域
    } u;
};

Type INT_TYPE;
Type FLOAT_TYPE;

struct FieldList_
{
    char *name;
    Type type;
    int is_def;
    FieldList tail;
};

struct symbol_
{
    char *name;  // 符号名
    Type type;   // 符号类型
    int is_def;  // 是否被赋值 1是 0否
    symbol tail; // 下一个符号
};

symbol create_table()
{
    symbol head = (symbol)malloc(sizeof(struct symbol_));
    head->is_def = 0;
    head->name = (char*)malloc(sizeof(char));
    head->name[0]=' ';
    head->tail = NULL;
    head->type = NULL;
    return head;
}

void init_int_float_type();

// 向一个符号表中添加符号
void add_symbol(symbol* head, symbol new_symbol);

void del_table(symbol head);

// 检查一个符号是否在表中出现过，包括变量名，函数名，结构体名以及其域名
int check_symbol(symbol head, char *symbol_name);

symbol find_symbol(symbol head,char* name);


#endif
