#include "parser.h"

// Parselets are objects that define how to parse specific token types.
// In OOP, this would be through inheritance so that a parseParselet() function can be called.
// Need to make structs with function pointers.

void parse_expr(parser_t *parser)
{
	token_t *token = tqueue_pop(parser->tokens);

}

