#ifndef SRC_STACK_H_
#define SRC_STACK_H_
struct stack_node {
    int data;
    struct stack_node* next;
};

typedef struct stack_node stack;

stack* new_node(int data);
void push(stack** top, int data);
int pop(stack** top);
void destroy(stack* root);

#endif  // SRC_STACK_H_
