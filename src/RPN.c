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
        }
        temp_output = temp_output->next;
    }

    //  вывод из стека оставшихся элементов в окончательный результат
    temp_stack = stack;
    while (temp_stack != NULL) {
        if (Output_RPN)
            add_to_output_from_stack(&Output_RPN, pop_from_stack(&temp_stack));
        temp_stack = temp_stack->prev;
    }

    temp_output = copy_to_lex(Output_RPN);

    printf("\n");
    struct stack_for_output *lex_from_stack;
    lex_from_stack = Output_RPN;
    while (lex_from_stack != NULL) {
        if (lex_from_stack->type == 0) {
            printf("%d", lex_from_stack->num);
        }
        if (lex_from_stack->type == 1) {
            printf("|%f|", lex_from_stack->func);
        }
        printf(" ");
        lex_from_stack = lex_from_stack->prev;
    }
    //output(temp_output);
    printf("\n\n\n\n\n");

    free(stack);
    free(Output_RPN);

    return temp_output;
}

// выбор action для операнда
void RPN_op(
            struct lexical_units *lex,
            struct stack_for_OP **stack,
            struct stack_for_output **Output_RPN,
            struct flags **flag) {
    switch (Precedence(lex->elem.func)) {
        case -1:  //  )
            while ((*stack)->func != 5) {
                add_to_output_from_stack(Output_RPN, pop_from_stack(stack));
            }
            if ((*flag)->flag_1 == 0) {
                printf("-1f0:%d ", lex->elem.func);
                pop_from_stack(stack);
            } else {
                printf("-1f1:%d ", lex->elem.func);
                pop_from_stack(stack);
                add_to_output_from_stack(Output_RPN, pop_from_stack(stack));
                (*flag)->flag_1--;
            }
            break;
        case 0:  //  (
            printf("0:%d ", lex->elem.func);
            push_to_stack(stack, lex->elem.func);
            break;
        case 1:  //  sin, cos...
            printf("1:%d ", lex->elem.func);
            push_to_stack(stack, lex->elem.func);
            (*flag)->flag_1++;
            break;
        case 2:  //  +, -
            printf("2:%d ", lex->elem.func);
            push_to_stack(stack, lex->elem.func);
            break;
        case 3:  //  *, /, NEGATE
            if ((*flag)->flag3 == 0) {
                printf("3f0:%d ", lex->elem.func);
                push_to_stack(stack, lex->elem.func);
                (*flag)->flag3 = 1;
            } else {
                printf("3f1:%d ", lex->elem.func);
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

