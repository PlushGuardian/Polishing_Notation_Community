#ifndef SRC_RPN_2_H
#define SCR_RPN_2_H
#include "stack_and_struct.h"

lex* new_lex(FUNK func, double num);
lex* add_to_tail(lex* tail, FUNK func, double num, int* flag);
lex* add_to_head(lex* head, FUNK func, double num, int* flag);
lex* remove_lex(lex* head, int* flag);
lex* return_to_head(lex* tail) ;
lex* shunting_yard(lex* head) ;
void free_queue(lex** head) ;

#endif