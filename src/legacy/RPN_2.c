#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "stack_and_struct.h"
#include "RPN_2.h"
#include "output_supplement.h"

// add dot to parsing
// add ) ( case to parsing

lex* new_lex(elem data) {
    lex* new_elem = (lex*)malloc(sizeof(lex));
    if (new_elem != NULL) {
        new_elem->unit.func = data.func;
        if (data.num != -1)
            new_elem->unit.num = data.num;
        new_elem->next = NULL;
        new_elem->prev = NULL;
    }
    return new_elem;
}

lex* remove_lex(lex* head, int* flag) {
    if (head != NULL) {
        head = head->next;
        free(head->prev);
        head->prev = NULL;
    } else {
        *flag = 0;
    }
    return head;
}

lex* add_to_head(lex* head, elem new_unit, int* flag) {
    lex* new_elem = new_lex(new_unit);
    if (new_elem != NULL) {
        new_elem->prev = head;
        head = new_elem;
    } else {
        *flag = 0;
    }
    return head;
}

lex* add_to_tail(lex* tail, elem new_unit, int* flag) {
    lex* new_elem = new_lex(new_unit);
    if (new_elem != NULL) {
        tail->prev = new_elem;
        new_elem->next = tail;
        tail = new_elem;
    } else {
        *flag = 0;
    }
    return tail;
}

lex* return_to_head(lex* tail) {
    while (tail != NULL && tail->next != NULL)
        tail = tail->next;
    return tail;
}

lex* shunting_yard(lex* head) {
    lex* reversed = new_lex(NUM, -1);
    lex* operators = new_lex(NUM, -1);
    int flag = 1, count = 0;
    while (head != NULL) {
        printf("REPEAT %d \n", count);
        count++;
        print_one_node(head);
        printf("these are operators\n");
        print_struct(operators);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        switch (head->func) {
            case NUM:
            case X:
                reversed = add_to_tail(reversed, head->func, head->num, &flag);
                break; 
            case R_BRACK:
                while(operators != NULL && operators->func != L_BRACK) {
                    reversed = add_to_tail(reversed,operators->func, -1, &flag);
                    operators = remove_lex(operators, &flag);
                }
                operators = remove_lex(operators, &flag);
                break;
            case L_BRACK:
                operators = add_to_head(operators, head->func, -1, &flag);
                break;
            default:
                if  (precedence(head->func) <= precedence(operators->func)) {
                    reversed = add_to_tail(reversed,operators->func, -1, &flag);
                    operators = remove_lex(operators, &flag);
                    operators = add_to_head(operators, head->func, -1, &flag);
                } else {
                    operators = add_to_head(operators, head->func, -1, &flag);
                }
                break;
        }
        head = head->next;
    }
    while (operators != NULL && operators->next != NULL) {
        reversed = add_to_tail(reversed,operators->func, -1, &flag);
        operators = remove_lex(operators, &flag);
    }
    reversed = return_to_head(reversed);
    if (operators != NULL)
        free(operators);
    reversed = reversed->next;
    free(reversed->prev);    
    return (reversed);
}

void free_queue(lex** head) {
    lex* temp = *head;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
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
    }
    return result;
}