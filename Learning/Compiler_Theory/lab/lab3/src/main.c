#include <stdio.h>
#include "InterTranslate.c"
#include "syntax.tab.h"
#include "SymTable.c"
#include "SemAnl.c"
extern FILE* yyin;
extern int yylex();
extern struct Node*root;
extern int yylineno;
extern void yyrestart(FILE *input_file);
extern int yyparse (void);
extern int LexError_NUM;
extern int SemError;

int main(int argc, char** argv)
{
    if (argc <= 1) return 1;
    FILE* f = fopen(argv[1], "r");
    if (!f)
    {
        perror(argv[1]);
        return 1;
    }
    FILE *f2=fopen(argv[2],"wt+");
    if(!f2){
        perror(argv[2]);
        return 1;
    }
    yylineno=1;
    yyrestart(f);
    yyparse();
    SemError=0;
    if(LexError_NUM == 0) {
        sem_Program(root);
        //print_tree(root,0);
        if(SemError==0){
            translate_start(root,f2);
        }
    }
    return 0;
}
