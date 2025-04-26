#include "token.h"

#include <stdlib.h>

Token *token_new(TokenType type, const char *value)
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
		free(token);
		token = NULL;
	}
}
