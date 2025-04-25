/* C-Library */
#include <stdio.h>
#include <stdlib.h>

/* Authored */
#include "file.h"
#include "container.h"
#include "lexer.h"
#include "token.h"

int main(int argc, char **argv)
{
	FILE *file = NULL;
	if (!open_file(&file, "test.baz"))
	{
		return -1;
	}
	
	printf("file opened\n");
	char *contents = parse_file_to_cstr(file);

	lexer_t *lexer = lexer_create(contents);
	token_queue_t *queue = tqueue_create();
	token_t *token = NULL;
	while ((token = lexer_get_next_token(lexer)) != NULL)
	{
		tqueue_push(queue, *token);
	}

	token = NULL;
	while ((token = tqueue_pop(queue)) != NULL)
	{
		token_print(*token);
	}

	tqueue_free(queue);
	lexer_free(lexer);
	free(contents);
	fclose(file);
	return 0;
}
