#ifndef SRC_CALCULATION_H_
#define SRC_CALCULATION_H_
#include "stack_and_struct.h"

double operations(stack** nums, FUNK oper, int* flag);
int calculate(lex* queue, double *res, double x);

#endif    // SRC_CALCULATION_H_