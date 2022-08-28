#include "parsing_test.h"
#include <string.h>

int main(){
  char * string = "SIN(x) - 4 / tg(x) + (3-20*2)/4";
  char string_result[strlen(string)+2];
  printf("%s\n", string);
  preparing_string(string, string_result);
  printf("%s\n", string_result);
}