#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "stack.h"
#include "graph.h"
#include "data_input.h"
#include "types_of_lexema.h"

char* input_string(int *flag) {
    char* res_str = (char*)malloc(sizeof(char));
    char ch;
    scanf("%c", &ch);
    int i = 0;
    int last_is_number = 0;
    while (ch != '\n') {
        if (ch != ' ')
            res_str[i] = ch;
        if (last_is_number != 1 && check_for_number(ch) == 1)
            *flag == 0;
        last_is_number = check_for_number(ch);
        i++;
        res_str = realloc(res_str, sizeof(char) * (i + 1));
        scanf("%c", &ch);
    }
    return res_str;
}

int parse(char* str, lex** queue) {
    lex* last = *queue;
    char cur_type;
    int i = 0, res = 1;
    LEX_TYPE last_lex = START;
    while (str[i] != '\0') {
        if (str[i] != ' '){
            cur_type = check_for_symbol(str[i]);
        }
        i++;
    }
    return res;
}

char check_for_symbol(char ch) {
    char res = ' ';
    if (check_for_brackets(ch) == 1)
        res = 'b';
    else if (check_for_brackets(ch) == - 1)
        res = 'B';
    else if (check_for_number(ch) == 1)
        res = 'n';
    else if (check_for_operator(ch))
        res = 'o';
    else if (check_for_function_letter(ch))
        res = 'l';
    else if (ch == '-')
        res = '-';
    else if (ch == 'x')
        res = 'x';
    else
        res = 'e';
    return res;
}

// int remove_spaces(char** str) {
//     int i = 0;
//     int is_number = 0;
//     while (str[i] != '\0')


// }

int complement_types_of_lexems (LEX_TYPE last_lex, char cur) {
    int res = 0;
    switch (last_lex) {
    case(START):
        if (cur == 'l' || cur == '-' || cur == 'n' || cur == 'B' || cur == 'x')
            res = 1;
    case(OPERATOR):
        if (cur == 'l' || cur == '-' || cur == 'n' || cur == 'B')
            res = 1;
    case(FUNCTION):
        if (cur == 'l' || cur == '-' || cur == 'n' || cur == 'B')
            res = 1;
    case(MINUS):
        if (cur == 'l' || cur == '-' || cur == 'n' || cur == 'B')
            res = 1;
    case(NUMBER):
        if (cur == 'l' || cur == '-' || cur == 'n' || cur == 'B')
            res = 1;
    case(L_BRACKET):
        if (cur == 'l' || cur == '-' || cur == 'n' || cur == 'B')
            res = 1;
    case(R_BRACKET):
        if (cur == 'l' || cur == '-' || cur == 'n' || cur == 'B')
            res = 1;
    case(X):
        if (cur == 'l' || cur == '-' || cur == 'n' || cur == 'B')
            res = 1;
    }
    return res;
}
