#include "calculation.h"
#include "stack_and_struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calculate(lex* queue, double *res, double x) {
    int flag = 1;
    x = x*1;
    stack* nums;
    while (queue) {
        if (queue->type == NUM) {
            push(&nums, queue->elem.num);
            
        } else if (queue->type == OP) {
            *res = operations(&nums, queue->elem.func, &flag);
            if (flag == 0) 
                break;
            push(&nums, *res);
        } else {
           
            push(&nums, x);
        }
        pop_lex(&queue);
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
        *flag = 0;
        break;
    case R_BRACK:
        *flag = 0;
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
