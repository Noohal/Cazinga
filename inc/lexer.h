#ifndef __LEXER_H
#define __LEXER_H

#include "token.h"

typedef struct LEXER_STRUCT
{
	unsigned int length;
	unsigned int idx;
	char *data;
	char current;
} lexer_t;

lexer_t *lexer_create(char *string);
void lexer_free(lexer_t *lex);

void lexer_skip_whitespace(lexer_t *lex);
void lexer_next(lexer_t *lex);
token_t *lexer_get_next_token(lexer_t *lex);

token_t *lexer_next_with_token(lexer_t *lex, enum TokenType t);
char *lexer_next_with_string(lexer_t *lex);
char *lexer_next_with_number(lexer_t *lex);
char *lexer_next_with_symbol(lexer_t *lex);

char *char_as_string(char c);

#endif // __LEXER_H
