#ifndef SRC_TYPES_OF_LEXEMA_H_
#define SRC_TYPES_OF_LEXEMA_H_

#include "stack_and_struct.h"

// FUNCTIONS FOR DETERMINING DIFFERENT "TYPES" OF CHARS IN A STRING
int check_for_function_letter(char ch);
int check_for_operator(char ch);
int check_for_brackets(char ch);
int check_for_number(char ch);
char check_for_symbol(char ch);

// FUNCTIONS FOR COMPARING PREVIOUS AND CURRENT CHARS
int complementing_types_of_units (LEX_TYPE last_lex, char cur);
LEX_TYPE determine_current_type(char cur);

// FUNCTIONS FOR PARSING MULTICHAR OPERATORS
char* add_elem_to_array(char* arr, int size, char elem, int* flag);
FUNK check_functions(char* func, int* flag);
FUNK check_minus(LEX_TYPE last_lex);

#endif  // SRC_TYPES_OF_LEXEMA_H_
