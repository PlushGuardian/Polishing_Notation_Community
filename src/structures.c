#include "structures.h"
#include <stdlib.h>

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

int free_list(lex* head) {
    int res = 1;
    if (head == NULL) res = 0;
    while (head != NULL && res != 0) 
        head = remove_lex(head, &res);
    return res;
}