#include <stdio.h>
#include <stdlib.h>
#include "validation.h"
#include "structures.h"

int validation(lex* head) {
    int res = -1, bracket_count = 0;
    LEX_TYPE prev_type, cur_type;
    if (head != NULL) {
        prev_type = determine_current_type(head->unit.func); 
        head = head->prev;
        res = 1;
    }
    while (head != NULL) {
        cur_type = determine_current_type(head->unit.func);
        res = res * complementing_types_of_units(prev_type, cur_type);
        if (head->unit.func == L_BRACKET) bracket_count--;
        if (head->unit.func == R_BRACKET) bracket_count++;
        prev_type = cur_type;
        head = head->prev;
    }
    if (bracket_count != 0) res = 0;
    return res;
}


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
