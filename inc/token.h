#ifndef __TOKEN_H
#define __TOKEN_H

#include "str.h"

typedef enum TokenType
{
	TOKEN_INVALID = 0,
	TOKEN_SYMBOL,
	TOKEN_NUM
} TokenType;

typedef struct Token
{
	TokenType type;
	string *value;
} Token;

Token *token_new(TokenType type, char *value);
Token *token_new_from_string(TokenType type, string *value);
void token_free(Token *token);

#endif // __TOKEN_H
