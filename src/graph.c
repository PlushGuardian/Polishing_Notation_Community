#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "stack_and_struct.h"
#include "input_and_parse.h" 
#include "parsing_supplement.h"
#include "calculation.h"
#include "RPN.h"

int main()
{
    // string test
    int flag = 1;
    char * str = input_string(&flag);
    printf("string: %s\n" , str);
    if (flag != 1)
        printf("your input is shit\n");
    if (flag == -1)
        printf("oh no, we have problems with memory");
    // printf("flag %d", flag);
    lex* lexem;
    lex* reversed;
    int res = parse(str, &lexem) ;
    if (res != 1)
        printf("your input is awful\n");
    if (res == - 1)
        printf("oh no, we have problems with memory");
    flag = reverse_stack(&lexem, &reversed);
    printf("------this is reversed\n");
    print_struct(reversed);
    lexem = Reverse_RPN(reversed);
    printf("------this is after polish\n");
    print_struct(lexem);
    double rara;
    calculate(lexem, &rara, 1);
    printf("result %lf\n", rara) ;

    double result;
    flag = flag * calculate(lexem, &result, 1);
    printf("calculate %lf", result);
    free(str);
    free(reversed);
}


