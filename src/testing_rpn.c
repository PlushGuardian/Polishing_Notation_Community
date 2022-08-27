#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "stack_and_struct.h"
#include "RPN_2.h"
#include "output_supplement.h"

int main() { //  3 + 4 × 2 ÷ ( 1 − 5 )
    lex* test = new_lex(NUM, 3);
    int flag;
    test = add_to_tail(test, ADD, -1, &flag);
    test = add_to_tail(test, NUM, 4, &flag);
    test = add_to_tail(test, MULTI, -1, &flag);
    test = add_to_tail(test, NUM, 2, &flag);
    test = add_to_tail(test, DIVIDE, -1, &flag);
    test = add_to_tail(test, L_BRACK, -1, &flag);
    test = add_to_tail(test, NUM, 1, &flag);
    test = add_to_tail(test, SUBTR, -1, &flag);
    test = add_to_tail(test, NUM, 5, &flag);
    test = add_to_tail(test, R_BRACK, -1, &flag);
    test = return_to_head(test);
    print_struct(test);
    printf("------------------------\n");
    lex* rpn = shunting_yard(test);
    print_struct(rpn);
    free_queue(&test);
    free_queue(&rpn);
    return 0;
}