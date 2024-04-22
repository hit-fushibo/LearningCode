#include"Sem.h"
#include"table.c"

#define INT 0
#define FLOAT 1
#define ARRAY 2
#define ARRAY_INT 7
#define ARRAY_FLOAT 8
#define STRUCT 3
#define RIGHT_ONLY 4
#define FUNC_RETURN 5
#define ERROR 6

Type current_type;
int nd_array_dim[32]={0};
int nd_array_dim_cnt;
Type P_type;
int exp_left=0;
symbol var_table;
symbol struct_table;
symbol func_table;
symbol temp_var;
int struct_error1=0;
FieldList S2F(symbol head)
{
    FieldList f=(FieldList)malloc(sizeof(struct FieldList_));
    
    f->is_def=head->is_def;
    f->name=(char*)malloc(strlen(head->name));
    memcpy(f->name,head->name,strlen(head->name));
    f->type=head->type;
    if(head->tail)
    {
        f->tail=S2F(head->tail);
    }
    else
    {
        f->tail=NULL;
    }

}

int Analyze_Program(struct node* root){
    
    var_table=NULL;
    struct_table=NULL;
    func_table=NULL;
    temp_var=NULL;
    
    init_int_float_type();
    
    Analyze_ExtDefList(root->children);
    print_error(error_head);
    return 0;
}


int Analyze_ExtDefList(struct node* root){
    if(root->children)
    {
        Analyze_ExtDef(root->children);
        Analyze_ExtDefList(root->children->right_bro);
    }
    else
    {
        
    }
    return 0;
}


int Analyze_ExtDef(struct node* root){
    if(root->children->right_bro->right_bro==NULL)
    {
        //ExtDef->specifier ;
        
        Analyze_Specifier(root->children);
    }
    else if(strcmp(root->children->right_bro->right_bro->name,"SEMI")==0)
    {
        //ExtDef->specifier ExtDecList ;

        Analyze_Specifier(root->children);
        Analyze_ExtDecList(root->children->right_bro);
    }
    else
    {
        //ExtDef->specifier FuncDec CompSt;

        Analyze_Specifier(root->children);
        Analyze_FunDec(root->children->right_bro);
        Analyze_CompSt(root->children->right_bro->right_bro);
    }
    current_type=NULL;
    del_table(temp_var);

    temp_var=NULL;
}


int Analyze_ExtDecList(struct node* root){
    if(root->children->right_bro==NULL)
    {
        //ExtDecList->VarDec
        symbol p=Analyze_VarDec(root->children);
        
        if (p==NULL)return 0;
        add_symbol(&var_table,p);
        if(p->type)//ndarray
        {   
            
            Type temp=p->type;
            while (temp->u.array.elem)
            {
                temp=temp->u.array.elem;
            }
            temp->u.array.elem=(Type)malloc(sizeof(struct Type_));
            memcpy(temp->u.array.elem,current_type,sizeof(struct Type_));
        }
        else
        {
            p->type=(Type)malloc(sizeof(struct Type_));
            memcpy(p->type,current_type,sizeof(struct Type_));
        }
    }
    else
    {
        //VarDec , ExtDecList
        symbol p=Analyze_VarDec(root->children);
        
        if(p!=NULL)
        {    
            add_symbol(&var_table,p);
            if(p->type)//ndarray
            {   
                Type temp=p->type;
                while (temp->u.array.elem)
                {
                    temp=temp->u.array.elem;
                }
                temp->u.array.elem=(Type)malloc(sizeof(struct Type_));
                memcpy(temp->u.array.elem,current_type,sizeof(struct Type_));
            }
            else
            {
                p->type=(Type)malloc(sizeof(struct Type_));
                memcpy(p->type,current_type,sizeof(struct Type_));
            }
        }

        Analyze_ExtDecList(root->children->right_bro->right_bro);
    }
}


int Analyze_Specifier(struct node* root){
    if(strcmp(root->children->name,"StructSpecifier"))
    {
        current_type=(Type)malloc(sizeof(struct Type_));
        //TYPE
        if(strcmp(root->children->value,"int")==0)
        {
            memcpy(current_type,INT_TYPE,sizeof(struct Type_));
            
        }
        else
        {
            memcpy(current_type,FLOAT_TYPE,sizeof(struct Type_));
        }
        
    }
    else
    {
        //StructSpecifier
        
        Analyze_StructSpecifier(root->children);
        
    }
}

int Analyze_P_Specifier(struct node* root)
{
    if(strcmp(root->children->name,"StructSpecifier"))
    {
        P_type=(Type)malloc(sizeof(struct Type_));
        //TYPE
        if(strcmp(root->children->value,"int"))
        {
            memcpy(P_type,INT_TYPE,sizeof(struct Type_));
        }
        else
        {
            memcpy(P_type,FLOAT_TYPE,sizeof(struct Type_));
        }
        
    }
    else
    {
        //StructSpecifier
        Analyze_P_StructSpecifier(root->children);
    }
}


int Analyze_StructSpecifier(struct node* root){
    symbol s=(symbol)malloc(sizeof(struct symbol_));
    if(strcmp(root->children->right_bro->name,"Tag"))
    {
        //STRUCT OptTag LC DefList RC
        char* name=Analyze_OptTag(root->children->right_bro);
        if(name)
        {
            
            s->name=name;
            s->is_def=0;
            s->tail=NULL;
            add_symbol(&struct_table,s);
            
        }
        
        symbol structure=Analyze_DefList(root->children->right_bro->right_bro->right_bro);
        
        Type t=(Type)malloc(sizeof(struct Type_));
        t->kind=2;
        FieldList s=S2F(structure);
        t->u.structure=(FieldList)malloc(sizeof(struct FieldList_));
        t->u.structure=s;
        
        if(name)//结构体声明
        {   
            s->type=t;
        }
        else//临时定义一个结构体
        {
            current_type=(Type)malloc(sizeof(struct Type_));
            memcpy(current_type,t,sizeof(struct Type_));
        }
    }
    else
    {
        //STRUCT Tag
        char* name=Analyze_Tag(root->children->right_bro);
        Type t=find_symbol(struct_table,name)->type;
        if(t)
        {
            current_type=(Type)malloc(sizeof(struct Type_));
            memcpy(current_type,t,sizeof(struct Type_));
        }
    }
}

int Analyze_P_StructSpecifier(struct node* root)
{
    if(strcmp(root->children->right_bro->name,"Tag"))
    {
        //STRUCT OptTag LC DefList RC
        char* name=Analyze_OptTag(root->children->right_bro);
        if(struct_error1)
        {
            return 0;
        }
        symbol structure=Analyze_DefList(root->children->right_bro->right_bro->right_bro);
        Type t=(Type)malloc(sizeof(struct Type_));
        t->kind=2;
        FieldList s=S2F(structure);
        t->u.structure=(FieldList)malloc(sizeof(struct FieldList_));
        t->u.structure=s;
        
        if(name)//结构体声明
        {    
            symbol s=(symbol)malloc(sizeof(symbol));
            s->name=name;
            s->type=t;
            s->is_def=0;
            s->tail=NULL;
            add_symbol(&struct_table,s);
        }
        else//临时定义一个结构体
        {
            P_type=(Type)malloc(sizeof(struct Type_));
            memcpy(P_type,t,sizeof(struct Type_));
        }
    }
    else
    {
        //STRUCT Tag
        char* name=Analyze_Tag(root->children->right_bro);
        Type t=find_symbol(struct_table,name)->type;
        if(t)
        {
            P_type=(Type)malloc(sizeof(struct Type_));
            memcpy(current_type,t,sizeof(struct Type_));
        }
    }
}


char* Analyze_OptTag(struct node* root){
    if(root->is_null){
        return NULL;
    }
    else
    {
        
        char* name=root->children->value;
        if(check_symbol(var_table,name)||check_symbol(temp_var,name)||check_symbol(struct_table,name))
        {
            struct_error1=1;
            add_error(3,root->lineno);
        }
        char* name_=(char*)malloc(strlen(name));
        memcpy(name_,name,strlen(name));
        return name_;
    }
}


char* Analyze_Tag(struct node* root){
    char* name=root->children->value;
    
    return name;
}


symbol Analyze_VarDec(struct node* root){
    symbol s=(symbol)malloc(sizeof(struct symbol_));
    if(root->children->right_bro==NULL)
    {
        // ID
        
        char* name=root->children->value;
        if(check_symbol(var_table,name)||check_symbol(temp_var,name)||check_symbol(struct_table,name))
        {
            
            add_error(3,root->lineno);
            return NULL;
        }
        s->name=(char*)malloc(strlen(name));
        
        memcpy(s->name,name,strlen(name));
        
        s->type=NULL;
        s->is_def=0;
        s->tail=NULL;
        return s;
    }
    else
    {
        // VarDec [INT]
        int size=atoi(root->children->right_bro->right_bro->value);
        s=Analyze_VarDec(root->children);
        Type t=(Type)malloc(sizeof(struct Type_));
        t->kind=1;
        t->u.array.size=size;
        t->u.array.elem=s->type;
        s->type=t;
        return s;
    }
}


int Analyze_FunDec(struct node* root){
    if(root->children->right_bro->right_bro->right_bro)
    {
        //ID(VarList)
        
        Analyze_VarList(root->children->right_bro->right_bro);
    }
    else
    {
        symbol s=(symbol)malloc(sizeof(struct symbol_));
        char* name=root->children->value;
        s->name=(char*)malloc(strlen(name));
        memcpy(s->name,name,strlen(name));
        s->type=NULL;
        s->is_def=0;
        s->tail=NULL;
        add_symbol(&func_table,s);
        del_table(temp_var);
        temp_var=NULL;
    }

}


int Analyze_VarList(struct node* root){
    if (root->children->right_bro)
    {
        //ParamDec,VarList
        Analyze_ParamDec(root->children);
        Analyze_VarList(root->children->right_bro->right_bro);
    }
    else
    {
        //ParamDec
        Analyze_ParamDec(root->children);
    }

}


int Analyze_ParamDec(struct node* root){
    Analyze_P_Specifier(root->children);
    symbol p=Analyze_VarDec(root->children->right_bro);
    add_symbol(&temp_var,p);
    if (p==NULL)return 0;
    if(p->type)//ndarray
    {   
        Type temp=p->type;
        while (temp->u.array.elem)
        {
            temp=temp->u.array.elem;
        }
        temp->u.array.elem=(Type)malloc(sizeof(struct Type_));
        memcpy(temp->u.array.elem,current_type,sizeof(struct Type_));
    }
    else
    {
        p->type=(Type)malloc(sizeof(struct Type_));
        memcpy(p->type,current_type,sizeof(struct Type_));
    }
}


int Analyze_CompSt(struct node* root){

    Analyze_DefList(root->children->right_bro);
    
    
    Analyze_StmtList(root->children->right_bro->right_bro);
}


int Analyze_StmtList(struct node* root){
    if(root->is_null)
    {
        return 0;
    }
    else
    {
        Analyze_Stmt(root->children);
        Analyze_StmtList(root->children->right_bro);
    }
}


int Analyze_Stmt(struct node* root){
    if(strcmp(root->children->name,"Exp")==0)
    {
        //Exp ;
        Analyze_Exp(root->children);
    }
    else if (strcmp(root->children->name,"CompSt")==0)
    {
        //CompSt;
        Analyze_CompSt(root->children);
    }
    else if (strcmp(root->children->name,"RETURN")==0)
    {
        //RETURN Exp;
        Analyze_Exp(root->children->right_bro);
    }
    else if (strcmp(root->children->name,"IF"))
    {
        int t=Analyze_Exp(root->children->right_bro->right_bro);
        
        if(t!=INT)
        {
            add_error(6,root->lineno);
        }
        Analyze_Stmt(root->children->right_bro->right_bro->right_bro->right_bro);
        if(root->children->right_bro->right_bro->right_bro->right_bro->right_bro)
        {
            Analyze_Stmt(root->children->right_bro->right_bro->right_bro->right_bro->right_bro->right_bro);
        }
    }
    else
    {
        int t=Analyze_Exp(root->children->right_bro->right_bro);
        
        if(t!=INT)
        {
            add_error(6,root->lineno);
        }
        Analyze_Stmt(root->children->right_bro->right_bro->right_bro->right_bro);
    }
    
    
    
}


symbol Analyze_DefList(struct node* root){
    if (root->is_null)
    {
        return NULL;
    }
    else
    {
        symbol s=Analyze_Def(root->children);
        symbol S=Analyze_DefList(root->children->right_bro);
        if (s==NULL)
        {
            return S;
        }
        s->tail=S;
        return s;
    }
}


symbol Analyze_Def(struct node* root)
{
    Analyze_Specifier(root->children);
    symbol s=Analyze_DecList(root->children->right_bro);
    
    if (s==NULL)
    {
    	return NULL;
    }
    
    add_symbol(&var_table,s);
    return s;
}

symbol Analyze_DecList(struct node* root)
{
    symbol s=(symbol)malloc(sizeof(struct symbol_));
    symbol S=(symbol)malloc(sizeof(struct symbol_));
    if (root->children->right_bro)
    {
        s=Analyze_Dec(root->children);
        if(s==NULL)
        {
            S=Analyze_DecList(root->children->right_bro);
            return S;
        
        }
        if(s->type)//ndarray
        {   
            Type temp=s->type;
            while (temp->u.array.elem)
            {
                temp=temp->u.array.elem;
            }
            temp->u.array.elem=(Type)malloc(sizeof(struct Type_));
            memcpy(temp->u.array.elem,current_type,sizeof(struct Type_));
        }
        else
        {
            s->type=(Type)malloc(sizeof(struct Type_));
            memcpy(s->type,current_type,sizeof(struct Type_));
        }
        S=Analyze_DecList(root->children->right_bro->right_bro);
        s->tail=S;
        
    }
    else
    {
        s=Analyze_Dec(root->children);
        if(s==NULL)return s;
        if(s->type)//ndarray
        {   
            Type temp=s->type;
            while (temp->u.array.elem)
            {
                temp=temp->u.array.elem;
            }
            temp->u.array.elem=(Type)malloc(sizeof(struct Type_));
            memcpy(temp->u.array.elem,current_type,sizeof(struct Type_));
        }
        else
        {
            s->type=(Type)malloc(sizeof(struct Type_));
            memcpy(s->type,current_type,sizeof(struct Type_));
        }
    }
    
    return s;
    
    
}

symbol Analyze_Dec(struct node* root)
{
    symbol s=(symbol)malloc(sizeof(struct symbol_));
    s=Analyze_VarDec(root->children);
    if(s==NULL)return s;
    if(root->children->right_bro)
    {
        s->is_def=1;
        int t=Analyze_Exp(root->children->right_bro->right_bro);
        if(current_type->kind==0)
        {
            if(current_type->u.basic!=t)
            {
                add_error(5,root->lineno);
            }
         
        }
        else if (current_type->kind==2)
        {
            if(t!=STRUCT)
            {
                add_error(5,root->lineno);
            }
        }
        else
        {
            int t1=type2array_code(current_type);
            if(t!=t1)
            {
                add_error(5,root->lineno);
            }
        }
    }
    
    return s;

}



int Analyze_Exp(struct node* root){
    if(!strcmp(root->children->name,"LP"))
    {
        //( Exp )
        return Analyze_Exp(root->children->right_bro);
    }
    if(!strcmp(root->children->name,"MINUS"))
    {
        //-Exp
        return Analyze_Exp(root->children->right_bro);
    }
    if(!strcmp(root->children->name,"NOT"))
    {
        //!EXP
        if(Analyze_Exp(root->children->right_bro)==INT||Analyze_Exp(root->children->right_bro)==FUNC_RETURN)
        {
            return INT;
        }
        else
        {
            return ERROR;
        }
    }
    if(!strcmp(root->children->name,"ID"))
    {
        if(root->children->right_bro==NULL)
        {   

            //ID
            
            symbol s=find_symbol(var_table,root->children->value);
            if(s==NULL)
            {
                add_error(1,root->lineno);
                return ERROR;
            }
            else
            {
                if(s->type->kind==0&&s->type->u.basic==0)
                {
                    
                    return INT;
                }
                else if (s->type->kind==0&&s->type->u.basic==1)
                {
                    
                    return FLOAT;
                }
                else if (s->type->kind==2)
                {
                    return STRUCT;
                }
                else
                {   
                    return type2array_code(s->type);
                }
            }
        }
        else if (strcmp(root->children->right_bro->right_bro->name,"Args")==0)
        {
            //ID (Args)
            Analyze_Args(root->children->right_bro->right_bro);
        }
        else
        {
            return FUNC_RETURN;
        }
        
    }
    if(!strcmp(root->children->name,"INT"))
    {
        //INT
        exp_left=1;
        return INT;
    }
    if(!strcmp(root->children->name,"FLOAT"))
    {
        //FLOAT
        exp_left=1;
        return FLOAT;
    }
    if(!strcmp(root->children->right_bro->name,"ASSIGNOP"))
    {
        //exp = exp
        exp_left=0;
        int type1=Analyze_Exp(root->children);
        int error_flag=0;
        if (exp_left)
        {
            add_error(6,root->lineno);
            error_flag=1;
        }
        int type2=Analyze_Exp(root->children->right_bro->right_bro);
        if(type1==FUNC_RETURN)return type2;
        if(type2==FUNC_RETURN)return type1;
        
        if (type1!=type2)
        {
            
            add_error(5,root->lineno);
            error_flag=1;
        }
        if (error_flag)
        {
            return ERROR;
        }
        else 
        {
            return type1;
        }
        
    }
    if(!strcmp(root->children->right_bro->name,"AND"))
    {
        int type1=Analyze_Exp(root->children);
        int type2=Analyze_Exp(root->children->right_bro->right_bro);
        if((type1==INT&&type2==INT)||(type1==FUNC_RETURN&&type2==INT)||(type2==FUNC_RETURN&&type1==INT)||(type1==FUNC_RETURN&&type2==FUNC_RETURN))
        {
            return INT;
        }
        else
        {
            add_error(7,root->lineno);
            return ERROR;
        }
    }
    if(!strcmp(root->children->right_bro->name,"OR"))
    {
        int type1=Analyze_Exp(root->children);
        int type2=Analyze_Exp(root->children->right_bro->right_bro);
        if((type1==INT&&type2==INT)||(type1==FUNC_RETURN&&type2==INT)||(type2==FUNC_RETURN&&type1==INT)||(type1==FUNC_RETURN&&type2==FUNC_RETURN))
        {
            return INT;
        }
        else
        {
            add_error(7,root->lineno);
            return ERROR;
        }
    }
    if(!strcmp(root->children->right_bro->name,"RELOP"))
    {
        int type1=Analyze_Exp(root->children);
        int type2=Analyze_Exp(root->children->right_bro->right_bro);
        if((type1==INT&&type2==INT)||(type1==FUNC_RETURN&&type2==INT)||(type2==FUNC_RETURN&&type1==INT)||(type1==FUNC_RETURN&&type2==FUNC_RETURN))
        {
            return INT;
        }
        else
        {
            add_error(7,root->lineno);
            return ERROR;
        }
    }
    if(!strcmp(root->children->right_bro->name,"PLUS"))
    {
        
        int type1=Analyze_Exp(root->children);
        int type2=Analyze_Exp(root->children->right_bro->right_bro);
        
        if((type1==INT&&type2==INT)||(type1==FUNC_RETURN&&type2==INT)||(type2==FUNC_RETURN&&type1==INT))
        {
            return INT;
        }
        else if((type1==FLOAT&&type2==FLOAT)||(type1==FUNC_RETURN&&type2==FLOAT)||(type2==FUNC_RETURN&&type1==FLOAT))
        {
            return FLOAT;
        }
        else if(type1==FUNC_RETURN&&type2==FUNC_RETURN)
        {
            return FUNC_RETURN;
        }
        else
        {
            
            add_error(7,root->lineno);
            return ERROR;
        }
    }
    if(!strcmp(root->children->right_bro->name,"MINUS"))
    {
        //exp - exp
        int type1=Analyze_Exp(root->children);
        int type2=Analyze_Exp(root->children->right_bro->right_bro);
        if((type1==INT&&type2==INT)||(type1==FUNC_RETURN&&type2==INT)||(type2==FUNC_RETURN&&type1==INT))
        {
            return INT;
        }
        else if((type1==FLOAT&&type2==FLOAT)||(type1==FUNC_RETURN&&type2==FLOAT)||(type2==FUNC_RETURN&&type1==FLOAT))
        {
            return FLOAT;
        }
        else if(type1==FUNC_RETURN&&type2==FUNC_RETURN)
        {
            return FUNC_RETURN;
        }
        else
        {
            add_error(7,root->lineno);
            return ERROR;
        }
    }
    if(!strcmp(root->children->right_bro->name,"STAR"))
    {
        //exp * exp
        int type1=Analyze_Exp(root->children);
        int type2=Analyze_Exp(root->children->right_bro->right_bro);
        if((type1==INT&&type2==INT)||(type1==FUNC_RETURN&&type2==INT)||(type2==FUNC_RETURN&&type1==INT))
        {
            return INT;
        }
        else if((type1==FLOAT&&type2==FLOAT)||(type1==FUNC_RETURN&&type2==FLOAT)||(type2==FUNC_RETURN&&type1==FLOAT))
        {
            return FLOAT;
        }
        else if(type1==FUNC_RETURN&&type2==FUNC_RETURN)
        {
            return FUNC_RETURN;
        }
        else
        {
            add_error(7,root->lineno);
            return ERROR;
        }
    }
    if(!strcmp(root->children->right_bro->name,"DIV"))
    {
        //exp / exp
        int type1=Analyze_Exp(root->children);
        int type2=Analyze_Exp(root->children->right_bro->right_bro);
        if((type1==INT&&type2==INT)||(type1==FUNC_RETURN&&type2==INT)||(type2==FUNC_RETURN&&type1==INT))
        {
            return INT;
        }
        else if((type1==FLOAT&&type2==FLOAT)||(type1==FUNC_RETURN&&type2==FLOAT)||(type2==FUNC_RETURN&&type1==FLOAT))
        {
            return FLOAT;
        }
        else if(type1==FUNC_RETURN&&type2==FUNC_RETURN)
        {
            return FUNC_RETURN;
        }
        else
        {
            add_error(7,root->lineno);
            return ERROR;
        }

    }
    if(!strcmp(root->children->right_bro->name,"LB"))
    {
        //Exp [Exp]
        int type1=Analyze_Exp(root->children);
        
        int type2=Analyze_Exp(root->children->right_bro->right_bro);
        exp_left=0;
        int error_flag=0;
        if(type1%10!=ARRAY&&type1%10!=ARRAY_INT&&type1%10!=ARRAY_FLOAT)
        {
            
            error_flag=1;
            add_error(10,root->lineno);
        }
        if(type2!=INT)
        {
            error_flag=1;
            add_error(12,root->lineno);

        }
        if (error_flag)return ERROR;
        else
        {
            if(type1%10==ARRAY)return type1/10;
            if(type1%10==ARRAY_INT)return INT;
            if(type1%10==ARRAY_FLOAT)return FLOAT;
        }
        
    }
    if(!strcmp(root->children->right_bro->name,"DOT"))
    {
        
        int t=prase_struct(root);
        return t;
    }
    
}

int prase_struct(struct node* root)
{
    FieldList f=prase_struct_help_func(root->children);
    if(f==NULL)return ERROR;
    else
    {
        if(strcmp(f->name,root->children->right_bro->right_bro->name)==0)
        {
            if(f->type->kind==0)return f->type->u.basic;
            else if (f->type->kind==2)
            {
                return STRUCT;
            }
            else
            {
                return type2array_code(f->type);
            }
            
        }
        while (f->tail)
        {
            if(strcmp(f->name,root->children->right_bro->right_bro->name)==0)
            {
                if(f->type->kind==0)return f->type->u.basic;
                else if (f->type->kind==2)
                {
                    return STRUCT;
                }
                else
                {
                    return type2array_code(f->type);
                }
            }
            f=f->tail;
        }
    }
    return ERROR;
}

FieldList prase_struct_help_func(struct node*root)
{
    if (strcmp(root->children->name,"ID"))
    {
        //依然存在嵌套结构体
        FieldList f=prase_struct_help_func(root->children);
        if(f==NULL)return NULL;
        if(strcmp(f->name,root->children->right_bro->right_bro->name)==0)
        {
            return f;
        }
        while (f->tail)
        {
            if(strcmp(f->name,root->children->right_bro->right_bro->name)==0)
            {
                return f;
            }
            f=f->tail;
        }
        return NULL;
    }
    else
    {
        symbol s=find_symbol(var_table,root->children->value);
        if(s==NULL)
        {
            add_error(1,root->lineno);
        }
        else
        {
            return s->type->u.structure;
        }
    }
}

int type2array_code(Type t)
{
    if(t->u.array.elem->kind==0)
    {
        if(t->u.array.elem->u.basic==0)
        {
            return ARRAY_INT;
        }
        else
        {
            return ARRAY_FLOAT;
        }
    }
    else
    {
        int t1=type2array_code(t->u.array.elem);
        return t1*10+3;
    }
}

int Analyze_Args(struct node* root){
    Analyze_Exp(root->children);
    exp_left=0;
    if(root->children->right_bro)
    {
        Analyze_Args(root->children->right_bro->right_bro);
    }
}

void add_error(int error_type,int lineno)
{
    if(error_head==NULL)
    {
        error_head=(error)malloc(sizeof(struct error_));
        error_head->error_type=error_type;
        error_head->lineno=lineno;
        error_head->tail=NULL;
    }
    else
    {
        error t=(error)malloc(sizeof(struct error_));
        t->error_type=error_type;
        t->lineno=lineno;
        error temp=error_head;
        while (temp->tail!=NULL)
        {
            temp=temp->tail;
        }
        temp->tail=t;
    }
}

void print_error(error head)
{
    if(head)
    {
        printf("ERROR type [%d] at Line [%d].\n",head->error_type,head->lineno);
        print_error(head->tail);
    }
}
