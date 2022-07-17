#include "functions.h"
#include "stack.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calculate(lex* queue, double *res) {
    int flag = 1;
    stack* nums;
    while (queue) {
        if (queue->type == NUM) {
            push(&nums, queue->elem.num);
            pop_lex(&queue);
        } else {
            *res = operations(&nums, queue->elem.func, &flag);
            push(&nums, *res);
        }
        if (flag == 0) 
            break;
    }
    return flag;
}

double operations(stack** nums, FUNK oper, int* flag) {
    double res = 0;
    double temp;
    switch (oper) {
    case ADD:
        res = pop(nums) + pop(nums);
        break;
    case SUBTR:
        res = pop(nums) - pop(nums);
        break;
    case NEGATE:
        res = - pop(nums);
        break;
    case DIVIDE:
        res = pop(nums);
        temp = pop(nums);
        if (temp == 0)
            *flag = 0;
        else 
            res = res / temp;
        break;
    case MULTI:
        res = pop(nums) * pop(nums);
        break;
    case L_BRACK:
            printf("remove me, im in functions.c in operations");
        break;
    case R_BRACK:
            printf("remove me, im in functions.c in operations");
        break;
    case SIN:
        res = sin(pop(nums));
        break;
    case COS:
        res = cos(pop(nums));
        break;
    case TAN:
        temp = pop(nums);
        if (cos(temp) != 0) 
            res = tan(pop(nums));
        else
            *flag = 0;        
        break;
    case CTG:
        temp = pop(nums);
        if (sin(temp) != 0) 
            res = cos(temp)/sin(temp);
        else
            *flag = 0;   
        break;
    case SQRT:
        res = sqrt(pop(nums));
        break;
    case LN:
        res = log(pop(nums));
        break;
    }
    return res;
}
