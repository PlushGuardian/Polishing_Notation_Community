#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "stack_and_struct.h"

lex* new_lex(FUNK func, double num) {
    lex* new_elem = (lex*)malloc(sizeof(lex));
    if (new_elem != NULL) {
        new_elem->func = func;
        if (num != -1)
            new_elem->num = num;
        new_elem->next = NULL;
    }
    return new_elem;
}

FUNK pop_func(lex** head) {
    lex* temp = *head;
    FUNK popped;
    if (temp != NULL) {
        popped = temp->func;
        *head = (*head)->next;
        free(temp);
    } else {
        popped = -1;
    }
    return popped;
}

FUNK pop_num(lex** head) {
    lex* temp = *head;
    FUNK popped;
    if (temp != NULL) {
        popped = temp->num;
        *head = (*head)->next;
        free(temp);
    } else {
        popped = -1;
    }
    return popped;
}

int push_to_head(lex** head, FUNK func, double num) {
    int res = 1;
    lex* new_elem = new_lex(func, num);
    if (new_elem != NULL) {
        new_elem->next = *head;
        *head = new_elem;
    } else {
        res = 0;
    }
    return res;
}

int push_to_tail(lex** tail, FUNK func, double num) {
    int res = 1;
    lex* new_elem = new_lex(func, num);
    if (new_elem != NULL) {
        (*tail)->next = new_elem;
        *tail = new_elem;
    } else {
        res = 0;
    }
    return res;
}
lex* return_to_head(lex* tail) {
    while (tail->prev != NULL)
        tail = tail->prev;
    return tail;
}

lex* shunting_yard(lex* head) {
    lex* reversed = NULL;
    lex* operators;
    while (head != NULL) {
        if (head->func == NUM || head->func == X) {
            push_to_tail(&reversed, head->func, head->num);
        } else {
            push_to_head(&operators, head->func, 0);
        }
    }
    while (operators != NULL) {
        push_to_tail(&reversed,pop_func(&operators), 0);
    }
    reversed = return_to_head(reversed);
    return (reversed);
}