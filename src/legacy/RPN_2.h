#ifndef SRC_RPN_2_H
#define SCR_RPN_2_H
#include "stack_and_struct.h"

lex* new_lex(elem data);
lex* add_to_tail(lex* head, elem new_unit, int* flag);
lex* add_to_head(lex* head, elem new_unit, int* flag);
lex* remove_lex(lex* head, int* flag);
lex* return_to_head(lex* tail) ;
lex* shunting_yard(lex* head) ;
void free_queue(lex** head) ;
int precedence(FUNK func);

#endif