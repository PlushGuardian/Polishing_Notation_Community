#include <stdio.h>
#include <stdlib.h>  // DYNAMIC MEMORY
#include "stack_and_struct.h"  // OPERATIONS WITH STRUCTURES
#include "input_and_parse.h"  
#include "parsing_supplement.h"  // COMPARING CHARACTERS IN PARSING

// THIS FUNCTION READS A STRING FROM STDIN AND DELETES ALL SPACES IN IT.
// IF THERE WERE ANY NYMBERS SEPARATED BY SPACE, IT WILL RETURN 0.
char* input_string(int *flag) {
    char ch;
    scanf("%c", &ch);
    char* res_str = (char*)malloc(sizeof(char));
    if (res_str == NULL) {
        free(res_str);
        *flag = -1;
        ch = '\n';
    }
    int size = 0, new_space_flag = 0, old_space_flag = 0;
    int last_is_number = 0, cur_is_number = 0;
    while (ch != '\n') {
        if (ch != ' ') {
            old_space_flag = new_space_flag;
            new_space_flag = 0;
            res_str[size] = ch;
            size++;
            
            char* temp = realloc(res_str, sizeof(char) * (size + 1));
            if (temp == NULL) {
                free(temp);
                *flag = -1;
                break;
            } else {
                res_str = temp;
            }
            last_is_number = cur_is_number;
            cur_is_number = check_for_number(ch);
        } else {
            old_space_flag = new_space_flag;
            new_space_flag = 1;
        }
        
        if (last_is_number == 1 && check_for_number(ch) == 1 && old_space_flag == 1)
            *flag = 0;
        scanf("%c", &ch);
    }
    return res_str;
}


int parse(char* str, lex** queue) {
    char cur_type, *num = (char*)malloc(sizeof(char));
    int i = 0, res = 1, len = 0, br_count = 0;
    LEX_TYPE last_lex = START, cur_lex;
    while (str[i] != '\0' && res == 1) {
        cur_type = check_for_symbol(str[i]);
        res = res * complementing_types_of_units(last_lex, cur_type);
        cur_lex = determine_current_type(cur_type);
        if (cur_lex == NUMBER || cur_lex == FUNCTION) {
            num = add_elem_to_array(num, len, str[i], &res);
            len++;
        }
        if ((last_lex == NUMBER && cur_lex != NUMBER) || (cur_lex == NUMBER && str[i+1] == '\0')) {
            push_lex(queue, NUM, atoi(num), &res);
            free(num);
            num = (char*)calloc(1, sizeof(char));
            if (!num) {
                res = 0;
                break;
            }
            len = 0;
        }
        if (last_lex == FUNCTION && cur_lex != FUNCTION) {
            FUNK cur_function = check_functions(num, &res);
            if (res != 0)
                push_lex(queue, OP, cur_function, &res);
            free(num);
            num = (char*)calloc(1, sizeof(char)); 
            if (!num) {
                res = 0;
                break;
            }
            len = 0;
        }
        if (cur_lex == L_BRACKET) {
            push_lex(queue, OP, L_BRACK, &res);
            br_count--;
        }   
        if (cur_lex == R_BRACKET) {
            push_lex(queue, OP, R_BRACK, &res);
            br_count++;
        }
        if (cur_lex == OPERATOR)
            push_lex(queue, OP, to_funk(str[i]), &res);
        if (cur_lex == VAR)
            push_lex(queue, OP, X, &res);
        if (cur_lex == MINUS) {
            FUNK minus_type = check_minus(last_lex);
            push_lex(queue, OP, minus_type, &res);
        }
        last_lex = cur_lex;
        i++;
    }
    if (num != NULL)
        free(num);
    if (br_count != 0)
        res = 0;
    return res;
}

FUNK to_funk(char cur){
    FUNK res;
    switch (cur) {
        case '+':
        res = ADD;
        break;
        case '*':
        res = MULTI;
        break;
        case '/':
        res = DIVIDE;
        break;
    }
    return res;
}



