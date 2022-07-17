#ifndef SRC_RPN_H
#define SCR_RPN_H

struct stack_for_OP {
    double func;
    struct stack_for_OP* prev;
};

struct flags {
    int flag_1;
    int flag3;
};

struct stack_for_output {
    TYPE type;
    double func;
    int num;
    int is_x;
    struct stack_for_output* prev;
};

struct lexical_units *Reverse_RPN(struct lexical_units *input);
void RPN_op (struct lexical_units *lex, struct stack_for_OP **stack, struct stack_for_output **Output_RPN,
            struct flags **flag);
int Precedence(FUNK func);
void add_to_output_from_stack(struct stack_for_output **root, double item);
void add_to_output_from_lex(struct stack_for_output **root, int item, int is_x);
double pop_from_stack(struct stack_for_OP **root);
void push_to_stack(struct stack_for_OP **root, double item);
struct lexical_units *copy_to_lex(struct stack_for_output *Output_RPN);
void add_to_struct(struct lexical_units **root, struct stack_for_output *Output_RPN);
struct lexical_units *generate_test_lex();
struct lexical_units *generate_test_lex_sin();
void output(struct lexical_units *lex);

#endif