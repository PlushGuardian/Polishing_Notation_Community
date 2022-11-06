#include <stdio.h>
#include <stdlib.h>
#include "stack_and_struct.h"
#include "RPN_2.h"
#include "output_supplement.h"
#include "parsing_supplement.h"

int validation(lex* head) {
    int res = -1;
    LEX_TYPE prev_type, cur_type;
    if (head != NULL) {
        prev_type = determine_current_type(head->unit.func); 
        head = head->prev;
        res = 1;
    }
    while (head != NULL) {
        cur_type = determine_current_type(head->unit.func);
        res = res * complementing_types_of_units(prev_type, cur_type);
        prev_type = cur_type;
        head = head->prev;
    }
    return res;
}