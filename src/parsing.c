#include "parsing.h"

void preparing_string(char *str, char *str_res) {
  int str_n = 1;
  str_res[0] = '(';
  for (; *str; str++) {
    if (*str != ' ') {
      if (*str >= 65 && *str <= 90) {
        str_res[str_n] = *str + 32; // lower case conversion
      } else {
        str_res[str_n] = *str;
      }
      str_n++;
    }
  }
  str_res[str_n] = ')';
  str_res[str_n + 1] = '\0';
}

void runner_string(char *ch, int x) {
  Tmp var;
  var.string[0] = '\n';
  var.n = 0;
  var.prev = '';

  for (; *ch; ch++) {
    if (check_char(*ch)) {

    }
    var.prev = *ch;
  }
}

int check_char(char ch) {
  return (ch >= 97 && ch <= 122 && ch != 120);
}

void string_assembly(Tmp var, char ch){
  if (var.string[0]){
    if(check_char(ch)){
      char ch_tmp[1];
      ch_tmp[0] = ch;
      strcat(var.string, ch_tmp);
    } else {
      // todo verification
      var.string[0] = '\0';
    }
  } else {
    if (check_char(ch)){
      var.string[0] = ch;
      var.string[1] = '\0';
    }
  }
}

Element check_operator(char ch, Tmp var) {
  Element res;
  res.funk = NO_RES;
  switch (ch) {
    case '-':
      if (var.prev == '(') {
        res.funk = NEGATE;
      } else {
        res.funk = SUBTR;
      }
      break;
    case '+':res.funk = ADD;
      break;
    case '*': res.funk = MULTI;
      break;
    case '/': res.funk = DIVIDE;
      break;
    case '(': res.funk = L_BRACK;
      break;
    case ')': res.funk = R_BRACK;
      break;
  }
  return res;
}