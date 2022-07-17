#include "stack_and_struct.h"
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "input_and_parse.h" 

/*---------------------------------------------------------
OPERATIONS FOR WORKING WITH STACK (USED IN CALCULATION FOR NUMBERS)
---------------------------------------------------------*/

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

/*---------------------------------------------------------
OPERATIONS FOR WORKING WITH STRUCTURE (QUEUE OF OPERANDS AND OPERATIONS)
---------------------------------------------------------*/

lex* new_node_lex() {
    lex* new_elem = (lex*)malloc(sizeof(lex));
    new_elem->next = NULL;
    return new_elem;
}

void push_lex(lex** root, TYPE type, double data, int *flag) {
    lex* new_elem = new_node_lex();
    if (new_elem == NULL) {
        *flag = -1;
        free(new_elem);
    } else {
        new_elem->type = type;
        if (type == NUM)
            new_elem->elem.num = data;
        else if (type == OP)
            new_elem->elem.func = data;
        else 
            new_elem->elem.is_x = data;    
        new_elem->next = *root;
        *root = new_elem;
    }
    
}

void pop_lex(lex** root) {
    lex* temp = *root;
    if (temp != NULL) {
        *root = (*root)->next;
        free(temp);
    }
}

lex* slide_lex(lex* elem, TYPE type, double data, int *flag) {
    printf("we have trouble");
    lex* new_elem = (lex *)malloc(sizeof(lex));
    printf("we have trouble");
    if (new_elem != NULL) {
        new_elem->next = NULL;
        elem->next = new_elem;
        new_elem->type = type;
        if (type == NUM) 
            new_elem->elem.num = data;
        if (type == OP) 
            new_elem->elem.func = data;
    } else {
        *flag = -1;
        printf("we have trouble");
    }
    return new_elem;
}

int reverse_stack(lex** old, lex** new) {
    int res = 1;
    while(*old && res) {
        if ((*old)->type == NUM)
            push_lex(new,(*old)->type,(*old)->elem.num, &res);
        if ((*old)->type == OP)
            push_lex(new,(*old)->type,(*old)->elem.func, &res);
        if ((*old)->type == X)
            push_lex(new,(*old)->type,(*old)->elem.is_x, &res);
        pop_lex(old);
    }
    return res;
}
