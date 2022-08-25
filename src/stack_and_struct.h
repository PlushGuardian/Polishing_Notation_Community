#ifndef SRC_STACK_AND_STRUCT_H_
#define SRC_STACK_AND_STRUCT_H_

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
    X,
    NUM,
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
int reverse_stack(lex** old, lex** new_);



// FOR POLISH NOTATION
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

void add_to_output_from_stack(struct stack_for_output **root, double item);
void add_to_output_from_lex(struct stack_for_output **root, int item, int is_x);
double pop_from_stack(struct stack_for_OP **root);
void push_to_stack(struct stack_for_OP **root, double item);
struct lexical_units *copy_to_lex(struct stack_for_output *Output_RPN);
void add_to_struct(struct lexical_units **root, struct stack_for_output *Output_RPN);
struct lexical_units *generate_test_lex();
struct lexical_units *generate_test_lex_sin();
void output(struct lexical_units *lex);


#endif  // SRC_STACK_AND_STRUCT_H_
