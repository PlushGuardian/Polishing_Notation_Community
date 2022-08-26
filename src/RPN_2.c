#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "stack_and_struct.h"
#include "RPN_2.h"
#include "output_supplement.h"

lex* new_lex(FUNK func, double num) {
    lex* new_elem = (lex*)malloc(sizeof(lex));
    if (new_elem != NULL) {
        new_elem->func = func;
        if (num != -1)
            new_elem->num = num;
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

lex* add_to_head(lex* head, FUNK func, double num, int* flag) {
    lex* new_elem = new_lex(func, num);
    if (new_elem != NULL) {
        new_elem->next = head;
        head = new_elem;
    } else {
        *flag = 0;
    }
    return head;
}

lex* add_to_tail(lex* tail, FUNK func, double num, int* flag) {
    lex* new_elem = new_lex(func, num);
    if (new_elem != NULL) {
        tail->next = new_elem;
        new_elem->prev = tail;
        tail = new_elem;
    } else {
        *flag = 0;
    }
    return tail;
}

lex* return_to_head(lex* tail) {
    while (tail != NULL && tail->prev != NULL)
        tail = tail->prev;
    return tail;
}

lex* shunting_yard(lex* head) {
    lex* reversed = new_lex(NUM, -1);
    lex* operators = new_lex(NUM, -1);
    int count = 0;
    int flag = 1;
    while (head != NULL) {
        if (head->func == NUM || head->func == X) 
            reversed = add_to_tail(reversed, head->func, head->num, &flag);
        else
            operators = add_to_head(operators, head->func, 0, &flag);
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