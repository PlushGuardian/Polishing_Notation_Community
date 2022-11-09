#include "structures.h"
#include "shunting_yard.h"
#include <stdlib.h>
#include <stdio.h>
#include "output_supplement.h"

lex* shunting_yard(lex* head) {
    elem primer;
    primer.func = NUM;
    primer.num = -1;
    int flag = 1;
    lex* res = new_lex(primer);
    lex* oper = new_lex(primer);

    while (head != NULL && flag) {
        print_formula_reverse(res);
        if (head->unit.func == NUM || head->unit.func == X) {
            res = add_to_tail(res, head->unit, &flag);
        } else if (head->unit.func == L_BRACK) {
            oper = add_to_head(oper, head->unit, &flag);
        } else if (head->unit.func == R_BRACK) {
            printf("~\n");
            while (oper != NULL && oper->unit.func != L_BRACK && flag) {
                res = add_to_tail(res, oper->unit, &flag);
                oper = remove_lex(oper, &flag);
                printf("~\n");
            }
            oper = remove_lex(oper, &flag);
            if (oper != NULL && check_for_func(oper->unit.func)) {
                res = add_to_tail(res, oper->unit, &flag);
                oper = remove_lex(oper, &flag);
            }
        } else {
            int prec_head = precedence(head->unit.func), prec_stack = precedence(oper->unit.func);
            printf("precedence: operator %d  queue %d\n", prec_stack, prec_head);
            while (prec_stack >= prec_head && oper != NULL && flag) {
                res = add_to_tail(res, oper->unit, &flag);
                oper = remove_lex(oper, &flag);
                prec_stack = precedence(oper->unit.func);
            }
            oper = add_to_head(oper, head->unit, &flag);
        }
        head = remove_lex(head, &flag);
    }

    if (oper != NULL) free_list(oper);
    res = return_to_head(res);
    print_formula(res);
    res = remove_lex(res, &flag); // remove primer
    return res;
}

/*
    - a number:
        put it into the output queue
    - a left parenthesis (i.e. "("):
        push it onto the operator stack
    - an operator o1:
        while (
            there is an operator o2 other than the left parenthesis at the top
            of the operator stack, and (o2 has greater precedence than o1)
        ):
            pop o2 from the operator stack into the output queue
        push o1 onto the operator stack

    - a right parenthesis (i.e. ")"):
        while the operator at the top of the operator stack is not a left parenthesis:
            {assert the operator stack is not empty}
            pop the operator from the operator stack into the output queue
        {assert there is a left parenthesis at the top of the operator stack}
        pop the left parenthesis from the operator stack and discard it
        if there is a function token at the top of the operator stack, then:
            pop the function from the operator stack into the output queue
*/

int check_for_func(FUNK func) {
    int result;
    switch (func) {
        case SIN:
        case COS:
        case TAN:
        case CTG:
        case SQRT:
        case LN:
            result = 1;
            break;
        default:
            result = 0;
            break;
    }
    return result;
}


int precedence(FUNK func) {
    int result;
    switch (func) {
        case SIN:
        case COS:
        case TAN:
        case CTG:
        case SQRT:
        case LN:
            result = 1;
            break;
        case ADD:
        case SUBTR:
            result = 2;
            break;
        case NEGATE:
        case DIVIDE:
        case MULTI:
            result = 3;
            break;
        default:
            result = 0;
            break;
        // case SIN:
        // case COS:
        // case TAN:
        // case CTG:
        // case SQRT:
        // case LN:
        //     result = 1;
        //     break;
        // case ADD:
        // case SUBTR:
        //     result = 2;
        //     break;
        // case NEGATE:
        // case DIVIDE:
        // case MULTI:
        //     result = 3;
        //     break;
        // default:
        //     result = 0;
        //     break;
    }
    return result;
}