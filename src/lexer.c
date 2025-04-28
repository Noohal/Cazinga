#include "lexer.h"

#include "queue.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int lexer_is_whitespace(Lexer *lex)
{
	return lex->current != '\n' && lex->current != ' ';
}

void lexer_set_size(Lexer *lex)
{
	lex->size = strlen(lex->contents);	
}

void lexer_lex(Lexer *lex)
{
	Token_Queue *queue = token_queue_create(1);

	Token *token = NULL;
	while (lex->current != '\0')
	{
		token = lexer_get_next_token(lex);

		if (token)
		{
			printf("TOKEN(%d, %s)\n", token->type, token->value->raw);
		}

		token_free(token);
	}

	token_queue_free(queue);
}

void lexer_next(Lexer *lex)
{
	lex->current = lex->contents[++lex->idx];
}

void lexer_skip_whitespace(Lexer *lex)
{
	while (lex->current == ' ' || lex->current == '\n')
	{
		lexer_next(lex);
	}
}

Token *lexer_get_next_token(Lexer *lex)
{
	while (lex->current != '\0' && lex->idx < lex->size)
	{
		lexer_skip_whitespace(lex);
		
		if (isalnum(lex->current))
		{
			if (isdigit(lex->current))
			{
				return lexer_get_next_with_number(lex);
			}
			else
			{
				return lexer_get_next_with_symbol(lex);
			}
		}

		switch(lex->current)
		{
			case '\"':
				return lexer_get_next_with_string(lex);
			case '(':
				return lexer_get_next_with_token(lex, TOKEN_LPAREN);
			case ')':
				return lexer_get_next_with_token(lex, TOKEN_RPAREN);
			case '=':
				return lexer_get_next_with_token(lex, TOKEN_EQUALS);
			case '+':
			case '-':
			case '*':
			case '/':
			default:
				return lexer_get_next_with_token(lex, TOKEN_INVALID);
		}
		lexer_next(lex);	
	}

	return NULL;
}

Token *lexer_get_next_with_number(Lexer *lex)
{
	string *num = str_create_empty();
	while (lexer_is_whitespace(lex) && isdigit(lex->current))
	{
		str_append(num, lex->current);
		lexer_next(lex);
	}
	str_append(num, '\0');
	
	return token_new_from_string(TOKEN_NUM, num);
}

Token *lexer_get_next_with_symbol(Lexer *lex)
{
	string *sym = str_create_empty();
	while (lexer_is_whitespace(lex) && isalnum(lex->current))
	{
		str_append(sym, lex->current);
		lexer_next(lex);
	}
	str_append(sym, '\0');
	
	return token_new_from_string(TOKEN_SYMBOL, sym);
}

Token *lexer_get_next_with_string(Lexer *lex)
{
	string *str = str_create_empty();
	lexer_next(lex);
	while (lex->current != '\"')
	{
		str_append(str, lex->current);
		lexer_next(lex);
	}
	str_append(str, '\0');
	lexer_next(lex);

	return token_new_from_string(TOKEN_STRING, str);
}

Token *lexer_get_next_with_token(Lexer *lex, TokenType type)
{
	string *val = str_create_empty();
	str_append(val, lex->current);
	lexer_next(lex);
	return token_new_from_string(type, val);
}
