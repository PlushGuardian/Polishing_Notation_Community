#ifndef SRC_STACK_H_
#define SRC_STACK_H_
struct stack_node {
    double data;
    struct stack_node* next;
};

typedef struct stack_node stack;

stack* new_node(double data);
void push(stack** root, double data);
double pop(stack** root);
void push_lex(lex** root, TYPE type, double data);
lex* new_node_funk(FUNK data);
lex* new_node_num(double data);
void pop_lex(lex** root); 


#endif  // SRC_STACK_H_




// #ifndef SRC_STACK_H_
// #define SRC_STACK_H_

// lex* new_node(double data);
// void push(lex** root, double data);
// double pop(lex** root);
// void destroy(lex* root);

// #endif  // SRC_STACK_H_
