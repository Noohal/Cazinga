#ifndef __TOKEN_H
#define __TOKEN_H

typedef enum TokenType
{
	TOKEN_INVALID = 0,
	TOKEN_SYMBOL,
	TOKEN_NUM
} TokenType;

typedef struct
{
	TokenType type;
	const char *value;
} Token;

Token *token_new(TokenType type, const char *value);
void token_free(Token *token);

#endif // __TOKEN_H
