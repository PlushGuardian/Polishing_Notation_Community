#include <stdio.h>
// #include "validation.h"
#include "structures.h"
#include "output_supplement.h"


void print_one_node(elem unit) {
    printf("TYPE OF NODE: ");
    output_of_func(unit.func);
    printf("\n");
    if (unit.func == NUM) printf("       VALUE: %f\n", unit.num);
}

void print_list(lex* head) {
    int count = 1;
    printf("+--------------------------------------+\n");
    while (head != NULL) {
        printf("~~~ELEMENT %d\n", count);
        print_one_node(head->unit);
        head = head->prev;
    }
    printf("+--------------------------------------+\n");
}

void print_formula(lex* head) {
    while (head != NULL) {
        if (head->unit.func == NUM) 
            printf("%.2f ", head->unit.num);
        else 
            print_element_of_formula(head->unit.func);
        head = head->prev;
    }
    printf("\n");
}

void print_formula_reverse(lex* head) {
    while (head != NULL) {
        if (head->unit.func == NUM) 
            printf("%.2f ", head->unit.num);
        else 
            print_element_of_formula(head->unit.func);
        head = head->next;
    }
    printf("\n");
}

void print_element_of_formula(int num) {
    switch (num){
        case 0:
        printf("+ ");
        break;
        case 1:
        printf("- ");
        break;
        case 2:
        printf("-");
        break;
        case 3:
        printf("/ ");
        break;
        case 4:
        printf("* ");
        break;
        case 5:
        printf("(");
        break;
        case 6:
        printf(")");
        break;
        case 7:
        printf("sin");
        break;
        case 8:
        printf("cos");
        break;
        case 9:
        printf("tan");
        break;
        case 10:
        printf("ctg");
        break;
        case 11:
        printf("sqrt");
        break;
        case 12:
        printf("ln");
        break;
        case 13:
        printf("x");
        break;
        default:
        printf("?");
        break;
    }
}

void output_of_func(int num) {
    switch (num){
        case 0:
        printf("ADD");
        break;
        case 1:
        printf("SUBTR");
        break;
        case 2:
        printf("NEGATE");
        break;
        case 3:
        printf("DIVIDE");
        break;
        case 4:
        printf("MULTI");
        break;
        case 5:
        printf("L_BRACKET");
        break;
        case 6:
        printf("R_BRACKET");
        break;
        case 7:
        printf("SIN");
        break;
        case 8:
        printf("COS");
        break;
        case 9:
        printf("TAN");
        break;
        case 10:
        printf("CTG");
        break;
        case 11:
        printf("SQRT");
        break;
        case 12:
        printf("LN");
        break;
        case 13:
        printf("X");
        break;
        case 14:
        printf("NUM");
        break;
    }
}

void output_of_lex_type(int num) {
    switch (num){
        case 0:
        printf("L_BRACKET");
        break;
        case 1:
        printf("R_BRACKET");
        break;
        case 2:
        printf("FUNCTION");
        break;
        case 3:
        printf("OPERATOR");
        break;
        case 4:
        printf("MINUS");
        break;
        case 5:
        printf("NUMBER");
        break;
    }
}
