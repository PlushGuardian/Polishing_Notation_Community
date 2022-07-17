#include "stack_and_struct.h"
#include <stdio.h>
#include <stdlib.h>
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
        else if (type == X)
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

/*---------------------------------------------------------
                FOR POLISH NOTATION
---------------------------------------------------------*/

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
    struct lexical_units *temp_lex = 0;
    struct stack_for_output *temp_RPN;

    temp_RPN = Output_RPN;

    //temp_lex = (struct lexical_units*)malloc(sizeof(struct lexical_units));
 
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
    if (Output_RPN->type == 3) {
        temp_lex->type = 3;
        temp_lex->elem.is_x = 1;
    }
    
    temp_lex->next = *root;  // next тут prev
    *root = temp_lex;
}

