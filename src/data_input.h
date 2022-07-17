#ifndef SRC_DATA_INPUT_H_
#define SRC_DATA_INPUT_H_

char* input_string(int *flag);
int parse(char* str, lex** queue);
void print_struct(lex* root);

void output_of_type(int num);
void output_of_lex_type(int num);
void output_of_func(int num);

#endif  // SRC_DATA_INPUT_H_
