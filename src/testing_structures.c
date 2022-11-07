#include <stdio.h>
#include "structures.h"
#include "output_supplement.h"

int main() {
    elem unit;
    unit.func = 0;
    unit.num = -1;
    lex* head = new_lex(unit);
    print_one_node(unit);
    print_list(head);
    free_list(head);
    return 0;
}