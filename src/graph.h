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



struct lexical_units {
    TYPE type;
    union {
        FUNK func;
        int num;
    }; 
    struct lexical_units* next;
};

typedef struct lexical_units lex;

#endif
