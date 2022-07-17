#ifndef SRC_STACK_AND_STRUCT_H_
#define SRC_STACK_AND_STRUCT_H_

// OPERATIONS FOR WORKING WITH STACK (USED IN CALCULATION FOR NUMBERS)
struct stack_node {
    double data;
    struct stack_node* next;
};

typedef struct stack_node stack;
stack* new_node(double data);
void push(stack** root, double data);
double pop(stack** root);

// OPERATIONS FOR WORKING WITH STRUCTURE (QUEUE OF OPERANDS AND OPERATIONS)
struct lexical_units {
    TYPE type;
    struct lexical_units* next;
    union {
        FUNK func;
        double num;
        double is_x;
    } elem;
} ;
typedef struct lexical_units lex;

void push_lex(lex** root, TYPE type, double data, int *flag);
void pop_lex(lex** root); 
lex* new_node_lex();
lex* slide_lex(lex* elem, TYPE type, double data, int *flag);
int reverse_stack(lex** old, lex** new);

typedef enum TYPE_N {
    NUM,
    OP,
    X,
}TYPE;

typedef enum FUNK_N {
    ADD,
    SUBTR,
    NEGATE,
    DIVIDE,
    MULTI,
    L_BRACK,
    R_BRACK,
    SIN,
    COS,
    TAN,
    CTG,
    SQRT,
    LN,
}FUNK;

typedef enum TYPE_OF_LAST_LEXEME {
    START,
    OPERATOR,
    FUNCTION,
    MINUS,
    NUMBER,
    L_BRACKET,
    R_BRACKET,
    VAR,
}LEX_TYPE;


#endif  // SRC_STACK_AND_STRUCT_H_