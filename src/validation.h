typedef enum TYPE_OF_LAST_LEXEME {
    L_BRACKET,
    R_BRACKET,
    FUNCTION,
    OPERATOR,
    MINUS,
    NUMBER
}LEX_TYPE;

int validation(lex* head);
int complementing_types_of_units (LEX_TYPE prev_lex, LEX_TYPE cur_lex);
LEX_TYPE determine_current_type(FUNK elem);