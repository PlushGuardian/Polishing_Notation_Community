#include <stdio.h>
#include "validation.h"
#include "structures.h"
#include "output_supplement.h"


void print_one_node(lex* head) {
    printf("TYPE OF NODE: ");
    output_of_func(head->unit.func);
    printf("\n");
    if (head->unit.func == NUM) printf("       VALUE: %d\n", head->unit.num);
}

void print_list(lex* head) {
    int count = 1;
    printf("+--------------------------------------+\n");
    while (head != NULL) {
        printf("\n~~~ELEMENT %d\n", count);
        print_one_node(head);
        head = head->prev;
    }
    printf("+--------------------------------------+\n");
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
