
#include <math.h>
#include <stdlib.h>
#include "structures.h"
#include "calculation.h"

double calculation(lex* queue, int* flag, double x) {
    elem unit;
    unit.func = NUM;
    unit.num = -1;
    lex* stack = new_lex(unit);
    double res;
    while (queue && stack && (*flag)) {
        if (queue->unit.func == X) {
            queue->unit.num = x;
            queue->unit.func = NUM;
            stack = add_to_head(stack,queue->unit,*flag);
        } else if (queue->unit.func == NUM) {
            stack = add_to_head(stack,queue->unit,*flag);
        } else {
            unit.num = operations(&stack, queue->unit.func, flag);
            stack = add_to_head(stack, unit,*flag);
        }
        queue = queue->prev;
    }
    if (queue == NULL)
        res = stack->unit.num;
    free_list(stack);
    return res;

}

double operations(lex** stack, FUNK oper, int* flag) {
    double res = 0;
    double temp;
    switch (oper) {
    case ADD:
        res = pop(stack, flag) + pop(stack, flag);
        break;
    case SUBTR:
        res = pop(stack, flag) - pop(stack, flag);
        break;
    case NEGATE:
        res = - pop(stack, flag);
        break;
    case DIVIDE:
        res = pop(stack, flag);
        temp = pop(stack, flag);
        if (temp == 0)
            *flag = 0;
        else 
            res = res / temp;
        break;
    case MULTI:
        res = pop(stack, flag) * pop(stack, flag);
        break;
    case L_BRACK:
        *flag = 0;
        break;
    case R_BRACK:
        *flag = 0;
        break;
    case SIN:
        res = sin(pop(stack, flag));
        break;
    case COS:
        res = cos(pop(stack, flag));
        break;
    case TAN:
        temp = pop(stack, flag);
        if (cos(temp) != 0) 
            res = tan(pop(stack, flag));
        else
            *flag = 0;        
        break;
    case CTG:
        temp = pop(stack, flag);
        if (sin(temp) != 0) 
            res = cos(temp)/sin(temp);
        else
            *flag = 0;   
        break;
    case SQRT:
        res = sqrt(pop(stack, flag));
        break;
    case LN:
        res = log(pop(stack, flag));
        break;
    }
    return res;
}