#include "token.h"

#include <stdio.h>
#include <stdlib.h>

token_t *token_create(enum TokenType t, char *val)
{
	token_t *token = (token_t*)calloc(1, sizeof(token_t));
	token->type = t;
	token->value = val;

	return token;
}

void token_free(token_t *token)
{
	free(token);
	token = NULL;
}

void token_print(token_t *token)
{
	printf("TOKEN(");

	switch(token->type)
	{
		case TOKEN_NUMBER:
		printf("NUMBER, ");
			break;
		case TOKEN_STRING:
			printf("STRING, ");
			break;
		case TOKEN_SYMBOL:
			printf("SYMBOL, ");
			break;
		case TOKEN_EQUALS:
			printf("EQUALS, ");
			break;
		case TOKEN_ADD:
			printf("ADD, ");
			break;
		case TOKEN_SUB:
			printf("SUBTRACT, ");
			break;
		case TOKEN_MUL:
			printf("MULTIPLY, ");
			break;
		case TOKEN_DIV:
			printf("DIVIDE, ");
			break;
		case TOKEN_LPAREN:
			printf("LEFT PAREN, ");
			break;
		case TOKEN_RPAREN:
			printf("RIGHT PAREN, ");
			break;
		default:
			printf("INVALID, ");
			break;
	}
	
	if (token->type == TOKEN_STRING)
	{
		printf("\'%s\')\n", token->value);
	}
	else if (token->type == TOKEN_INVALID)
	{
		printf("%d)\n", (int)*token->value);
	}
	else 
	{
		printf("%s)\n", token->value);
	}
}
