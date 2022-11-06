#include "parsing_supplement.h"
#include "output_supplement.h"
#include "stack_and_struct.h"
#include "input_and_parse.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*---------------------------------------------------------
FUNCTIONS FOR DETERMINING DIFFERENT "TYPES" OF CHARS IN A STRING
---------------------------------------------------------*/

int check_for_function_letter(char ch) {
    int res = 0;
    if (ch == 'a' || ch == 'c' || ch == 'g' || ch == 'i' || ch == 'n')
        res = 1;
    if (ch == 'o' || ch == 'q' || ch == 'r' || ch == 's' || ch == 't')
        res = 1;
    return res;
}

int check_for_operator(char ch) {
    int res = 0;
    if (ch == '+' || ch == '*' || ch == '/')
        res = 1;
    return res;
}

int check_for_brackets(char ch) {
    int res = 0;
    if (ch == '(')
        res = -1;
    if (ch == ')')
        res = 1;
    return res;
}

int check_for_number(char ch) {
    int res = 0;
    if ((int)ch > 47 && (int)ch < 58)
        res = 1;
    return res;
}

char check_for_symbol(char ch) {
    char res = 'e';
    if (check_for_brackets(ch) == - 1)
        res = 'B';
    if (check_for_brackets(ch) == 1)
        res = 'b';
    if (check_for_number(ch) == 1)
        res = 'n';
    if (check_for_operator(ch) == 1) 
        res = 'o';        
    if (check_for_function_letter(ch) == 1)
        res = 'l';
    if (ch == '-')
        res = '-';
    if (ch == 'x')
        res = 'x';
    return res;
}

/*---------------------------------------------------------
    FUNCTIONS FOR COMPARING PREVIOUS AND CURRENT CHARS
---------------------------------------------------------*/


int complementing_types_of_units (LEX_TYPE prev_lex, LEX_TYPE cur_lex) {
    int res;
    switch (prev_lex) {
        case (L_BRACKET):
            switch (cur_lex) {
                case(L_BRACKET):
                case(FUNCTION):
                case(MINUS):
                case(NUMBER):
                    res = 1;
                    break;
                default:
                    res = 0;
                    break;
            }
            break;
        case (R_BRACKET):
        case (NUMBER):
            switch (cur_lex) {
                case(R_BRACKET):
                case(OPERATOR):
                case(MINUS):
                    res = 1;
                    break;
                default:
                    res = 0;
                    break;
            }
            break;
        case (FUNCTION):
            switch (cur_lex) {
                case(L_BRACKET):
                    res = 1;
                    break;
                default:
                    res = 0;
                    break;
            }
            break;
        case (OPERATOR):
        case (MINUS):
            switch (cur_lex) {
                case(L_BRACKET):
                case(FUNCTION):
                case(NUMBER):
                    res = 1;
                    break;
                default:
                    res = 0;
                    break;
            }
            break;
    }
    return res;
}

LEX_TYPE determine_current_type(FUNK elem) {
    LEX_TYPE res;
    switch (elem) {
        case (ADD):
        case (DIVIDE):
        case (MULTI):
            res = OPERATOR;
            break; 
        case (NEGATE):
        case (SUBTR):
            res = MINUS;
            break;
        case (SIN):
        case (COS):
        case (TAN):
        case (CTG):
        case (SQRT):
        case (LN):
            res = FUNCTION;
            break;
        case (L_BRACK):
            res = L_BRACKET;
            break;
        case (R_BRACK):
            res = R_BRACKET;
            break;
        case (NUM):
        case (X):
            res = NUMBER;
            break;
    } 
    return res;
}

/*---------------------------------------------------------
         FUNCTIONS FOR PARSING MULTICHAR OPERATORS
---------------------------------------------------------*/

char* add_elem_to_array(char* arr, int size, char elem, int* flag) {
    char* temp = realloc(arr, sizeof(char) * (size + 1));
    if (temp == NULL) {
        free(temp);
        *flag = -1;
    } else {
        arr = temp;
        arr[size] = elem;
    }
    return arr;
}

FUNK check_functions(char* func, int* flag) {
    FUNK res = SIN;
    if (strcmp(func, "sin") == 0)
        res = SIN;
    else if (strcmp(func, "cos") == 0)
        res = COS;
    else if (strcmp(func, "tan") == 0)
        res = TAN;
    else if (strcmp(func, "ctg") == 0)
        res = CTG;
    else if (strcmp(func, "sqrt") == 0)
        res = SQRT;
    else if (strcmp(func, "ln") == 0)
        res = LN;
    else
        *flag = 0;
    return res;
}

FUNK check_minus(LEX_TYPE last_lex) {
    FUNK res;
    if (last_lex == L_BRACKET || last_lex == START)
        res = NEGATE;
    else
        res = SUBTR;
    return res;
}