#include"SymTable.h"
FieldList cur_tail[128];
void new_symbol_table() {
	stack_top++;
	SYMBOL_TALBE_STACK[stack_top] = NULL;
	cur_tail[stack_top]=NULL;
}
FieldList pop_symbol_table() {
	FieldList res=SYMBOL_TALBE_STACK[stack_top];
	SYMBOL_TALBE_STACK[stack_top] = NULL;
	cur_tail[stack_top]=NULL;
	stack_top--;
	return res;
}
void insert_fieldlist(FieldList p) {
	p->tail=NULL;
	if(cur_tail[stack_top]==NULL){
		SYMBOL_TALBE_STACK[stack_top]=p;
		cur_tail[stack_top]=p;
	}
	else{
		cur_tail[stack_top]->tail=p;
		cur_tail[stack_top]=p;
	}
}
FieldList can_use_search(char* name, int func) {
	//func=0:is a func,=1:not a func,=2:structure
	if(func==0){
		for (int point = stack_top; point >= 0;--point) {
			for (FieldList p = SYMBOL_TALBE_STACK[point]; p != NULL; p = p->tail) 
				if (strcmp(p->name, name) == 0)
					if (p->type->kind == FUNCTION)return p;
		}
	}
	else if(func==2){
		for (int point = stack_top; point >= 0;--point) {
			for (FieldList p = SYMBOL_TALBE_STACK[point]; p != NULL; p = p->tail) 
				if (strcmp(p->name, name) == 0)
					if (p->type->kind == STRUCTURE)return p;
		}
	}
	else{
		for (int point = stack_top; point >= 0;--point) {
			for (FieldList p = SYMBOL_TALBE_STACK[point]; p != NULL; p = p->tail) 
				if (strcmp(p->name, name) == 0)
					if (p->type->kind != FUNCTION)return p;
		}
	}

	return NULL;
}
FieldList can_new_search(char* name, int func) {
	//func=0:is a func,=1:other,=2:struct
	if(func==0){
		for (int point = stack_top; point >= 0;--point) {
			for (FieldList p = SYMBOL_TALBE_STACK[point]; p != NULL; p = p->tail) 
				if (strcmp(p->name, name) == 0)
					if (p->type->kind == FUNCTION)return p;
		}
	}
	else if(func==2){
		for (int point = stack_top; point >= 0;--point) {
			for (FieldList p = SYMBOL_TALBE_STACK[point]; p != NULL; p = p->tail) 
				if (strcmp(p->name, name) == 0)
					if (p->type->kind != FUNCTION)return p;
		}
	}
	else{
		for (FieldList p = SYMBOL_TALBE_STACK[stack_top]; p != NULL; p = p->tail) 
			if (strcmp(p->name, name) == 0)
				if (p->type->kind != FUNCTION)return p;
		for (int point = stack_top-1; point >= 0;--point) {
			for (FieldList p = SYMBOL_TALBE_STACK[point]; p != NULL; p = p->tail) 
				if (strcmp(p->name, name) == 0)
					if (p->type->kind == STRUCTURE)return p;
		}
	}

	return NULL;
}
int func_compare(FieldList a, FieldList b) {
	//0-==,1-!=
	if(strcmp(a->name,b->name)!=0)return 1;
	if(type_compare(a->type,b->type)!=0)return 1;
	return 0;
}
int type_compare(Type a,Type b){
	//0-==,1-!=
	//if(a->kind==ERROR||b->kind==ERROR)return 0;
	if(a->kind==BASIC){
		if(b->kind==BASIC&&a->u.basic==b->u.basic)return 0;
		else return 1;
	}
	else if(a->kind==ARRAY){
		if(b->kind==ARRAY)return type_compare(a->u.array.elem,b->u.array.elem);
		else return 1;
	}
	else if(a->kind==STRUCTURE){
		if(b->kind==STRUCTURE){
			FieldList pa=a->u.structure;
			FieldList pb=b->u.structure;
			for(;pa!=NULL&&pb!=NULL;pa=pa->tail,pb=pb->tail)
				if(type_compare(pa->type,pb->type)==1)return 1;
			if(pa==NULL&&pb==NULL)return 0;
			else return 1;
		}
		else return 1;
	}
	else if(a->kind==FUNCTION){
		if(b->kind==FUNCTION){
			FieldList pa=a->u.func.parameter;
			FieldList pb=b->u.func.parameter;
			for(;pa!=NULL&&pb!=NULL;pa=pa->tail,pb=pb->tail)
				if(type_compare(pa->type,pb->type)==1)return 1;
			if(pb!=NULL||pa!=NULL)return 1;
			if(type_compare(a->u.func.return_type,b->u.func.return_type)==0)return 0;
			else return 1;
		}
		else return 1;
	}
	return 1;
}
Type new_error_type(){
	Type t=(Type)malloc(sizeof(struct Type_));
	t->kind=ERROR;
	t->can_be_left=0;
	return t;
}

FieldList CopyFieldList(FieldList field){
    FieldList res=(FieldList)malloc(sizeof(struct FieldList_));
    strcpy(res->name,field->name);
    res->tail=NULL;
    res->type=CopyType(field->type);
	res->var_num=-1;
	res->addr_or_not=0;
    return res;
}
Type CopyType(Type t){
    Type res=(Type) malloc(sizeof(struct Type_));
    res->kind=t->kind;
    res->can_be_left=0;
    if(res->kind==BASIC)res->u.basic=t->u.basic;
    else if(res->kind==ARRAY){
        res->u.array.size=t->u.array.size;
        res->u.array.elem=CopyType(t->u.array.elem);
    }
    else if(res->kind==STRUCTURE){
        res->u.structure=NULL;
        FieldList Tail=NULL;
        for(FieldList t_mem=t->u.structure;t_mem!=NULL;t_mem=t_mem->tail){
            FieldList p=(FieldList)malloc(sizeof(struct FieldList_));
            p->tail=NULL;
			p->var_num=-1;
			p->addr_or_not=0;
            strcpy(p->name,t_mem->name);
            p->type=CopyType(t_mem->type);
            if(Tail==NULL){res->u.structure=p;Tail=p;}
            else {Tail->tail=p;Tail=p;}
        }
    }
    else res=t;//函数和error不需要copy
    return res;
}