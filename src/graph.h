#ifndef SRC_GRAPH_H_
#define SRC_GRAPH_H_
typedef enum TYPE_N {
    NUM,
    OP
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
    X,
}LEX_TYPE;

struct lexical_units {
    TYPE type;
    struct lexical_units* next;
    union {
        FUNK func;
        int num;
    } elem;
} ;

typedef struct lexical_units lex;

#endif  // SRC_GRAPH_H_
