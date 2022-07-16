#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "functions.h"
#include "stack.h"

int main()
{
    char * str = input_string();
    struct lex lexem;
    lexem.type = NUM;
    lexem.num = 15;
    printf("%s\n%d %d", str, lexem.type, lexem.num);
    free(str);
}
