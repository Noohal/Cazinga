#include "lexer.h"

#include "queue.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

		token_free(token);
	}

	token_queue_free(queue);
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
		}
		lexer_next(lex);	
	}

	return NULL;
}

void lexer_next(Lexer *lex)
{
	lex->current = lex->contents[++lex->idx];
}

Token *lexer_get_next_with_number(Lexer *lex)
{
	string *num = str_create_empty();
	while (lex->current != '\n' && lex->current != ' ' && isdigit(lex->current))
	{
		str_append(num, lex->current);
		lexer_next(lex);
	}
	str_append(num, '\0');
	return token_new_from_string(TOKEN_NUM, num);
}

void lexer_skip_whitespace(Lexer *lex)
{
	while (lex->current == ' ' || lex->current == '\n')
	{
		lexer_next(lex);
	}
}

