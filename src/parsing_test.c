#include "parsing_test.h"
#include <string.h>

int main(){
  char * string = "ssd egge ss f   fs4e gh hre e";
  char string_result[strlen(string)];
  printf("%s\n", string);
  preparing_string(string, string_result);
  printf("%s\n", string_result);
}