#include <stdio.h>
#include <stdlib.h>  // DYNAMIC MEMORY
#include "stack_and_struct.h"  // OPERATIONS WITH STRUCTURES
#include "input_and_parse.h"  
#include "parsing_supplement.h"  // COMPARING CHARACTERS IN PARSING
#include "output_supplement.h"

// THIS FUNCTION READS A STRING FROM STDIN AND DELETES ALL SPACES IN IT.
// IF THERE WERE ANY NYMBERS SEPARATED BY SPACE, IT WILL RETURN 0.
char* input_string(int *flag) {
    char ch;
    scanf("%c", &ch);
    char* res_str = calloc(1,sizeof(char));
    if (res_str == NULL) {
        free(res_str);
        *flag = -1;
        ch = '\n';
    }

    int size = 0, new_space_flag = 0, old_space_flag;
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

/* THIS FUNCTION CHECKS WHETHER THE INPUT STRING IS AN ACTUAL EQUATION TO BE SOLVED.
IT CHECKS THE STRING AFTER INPUT_STRING() SYMBOL BY SYMBOL AND CHECKS, WHETHER THE 
CURRENT SYMBOL (CUR_SYM) IS "COMPLEMENTARY" TO THE ONE BEFORE IT (PREV_SYM) OR NOT. FOR 
EXAMPLE, YOU CANNOT HAVE AN OPENING BRACKET AFTER A NUMBER, BUT YOU CAN HAVE A CLOSING 
ONE, SO THE FORMER ONE IS NOT COMPLEMENTARY AND THE LATTER ONE IS.
tHE RESULTING SYMBOLS ARE PUT IN A LIST OF STRUCTURES.
NUMBERS AND FUNCTION NAMES ARE STORED TEMPORARILY IN AN ARRAY, AND WHEN THEY END, THEY 
ARE PUT INTO THE FINAL LIST OF STRUCTURES.
THERE IS ALSO A CHECK THAT THE NUMBER OF CLOSING BRACKETS IS EQUAL TO THE NUMBER OF 
OPENING ONES.
PARSING SUPPLEMENT CONTAINS ALL THE COMPARISONS BETWEEN SYMBOLS.
*/
int parse(char* str, lex** queue) {
    char *num = calloc(1, sizeof(char));
    int i = 0, res = 1, len = 0, br_count = 0;
    if (num == NULL)
        res = 0;
    LEX_TYPE prev_sym = START, cur_sym;
    while (str[i] != '\0' && res == 1) {
        char cur_type = check_for_symbol(str[i]);
        res = res * complementing_types_of_units(prev_sym, cur_type);
        cur_sym = determine_current_type(cur_type);
        if (cur_sym == VAR)
            push_lex(queue, X, 1, &res);
        if (cur_sym == NUMBER || cur_sym == FUNCTION) {
            num = add_elem_to_array(num, len, str[i], &res);
            len++;
        }
        if ((prev_sym == NUMBER && cur_sym != NUMBER) || (cur_sym == NUMBER && str[i+1] == '\0')) {
            push_lex(queue, NUM, atoi(num), &res);
            free(num);
            num = (char*)calloc(1, sizeof(char));
            if (!num) {
                res = 0;
                break;
            }
            len = 0;
        }
        if (prev_sym == FUNCTION && cur_sym != FUNCTION) {
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
        if (cur_sym == L_BRACKET) {
            push_lex(queue, OP, L_BRACK, &res);
            br_count--;
        } 
        if (cur_sym == R_BRACKET) {
            push_lex(queue, OP, R_BRACK, &res);
            br_count++;
        }
        if (cur_sym == OPERATOR)
            push_lex(queue, OP, to_funk(str[i]), &res);
        if (cur_sym == VAR) 
            push_lex(queue, X, 1, &res);
        if (cur_sym == MINUS) {
            FUNK minus_type = check_minus(prev_sym);
            push_lex(queue, OP, minus_type, &res);
        }
        prev_sym = cur_sym;
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



