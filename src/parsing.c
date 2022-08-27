#include "parsing.h"

#include <stdio.h>

void preparing_string(char * str, char * str_res){
  int str_n = 0;
  for(;*str;str++){
//    printf("[%c]\n", *str);
    // delete spase
    if (*str !=' ') {
//      printf("-=%c=-\n", *(str+1));
//      printf("-=%c=-\n", *(str));
      str_res[str_n] = *str;
      str_n++;
    }
  }
  str_res[str_n] = '\0';
}


void runner_string(char *ch, int x) {
  Tmp var;
  var.string[0]='\n';
  var.n=0;
  var.x=x;

  for (; *ch; ch++) {
    if (check_char(*ch)){

    }
  }
}

int check_char(char ch){
  return (ch >= 97 && ch <=122 && ch !=120);
}