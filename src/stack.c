#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

stack* new_node(int data) {
    stack* new_elem = (stack*)malloc(sizeof(stack));
    new_elem->data = data;
    new_elem->next = NULL;
    return new_elem;
}

void push(stack** top, int data) {
    stack* new_elem = new_node(data);
    new_elem->next = *top;
    *top = new_elem;
}

int pop(stack** top) {
    stack* temp = *top;
    int popped;
    if (temp != NULL) {
        popped = temp->data;
        *top = (*top)->next;
        free(temp);
    } else {
        popped = 0;
    }
    return popped;
}

void destroy(stack* root) {
    while (root != NULL) {
        stack* ptr = root->next;
        free(root);
        root = ptr;
    }
}
