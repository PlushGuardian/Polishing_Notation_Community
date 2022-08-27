#ifndef POLISH_SRC_PARSING_H_
#define POLISH_SRC_PARSING_H_

#include <string.h>

typedef struct tmp_var{
  char string[8];
  int n;
  int x;
}Tmp;

int check_char(char ch);
void preparing_string(char * str, char *str_res);
#endif //POLISH_SRC_PARSING_H_
