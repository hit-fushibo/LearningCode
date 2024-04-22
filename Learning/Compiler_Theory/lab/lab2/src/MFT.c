#include"MFT.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node* create_token_node(char* name,char*value,int lineno)
{
    struct node* gram_node=(struct node *)malloc(sizeof(struct node));
    gram_node->is_null=0;
    gram_node->name=(char*)malloc(strlen(name)+2);
    gram_node->value=(char*)malloc(strlen(value)+2);
    strcpy(gram_node->name,name);
    strcpy(gram_node->value,value);
    gram_node->lineno=lineno;
    gram_node->right_bro=NULL;
    gram_node->children=NULL;
    return gram_node;
}
struct node* create_gram_node(int is_null, char* name, char* value, int lineno) {
    struct node* gram_node=(struct node *)malloc(sizeof(struct node));
    gram_node->is_null=is_null;
    gram_node->name=(char*)malloc(strlen(name)+2);
    gram_node->value=(char*)malloc(strlen(value)+2);
    strcpy(gram_node->name,name);
    strcpy(gram_node->value,value);
    gram_node->lineno=lineno;
    gram_node->right_bro=NULL;
    gram_node->children=NULL;
    return gram_node;
}

void add_child(struct node* root, struct node* child) {
    if (root == NULL || child == NULL) {
        fprintf(stderr, "Invalid input: root or child is NULL");
        return;
    }
    if (root->children == NULL) {
        root->children = child;
        root->lineno=child->lineno;
    } else {
        struct node* temp = root->children;
        while (temp->right_bro != NULL) {
            temp = temp->right_bro;
        }
        temp->right_bro = child;
    }
}

void print_tree(struct node *root, int depth)
{
    if (root != NULL && root->is_null==0)
    {
        for (int i = 0; i < depth; i++)
        {
            printf("  ");
        }
        // 结构体属性输出
        printf("%s",root->name);
        if(strcmp(root->name,"ID")==0){
            printf(" :%s",root->value);
        }
        if(strcmp(root->name,"TYPE")==0){
            printf(" :%s",root->value);
        }
        if(strcmp(root->name,"INT")==0||strcmp(root->name,"FLOAT")==0){
            printf(" :%s",root->value);
        }
        printf(" (%d)\n",root->lineno);
    }
    if (root->children != NULL)
    {
        print_tree(root->children, depth + 1);
    }
    if (root->right_bro != NULL)
    {
        print_tree(root->right_bro, depth);
    }
}
