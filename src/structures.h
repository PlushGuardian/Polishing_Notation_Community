
// MAIN STRUCT OPERATIONS
lex* new_lex(elem data);
lex* remove_lex(lex* head, int* flag);
lex* add_to_head(lex* head, elem new_unit, int* flag);
lex* add_to_tail(lex* tail, elem new_unit, int* flag);
lex* return_to_head(lex* tail);
int free_list(lex* head);

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
    ERR,
    NO_RES
}FUNK;


typedef struct Element {
  FUNK func;
  double num;
} elem;

typedef struct lexical_units {
    struct lexical_units* next;
    struct lexical_units* prev;
    elem unit;
} lex;