#include <stdio.h>
#include "structures.h"
#include "validation.h"
#include "output_supplement.h"
#include "shunting_yard.h"
#include "calculation.h"

lex* formula_1() ;
void validation_check(lex* head);

int main() {
    lex* head = formula_1();
    print_formula(head);
    validation_check(head);
    head = shunting_yard(head);
    print_formula(head);
    int flag = 1;
    double res = calculation(head, &flag, 0);
    printf("the result is: %f\n", res);
    free_list(head);
    return 0;
}

void validation_check(lex* head) {
    int flag;
    flag = validation(head);
    printf("is this a valid list?\n");
    if (flag) printf("yes\n");
    else printf("no\n");
}


lex* formula_1() {  //  3 + 4 × 2 ÷ (1 − 5)    3 4 2 * 1 5 - / +
    lex* primer;
    int flag = 1;
    elem unit;
    unit.func = L_BRACK;
    unit.num = -1;
    primer = new_lex(unit);
    unit.func = NUM;
    unit.num = 3;
    primer = add_to_tail(primer, unit, &flag);
    unit.func = ADD;
    unit.num = -1;
    primer = add_to_tail(primer, unit, &flag);
    unit.func = NUM;
    unit.num = 4;
    primer = add_to_tail(primer, unit, &flag);
    unit.func = MULTI;
    unit.num = -1;
    primer = add_to_tail(primer, unit, &flag);
    unit.func = NUM;
    unit.num = 2;
    primer = add_to_tail(primer, unit, &flag);
    unit.func = DIVIDE;
    unit.num = -1;
    primer = add_to_tail(primer, unit, &flag);
    unit.func = L_BRACK;
    unit.num = -1;
    primer = add_to_tail(primer, unit, &flag);
    unit.func = NUM;
    unit.num = 1;
    primer = add_to_tail(primer, unit, &flag);
    unit.func = SUBTR;
    unit.num = -1;
    primer = add_to_tail(primer, unit, &flag);
    unit.func = NUM;
    unit.num = 5;
    primer = add_to_tail(primer, unit, &flag);
    unit.func = R_BRACK;
    unit.num = -1;
    primer = add_to_tail(primer, unit, &flag);
    unit.func = R_BRACK;
    unit.num = -1;
    primer = add_to_tail(primer, unit, &flag);
    primer = return_to_head(primer);
    return primer;
}