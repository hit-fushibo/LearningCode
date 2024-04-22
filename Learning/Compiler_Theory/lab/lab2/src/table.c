#include"table.h"

void init_int_float_type()
{
    INT_TYPE=(Type)malloc(sizeof(struct Type_));
    INT_TYPE->kind=0;
    INT_TYPE->u.basic=0;
    FLOAT_TYPE=(Type)malloc(sizeof(struct Type_));
    FLOAT_TYPE->kind=0;
    FLOAT_TYPE->u.basic=1;
}

void add_symbol(symbol* head,symbol new_symbol)
{
    if (*head==NULL)
    {
    	*head=new_symbol;
    	
    	return;
    }
    symbol t=*head;
    while (t->tail!=NULL)
    {
        t=t->tail;
    }
    t->tail=new_symbol;
}

void del_table(symbol head)
{   if(head==NULL)
    {
    	return;
    }
    else
    {
    	del_table(head->tail);
    	free(head);
    }
}

int check_symbol(symbol head,char* symbol_name)
{
    
    symbol t=head;
    if(t==NULL)
    {
    	
        return 0;
    }
    
    if(!strcmp(t->name,symbol_name))
    {
        return 1;
    }
    
    if(t->type!=NULL)
    {
    if(t->type->kind==2)
    {
    
        FieldList temp=t->type->u.structure;
        while (temp->tail!=NULL)
        {
            if(!strcmp(temp->name,symbol_name))
            {
                return 1;
            }
        }
            
    }
    }
    
    while (t->tail!=NULL)
    {
        if(!strcmp(t->name,symbol_name))
        {
            return 1;
        }
        if(t->type!=NULL)
        {
        if(t->type->kind==2)
        {
            FieldList temp=t->type->u.structure;
            while (temp->tail!=NULL)
            {
                if(!strcmp(temp->name,symbol_name))
                {
                    return 1;
                }
            }
            
        }
        }
        t=t->tail;
    }
    
    return 0;
}

symbol find_symbol(symbol head,char* name)
{
    symbol t=head;
    if(!strcmp(t->name,name))
    {
        return t;
    }
    while (t->tail!=NULL)
    {
        if(!strcmp(t->name,name))
        {
            return t;
        }
        t=t->tail;
    }
    return NULL;
}
