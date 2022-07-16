#ifndef SRC_GRAPH_H_
#define SRC_GRAPH_H_
enum TYPE {
    NUM,
    OP
};
enum FUNK {
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
};

struct lex {
    enum TYPE type;
    union {
        enum FUNK func;
        int num;
    }; 
};
#endif
