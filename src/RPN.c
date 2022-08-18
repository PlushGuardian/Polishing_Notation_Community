#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "stack_and_struct.h"
#include "RPN.h"

struct lexical_units *Reverse_RPN(struct lexical_units *input) {
    struct lexical_units *temp_output;
    struct stack_for_output *Output_RPN = 0;
    struct stack_for_OP *stack = 0, *temp_stack;
    struct flags *flag;

    stack = (struct stack_for_OP*)malloc(sizeof(struct stack_for_OP));

    flag = (struct flags*)malloc(sizeof(struct flags));
    flag->flag3 = 0;
    flag->flag_1 = 0;

    // перебор полученной структуры
    temp_output = input;
    while (temp_output != NULL) {
        switch (temp_output->type) {
            // если число, то сразу занести в результат без обработки
            case NUM:
                add_to_output_from_lex(&Output_RPN, temp_output->elem.num, 0);
                break;
            case OP:
                RPN_op(temp_output, &stack, &Output_RPN, &flag);
                break;
            case X:
                
                add_to_output_from_lex(&Output_RPN, temp_output->elem.num, 1);
                break;
        }
        temp_output = temp_output->next;
    }
    //  вывод из стека оставшихся элементов в окончательный результат
    temp_stack = stack;
    while (temp_stack != NULL) {
        add_to_output_from_stack(&Output_RPN, pop_from_stack(&temp_stack));
        temp_stack = temp_stack->prev;
    }

    temp_output = copy_to_lex(Output_RPN);
    free(stack);
    free(temp_stack);
    free(Output_RPN);
    free(flag);

    return temp_output;
}


// выбор action для операнда
void RPN_op(
            struct lexical_units *lex,
            struct stack_for_OP **stack,
            struct stack_for_output **Output_RPN,
            struct flags **flag) {
    //printf("\nFunc:%d Precedence:%d\n", lex->elem.func, Precedence(lex->elem.func));
    switch (Precedence(lex->elem.func)) {
        case -1:  //  )
            while ((*stack)->func != 5) {
                add_to_output_from_stack(Output_RPN, pop_from_stack(stack));
            }
            pop_from_stack(stack);
            if ((*stack)->func == 7 || (*stack)->func == 8 || (*stack)->func == 9
                || (*stack)->func == 10 || (*stack)->func == 11 || (*stack)->func == 12) {
                    add_to_output_from_stack(Output_RPN, pop_from_stack(stack));
                }
            break;
        case 0:  //  (
            push_to_stack(stack, lex->elem.func);
            break;
        case 1:  //  sin, cos...
            push_to_stack(stack, lex->elem.func);
            (*flag)->flag_1 = 1;
            break;
        case 2:  //  +, -
            push_to_stack(stack, lex->elem.func);
            break;
        case 3:  //  *, /, NEGATE
            if ((*flag)->flag3 == 0) {
                push_to_stack(stack, lex->elem.func);
                (*flag)->flag3 = 1;
            } else {
                add_to_output_from_stack(Output_RPN, pop_from_stack(stack));
                push_to_stack(stack, lex->elem.func);
                (*flag)->flag3 = 0;
            }
            break;
    }
}

// определение к какой группе принадлежит операнд
int Precedence(FUNK func) {
    int result = -5;
    switch (func) {
        case ADD:
        case SUBTR:
            result = 2;
            break;
        case NEGATE:
        case DIVIDE:
        case MULTI:
            result = 3;
            break;
        case L_BRACK:
            result = 0;
            break;
        case R_BRACK:
            result = -1;
            break;
        case SIN:
        case COS:
        case TAN:
        case CTG:
        case SQRT:
        case LN:
            result = 1;
            break;
    }
    return result;
}