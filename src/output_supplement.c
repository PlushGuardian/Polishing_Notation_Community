#include "stack_and_struct.h"
#include "output_supplement.h"
#include <stdio.h>



void print_struct(lex* root) {
    int i = 0;
    while (root != NULL) {
        printf("Element %d:\n", i);
        print_one_node(root);
        // printf("address of next = %p\n", root->next);
        printf("\n");
        root = root->next;
        i++;
    }
}

void print_one_node(lex* root) {
    if (root->func == NUM) {
        printf("   %lf\n", root->num);
    }
    else {
        printf("   ");
        output_of_func(root->func);
        printf("\n");
    }

}

void output_of_type(int num) {
    switch (num){
        case 0:
        printf("NUM");
        break;
        case 1:
        printf("OP");
        break;
        case 2:
        printf("X");
        break;
    }
}

void output_of_lex_type(int num) {
    switch (num){
        case 0:
        printf("START");
        break;
        case 1:
        printf("OPERATOR");
        break;
        case 2:
        printf("FUNCTION");
        break;
        case 3:
        printf("MINUS");
        break;
        case 4:
        printf("NUMBER");
        break;
        case 5:
        printf("L_BRACKET");
        break;
        case 6:
        printf("R_BRACKET");
        break;
        case 7:
        printf("VAR");
        break;
        case 8:
        printf("X");
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
    }
}