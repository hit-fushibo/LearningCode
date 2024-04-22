#include"syntax.tab.h"
#include<stdio.h>
#include<stdlib.h>
#include"Sem.c"

extern void yyrestart(FILE*);
extern struct node * root;
int main(int argc,char** argv)
{
    if(argc<=1) return 1;
    FILE *f =fopen(argv[1],"r");
    if (!f)
    {
        perror(argv[1]);
        return 1;
    }
    yyrestart(f);
    yyparse();
    Analyze_Program(root);

    return 0;
}
