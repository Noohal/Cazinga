#ifndef __LEXER_H
#define __LEXER_H

#include "token.h"

typedef struct
{
	const char *contents;
	unsigned char current;
	int size;
	int idx;
} Lexer;

void lexer_set_size(Lexer *lex);

void lexer_lex(Lexer *lex);
void lexer_next(Lexer *lex);
void lexer_skip_whitespace(Lexer *lex);

Token *lexer_get_next_token(Lexer *lex);
Token *lexer_get_next_with_number(Lexer *lex);
Token *lexer_get_next_with_symbol(Lexer *lex);
Token *lexer_get_next_with_string(Lexer *lex);
Token *lexer_get_next_with_token(Lexer *lex, TokenType type);

#endif // __LEXER_H
