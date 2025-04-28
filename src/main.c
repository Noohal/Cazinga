#include <stdio.h>

#include "token.h"
#include "lexer.h"

int main(void)
{
	const char *code = "var x = 1123a1231\n" \
					   "print(x + 'this is a string')\n";
	
	Lexer lexer = { .contents = code, .current = code[0], .idx = 0 };
	
	lexer_set_size(&lexer);
	lexer_lex(&lexer);
	return 0;
}
