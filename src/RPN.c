#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "stack.h"
#include "graph.h"
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

// занести в окончательный результат из стека
void add_to_output_from_stack(struct stack_for_output **root, double item) {
    struct stack_for_output *temp;
    temp = (struct stack_for_output*)malloc(sizeof(struct stack_for_output));
    temp->func = item;
    temp->type = 1;
    temp->prev = *root;

    *root = temp;
}

// занести в окончательный результат из структуры
void add_to_output_from_lex(struct stack_for_output **root, int item, int is_x) {
    struct stack_for_output *temp;
    temp = (struct stack_for_output*)malloc(sizeof(struct stack_for_output));
    if (is_x) {
        temp->is_x = 1;
        temp->type = 3;
    } else {
        temp->num = item;
        temp->type = 0;
    }
    temp->prev = *root;

    *root = temp;
}

// достать из стека
double pop_from_stack(struct stack_for_OP **root) {
    double result;
    result = (*root)->func;
    if ((*root)->prev)
        *root = (*root)->prev;
    return result;
}

// положить в стек
void push_to_stack(struct stack_for_OP **root, double item) {
    struct stack_for_OP *temp;
    temp = (struct stack_for_OP*)malloc(sizeof(struct stack_for_OP));
    temp->func = item;

    temp->prev = *root;
    *root = temp;
}

// переделать из стека в список
struct lexical_units* copy_to_lex(struct stack_for_output *Output_RPN) {
    struct lexical_units *temp_lex;
    struct stack_for_output *temp_RPN;

    temp_RPN = Output_RPN;

    temp_lex = (struct lexical_units*)malloc(sizeof(struct lexical_units));
    if (Output_RPN->type == 1) {
        temp_lex->type = 1;
        temp_lex->elem.func = Output_RPN->func;
    }
    if (Output_RPN->type == 0) {
        temp_lex->type = 0;
        temp_lex->elem.num = Output_RPN->num;
    }
    if (Output_RPN->type == 3) {
        temp_lex->type = 3;
        temp_lex->elem.is_x = 1;
    }
    temp_RPN = temp_RPN->prev;
    
    while (temp_RPN) {
        add_to_struct(&temp_lex, temp_RPN);
        temp_RPN = temp_RPN->prev;
    }
    
    return temp_lex;
}

void add_to_struct(struct lexical_units **root, struct stack_for_output *Output_RPN) {
    struct lexical_units *temp_lex;

    temp_lex = (struct lexical_units*)malloc(sizeof(struct lexical_units));

    if (Output_RPN->type == 1) {
        temp_lex->type = 1;
        temp_lex->elem.func = Output_RPN->func;
    }
    if (Output_RPN->type == 0) {
        temp_lex->type = 0;
        temp_lex->elem.num = Output_RPN->num;
    }
    
    temp_lex->next = *root;  // next тут prev
    *root = temp_lex;
}


// создание тестовой структуры типа lexical_units
struct lexical_units *generate_test_lex() {
    struct lexical_units *test_lex, *start;

{
    test_lex = (struct lexical_units*)malloc(sizeof(struct lexical_units));
    start = test_lex;
    test_lex->type = 0;
    test_lex->elem.num = 3;
    test_lex->next = (struct lexical_units*)malloc(sizeof(struct lexical_units));;
}
{
    test_lex = test_lex->next;
    test_lex->type = 1;
    test_lex->elem.func = ADD;
    test_lex->next = (struct lexical_units*)malloc(sizeof(struct lexical_units));
}
{
    test_lex = test_lex->next;
    test_lex->type = 0;
    test_lex->elem.num = 4;
    test_lex->next = (struct lexical_units*)malloc(sizeof(struct lexical_units));
}
{
    test_lex = test_lex->next;
    test_lex->type = 1;
    test_lex->elem.func = MULTI;
    test_lex->next = (struct lexical_units*)malloc(sizeof(struct lexical_units));
}
{
    test_lex = test_lex->next;
    test_lex->type = 0;
    test_lex->elem.num = 2;
    test_lex->next = (struct lexical_units*)malloc(sizeof(struct lexical_units));
}
{
    test_lex = test_lex->next;
    test_lex->type = 1;
    test_lex->elem.func = DIVIDE;
    test_lex->next = (struct lexical_units*)malloc(sizeof(struct lexical_units));
}
{
    test_lex = test_lex->next;
    test_lex->type = 1;
    test_lex->elem.func = L_BRACK;
    test_lex->next = (struct lexical_units*)malloc(sizeof(struct lexical_units));
}
{
    test_lex = test_lex->next;
    test_lex->type = 0;
    test_lex->elem.num = 1;
    test_lex->next = (struct lexical_units*)malloc(sizeof(struct lexical_units));
}
{
    test_lex = test_lex->next;
    test_lex->type = 1;
    test_lex->elem.func = SUBTR;
    test_lex->next = (struct lexical_units*)malloc(sizeof(struct lexical_units));
}
{
    test_lex = test_lex->next;
    test_lex->type = 0;
    test_lex->elem.num = 5;
    test_lex->next = (struct lexical_units*)malloc(sizeof(struct lexical_units));
}
{
    test_lex = test_lex->next;
    test_lex->type = 1;
    test_lex->elem.func = R_BRACK;
    test_lex->next = NULL;
}
    return start;
}

// создание тестовой структуры типа lexical_units
struct lexical_units *generate_test_lex_sin() {
    struct lexical_units *test_lex, *start;

{
    test_lex = (struct lexical_units*)malloc(sizeof(struct lexical_units));
    start = test_lex;
    test_lex->type = 1;
    test_lex->elem.num = SIN;
    test_lex->next = (struct lexical_units*)malloc(sizeof(struct lexical_units));;
}
{
    test_lex = test_lex->next;
    test_lex->type = 1;
    test_lex->elem.func = L_BRACK;
    test_lex->next = (struct lexical_units*)malloc(sizeof(struct lexical_units));
}
{
    test_lex = test_lex->next;
    test_lex->type = 1;
    test_lex->elem.num = SQRT;
    test_lex->next = (struct lexical_units*)malloc(sizeof(struct lexical_units));
}
{
    test_lex = test_lex->next;
    test_lex->type = 1;
    test_lex->elem.func = L_BRACK;
    test_lex->next = (struct lexical_units*)malloc(sizeof(struct lexical_units));
}
{
    test_lex = test_lex->next;
    test_lex->type = 0;
    test_lex->elem.num = 2;
    test_lex->next = (struct lexical_units*)malloc(sizeof(struct lexical_units));
}
{
    test_lex = test_lex->next;
    test_lex->type = 1;
    test_lex->elem.func = R_BRACK;
    test_lex->next = (struct lexical_units*)malloc(sizeof(struct lexical_units));
}
{
    test_lex = test_lex->next;
    test_lex->type = 1;
    test_lex->elem.func = DIVIDE;
    test_lex->next = (struct lexical_units*)malloc(sizeof(struct lexical_units));
}
{
    test_lex = test_lex->next;
    test_lex->type = 0;
    test_lex->elem.num = 3;
    test_lex->next = (struct lexical_units*)malloc(sizeof(struct lexical_units));
}
{
    test_lex = test_lex->next;
    test_lex->type = 1;
    test_lex->elem.func = MULTI;
    test_lex->next = (struct lexical_units*)malloc(sizeof(struct lexical_units));
}
{
    test_lex = test_lex->next;
    test_lex->type = 0;
    test_lex->elem.num = 9;
    test_lex->next = (struct lexical_units*)malloc(sizeof(struct lexical_units));
}
    return start;
}

// // вывод структуры
// void output(struct lexical_units *lex) {
//     struct lexical_units *temp;

//     temp = lex;
//     while (temp != NULL) {
//         if (temp->type == 0) {
//             printf("%d", temp->elem.num);
//         }
//         if (temp->type == 1) {
//             printf("|%d|", temp->elem.func);
//         }
//         printf(" ");
//         temp = temp->next;
//     }
// }
