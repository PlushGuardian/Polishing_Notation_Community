#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

char* input_string() {
    char* res_str = (char*)malloc(sizeof(char));
    char ch = ' ';
    scanf("%c", &ch);
    int i = 0;
    while (ch != '\n') {
        res_str[i] = ch;
        scanf("%c", &ch);
        i++;
        res_str = realloc(res_str, sizeof(char) * (i + 1));
    }
    return res_str;
}


double calculate(lex)