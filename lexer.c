#include "lexer.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

lexer_t *lexer_create(char *string)
{
	lexer_t *lex = (lexer_t*)calloc(1, sizeof(lexer_t));
	lex->data = string;
	lex->length = strlen(string);
	lex->idx = 0;
	lex->current = lex->data[lex->idx];
	return lex;
}

void lexer_free(lexer_t *lex)
{
	free(lex);
	lex = NULL;
}

void lexer_skip_whitespace(lexer_t *lex)
{
	while (lex->current == ' ' || lex->current == '\n')
	{
		lexer_next(lex);
	}
}

void lexer_next(lexer_t *lex)
{
	lex->current = lex->data[++lex->idx];
}

token_t *lexer_get_next_token(lexer_t *lex)
{
	while(lex->current != '\0')
	{
		lexer_skip_whitespace(lex);
		// Beginning of loop will always be new token.
		if (lex->current == '"')
		{
			char *token = lexer_next_with_string(lex);
			return token_create(TOKEN_STRING, token);
		}
		
		if (isalnum(lex->current))
		{
			if (isdigit(lex->current))
			{
				char *constant = lexer_next_with_number(lex);
				return token_create(TOKEN_NUMBER, constant);
			}
			else
			{
				char *symbol = lexer_next_with_symbol(lex);
				return token_create(TOKEN_SYMBOL, symbol);
			}
		}

		switch(lex->current)
		{
			case '=':
				return lexer_next_with_token(lex, TOKEN_EQUALS);
			case '(':
				return lexer_next_with_token(lex, TOKEN_LPAREN);
			case ')':
				return lexer_next_with_token(lex, TOKEN_RPAREN);
			case '+':
				return lexer_next_with_token(lex, TOKEN_ADD);
			case '-':
				return lexer_next_with_token(lex, TOKEN_SUB);
			case '*':
				return lexer_next_with_token(lex, TOKEN_MUL);
			case '/':
				return lexer_next_with_token(lex, TOKEN_DIV);
			default:
				if (lex->current != 0)
					return lexer_next_with_token(lex, TOKEN_INVALID);
				else
					break;
		}
		lexer_next(lex);	
	}
	return NULL;
}

token_t *lexer_next_with_token(lexer_t *lex, enum TokenType t)
{
	token_t *tok = token_create(t, char_as_string(lex->current));
	lexer_next(lex);
	return tok;
}

char *lexer_next_with_string(lexer_t *lex)
{
	char *str = (char*)calloc(1, sizeof(char));
	
	lexer_next(lex);
	while (lex->current != '"')
	{
		char *current = char_as_string(lex->current);
		str = (char*)realloc(str, (strlen(str) + strlen(current) + 1)*sizeof(char));
		strcat(str, current);
		lexer_next(lex);
	}
	lexer_next(lex);
	return str;
}

char *lexer_next_with_number(lexer_t *lex)
{
	char *num = (char*)calloc(1, sizeof(char));

	while (lex->current != ' ' && lex->current != '\n')
	{
		char *current = char_as_string(lex->current);
		num = (char*)realloc(num, (strlen(num) + strlen(current) + 1)*sizeof(char));
		strcat(num, current);
		lexer_next(lex);
	}

	return num;
}

char *lexer_next_with_symbol(lexer_t *lex)
{
	char *sym = (char*)calloc(1, sizeof(char));

	while (lex->current != ' ' && lex->current != '\n' && isalnum(lex->current))
	{
		char *current = char_as_string(lex->current);
		sym = (char*)realloc(sym, (strlen(sym) + strlen(current) + 1)*sizeof(char));
		strcat(sym, current);
		lexer_next(lex);
	}
	
	if (lex->current != '(' && lex->current != '"')
	{
		lexer_next(lex);
	}
	return sym;
}

char *char_as_string(char c)
{
	char *str = (char*)calloc(2, sizeof(char));
	str[0]=c;
	str[1]='\0';
	return str;
}
