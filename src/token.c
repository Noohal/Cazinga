#include "token.h"

#include <stdlib.h>

Token *token_new(TokenType type, char *value)
{
	Token *token = (Token*)malloc(sizeof(Token));
	token->type = type;
	token->value = str_create(value);
	return token;
}

Token *token_new_from_string(TokenType type, string *value)
{
	Token *token = (Token*)malloc(sizeof(Token));
	token->type = type;
	token->value = value;
	return token;
}

void token_free(Token *token)
{
	if (token)
	{
		str_free(token->value);
		free(token);
		token = NULL;
	}
}
