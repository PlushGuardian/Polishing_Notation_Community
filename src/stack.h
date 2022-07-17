#ifndef SRC_STACK_H_
#define SRC_STACK_H_
#include "graph.h"

// OPERATIONS FOR WORKING WITH STACK (USED IN CALCULATION FOR NUMBERS)
struct stack_node {
    double data;
    struct stack_node* next;
};

typedef struct stack_node stack;
stack* new_node(double data);
void push(stack** root, double data);
double pop(stack** root);

// OPERATIONS FOR WORKING WITH STRUCTURE (QUEUE OF OPERANDS AND OPERATIONS)
struct lexical_units {
    TYPE type;
    struct lexical_units* next;
    union {
        FUNK func;
        int num;
    } elem;
} ;
typedef struct lexical_units lex;

void push_lex(lex** root, TYPE type, double data, int *flag);
lex* new_node_funk(FUNK data);
lex* new_node_num(double data);
void pop_lex(lex** root); 

#endif  // SRC_STACK_H_