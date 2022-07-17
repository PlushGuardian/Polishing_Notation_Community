#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "stack.h"
#include "data_input.h"
#include "parsing_supplement.h"

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
    lex* start = lexem;
    int res = parse(str, &lexem) ;
    if (res != 1)
        printf("your input is awful\n");
    if (res == - 1)
        printf("oh no, we have problems with memory");

    
    print_struct(start);

    free(str);
    free(lexem);
}

    // char test_char = '-';
    // printf("symbol: %c\n", test_char);
    // printf("check for operator %d\n", check_for_operator(test_char));
    // printf("check for symbol %c\n", check_for_symbol(test_char));
    // test_char = '/';
    // printf("symbol: %c\n", test_char);
    // printf("check for operator %d\n", check_for_operator(test_char));
    // printf("check for symbol %c\n", check_for_symbol(test_char));
    // test_char = '+';
    // printf("symbol: %c\n", test_char);
    // printf("check for operator %d\n", check_for_operator(test_char));
    // printf("check for symbol %c\n", check_for_symbol(test_char));

    
    // lexem->type = NUM;
    // lexem->elem.num = 15;
    // push_lex(&lexem, OP, ADD, &flag);
    // stack* nums;
    //     if (lexem->type == NUM) {
    //         push(&nums, lexem->elem.num);
    //     }
    // push (&nums, 5);
    // push(&nums, 3);
    // printf("nums data %lf\nlexem %d %d\n",  nums->data, (FUNK)lexem->type, (FUNK)lexem->elem.func);
    // printf("operations %lf\n", operations(&nums,ADD,&flag));
