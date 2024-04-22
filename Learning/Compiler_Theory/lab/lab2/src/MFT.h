#ifndef _MFT_H_
#define _MFT_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int is_null;
    char* name; //node type:INT/FLOAT...
    char* value; //if ID,TYPE,INT,FLOAT
    int lineno; //line
    struct node* right_bro; //the point of its right bro
    struct node* children; //the point of its first child
};
struct node* create_token_node(char* name,char*value,int lineno);
void print_tree(struct node* root,int depth);
struct node* create_gram_node(int is_null,char* name,char* value,int lineno);
void add_child(struct node* root,struct node* child);
#endif