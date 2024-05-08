#ifndef DEF_SYMTABLE
#define DEF_SYMTABLE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Type_* Type;
typedef struct FieldList_* FieldList;

struct Type_
{
	enum { BASIC, ARRAY, STRUCTURE, FUNCTION ,ERROR} kind;
	union
	{
		// 基本类型,0-int,1-float
		int basic;
		// 数组类型信息包括元素类型与数组大小构成
		struct { Type elem; int size; } array;
		// 结构体类型信息是一个链表
		FieldList structure;
		//函数类型信息是一个链表,defined=0-undefined,1-defined
		struct {FieldList parameter; int defined; Type return_type;}func;
	} u;
	int can_be_left;//0-can't,1-can
	int line;
};

struct FieldList_
{
	char name[32]; // 域的名字
	Type type; // 域的类型
	FieldList tail; // 下一个域
	int var_num;
	int addr_or_not;//1-is a parameter and a 数组/struct
};

FieldList SYMBOL_TALBE_STACK[128];
int stack_top;
FieldList FINAL_SYMBOL_TABLE;

void new_symbol_table();
FieldList pop_symbol_table();
void insert_fieldlist(FieldList p);
FieldList can_use_search(char* name, int func);
FieldList can_new_search(char* name, int func);
int func_compare(FieldList a, FieldList b);
int type_compare(Type a,Type b);
Type new_error_type();
FieldList CopyFieldList(FieldList field);
Type CopyType(Type t);

#endif