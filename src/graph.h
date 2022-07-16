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



struct lex {
    TYPE type;
    union {
        FUNK func;
        int num;
    }; 
    struct lex* next;
};

#endif
