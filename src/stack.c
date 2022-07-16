#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
//#include "functions.h"
#include "graph.h"
#include "data_input.h"

stack* new_node(double data) {
    stack* new_elem = (stack*)malloc(sizeof(stack));
    new_elem->data = data;
    new_elem->next = NULL;
    return new_elem;
}

void push(stack** root, double data) {
    stack* new_elem = new_node(data);
    new_elem->next = *root;
    *root = new_elem;
}

double pop(stack** root) {
    stack* temp = *root;
    double popped;
    if (temp != NULL) {
        popped = temp->data;
        *root = (*root)->next;
        free(temp);
    } else {
        popped = 0;
    }
    return popped;
}

lex* new_node_funk(FUNK data) {
    lex* new_elem = (lex*)malloc(sizeof(lex));
    new_elem->elem.func = data;
    new_elem->next = NULL;
    return new_elem;
}

lex* new_node_num(double data) {
    lex* new_elem = (lex*)malloc(sizeof(lex));
    new_elem->elem.num = data;
    new_elem->next = NULL;
    return new_elem;
}

void push_lex(lex** root, TYPE type, double data) {
    lex* new_elem;
    if (type == NUM)
        new_elem = new_node_num(data);
    else
        new_elem = new_node_funk(data);
    new_elem->next = *root;
    data = data*1;
    *root = new_elem;
}

void pop_lex(lex** root) {
    lex* temp = *root;
    if (temp != NULL) {
        *root = (*root)->next;
        free(temp);
    }
}


