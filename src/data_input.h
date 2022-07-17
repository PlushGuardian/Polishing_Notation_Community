#ifndef SRC_DATA_INPUT_H_
#define SRC_DATA_INPUT_H_

char* input_string(int *flag);
int parse(char* str, lex** queue);
void print_struct(lex* root);

void output_of_type(int num);
void output_of_lex_type(int num);
void output_of_func(int num);
void print_one_node(lex* root);
FUNK to_funk(char cur);
void restart_array(char** arr, int* len);

#endif  // SRC_DATA_INPUT_H_
