#include "types_of_lexema.h"


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
    if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4')
        res = 1;
    if (ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9')
        res = 1;
    return res;
}


//+ - * / 


//sin, cos, tan, ctg, sqrt, ln