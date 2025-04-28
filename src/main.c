#include <stdio.h>

#include "file.h"
#include "token.h"
#include "lexer.h"

int main(void)
{
	/*
	const char *code = "var x = 1123a1231\n" \
					   "print(x + \"this is a string\")\n";
	*/
	FILE *file = NULL;
	if (!open_file(&file, "test.baz"))
	{
		return -1;
	}
	
	string *parsed_file = parse_file_to_str(file);
	if (!parsed_file)
	{
		fprintf(stderr, "ERROR: Could not parse file!");
		return -1;
	}
	Lexer lexer = { .contents = parsed_file->raw, .current = parsed_file->raw[0], .idx = 0 };
	
	lexer_set_size(&lexer);
	lexer_lex(&lexer);
	str_free(parsed_file);
	close_file(file);
	return 0;
}
