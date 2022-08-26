#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "stack_and_struct.h"
#include "RPN_2.h"
#include "output_supplement.h"

int main() {
    lex* test = new_lex(NUM, 3);
    print_one_node(test);
    int flag;
    test = add_to_tail(test, ADD, -1, &flag);
    print_one_node(test);
    test = add_to_tail(test, NUM, 2, &flag);
    print_one_node(test);
    test = return_to_head(test);
    print_struct(test);
    printf("------------------------\n");
    lex* rpn = shunting_yard(test);
    print_struct(rpn);
    free_queue(&test);
    free_queue(&rpn);
    return 0;
}