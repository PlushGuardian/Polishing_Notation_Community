#include <stdio.h>
#include <stdlib.h>

char* input_string(int *flag);
int check_for_number(char ch);

int main() {
    int flag = 1;
    char * str = input_string(&flag);
    if (flag == 0)
        printf("your input is shit\n");
    else
        printf("string %s\n" , str);
}

char* input_string(int *flag) {
    char ch;
    scanf("%c", &ch);
    char* res_str = (char*)malloc(sizeof(char));
    if (res_str == NULL) {
        free(res_str);
        *flag = -1;
        ch = '\n';
    }
    int size = 0;
    int last_is_number = 0;
    while (ch != '\n') {
        if (ch != ' ') {
            res_str[size] = ch;
            last_is_number = check_for_number(ch);
            size++;
            char* temp = realloc(res_str, sizeof(char) * (size + 1));
            if (res_str == NULL) {
                free(temp);
                *flag = -1;
                break;
            } else {
                res_str = temp;
            }
        }
        if (last_is_number == 1 && check_for_number(ch) == 1)
            *flag = 0;
        scanf("%c", &ch);
    }
    return res_str;
}

int check_for_number(char ch) {
    int res = 0;
    if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4')
        res = 1;
    if (ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9')
        res = 1;
    return res;
}



    // char test_char = '-';
    // printf("symbol: %c\n", test_char);
    // printf("check for operator %d\n", check_for_operator(test_char));
    // printf("check for symbol %c\n", check_for_symbol(test_char));
    // test_char = '/';
    // printf("symbol: %c\n", test_char);
    // printf("check for operator %d\n", check_for_operator(test_char));
    // printf("check for symbol %c\n", check_for_symbol(test_char));
    // test_char = '+';
    // printf("symbol: %c\n", test_char);
    // printf("check for operator %d\n", check_for_operator(test_char));
    // printf("check for symbol %c\n", check_for_symbol(test_char));

    
    // lexem->type = NUM;
    // lexem->elem.num = 15;
    // push_lex(&lexem, OP, ADD, &flag);
    // stack* nums;
    //     if (lexem->type == NUM) {
    //         push(&nums, lexem->elem.num);
    //     }
    // push (&nums, 5);
    // push(&nums, 3);
    // printf("nums data %lf\nlexem %d %d\n",  nums->data, (FUNK)lexem->type, (FUNK)lexem->elem.func);
    // printf("operations %lf\n", operations(&nums,ADD,&flag));