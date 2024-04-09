#!/bin/bash

if [ "$1" = "--clean" ]; then
    rm -rf ./src/lex.yy.c ./src/syntax.tab.c ./src/syntax.tab.h ./bin/parser
elif [ "$1" = "--build" ]; then
    cd ./src
    flex lexical.l
    bison -d syntax.y
    flex lexical.l
    gcc main.c syntax.tab.c -lfl -ly -o ../bin/parser
    cd ..
else
    rm -rf ./src/lex.yy.c ./src/syntax.tab.c ./src/syntax.tab.h ./bin/parser
    cd ./src
    flex lexical.l
    bison -d syntax.y
    flex lexical.l
    gcc main.c syntax.tab.c -lfl -ly -o ../bin/parser
    cd ..
fi

