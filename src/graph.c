#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
//#include "functions.h"
#include "stack.h"
#include "data_input.h"

int main()
{
    // string test
    int flag = 1;
    char * str = input_string(&flag);
    printf("string %s\n" , str);
    lex* lexem = malloc(sizeof(lex));
    lexem->type = NUM;
    lexem->elem.num = 15;
    push_lex(&lexem, OP, ADD);
    stack* nums;
        if (lexem->type == NUM) {
            push(&nums, lexem->elem.num);
        }
    push (&nums, 5);
    push(&nums, 3);
    int flag = 1;
    printf("nums data %d\nlexem %d %d\n",  nums->data, (FUNK)lexem->type, (FUNK)lexem->elem.func);
    printf("operations %lf\n", operations(&nums,ADD,&flag));
    free(str);
    free(lexem);
}
