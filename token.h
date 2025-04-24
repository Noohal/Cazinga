#ifndef __TOKEN_H
#define __TOKEN_H

enum TokenType {
	TOKEN_INVALID,
	TOKEN_NUMBER,
	TOKEN_STRING,
	TOKEN_SYMBOL,
	
	// Operations
	TOKEN_EQUALS,
	TOKEN_ADD,
	TOKEN_SUB,
	TOKEN_MUL,
	TOKEN_DIV,
	
	// Delimiters
	TOKEN_LPAREN,
	TOKEN_RPAREN
};

typedef struct Token
{
	enum TokenType type;
	char *value;
} token_t;

token_t *token_create(enum TokenType t, char *val);
void token_free(token_t *token);

void token_print(token_t *token);

#endif // __TOKEN_H
