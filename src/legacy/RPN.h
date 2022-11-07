#ifndef SRC_RPN_H
#define SCR_RPN_H

struct lexical_units *Reverse_RPN(struct lexical_units *input);
void RPN_op (struct lexical_units *lex, struct stack_for_OP **stack, struct stack_for_output **Output_RPN,
            struct flags **flag);
int Precedence(FUNK func);


#endif