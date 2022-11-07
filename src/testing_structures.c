#include <stdio.h>
#include "structures.h"
#include "validation.h"
#include "output_supplement.h"


int main() {
    elem unit;
    unit.func = 0;
    unit.num = -1;
    int flag = 1;
    lex* head = new_lex(unit);
    for (int i = 1; i < 15; i++) {
        unit.func = i;
        head = add_to_head(head, unit,&flag);
        if (flag == 0) break;
    }
    print_list(head);
    flag = validation(head);
    printf("is this a valid list?\n");
    if (flag) printf("yes\n");
    else printf("no\n");
    free_list(head);
    return 0;
}