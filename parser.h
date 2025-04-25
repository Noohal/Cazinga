#ifndef __PARSER_H
#define __PARSER_H

#include "container.h"

typedef struct PARSER
{
	token_queue_t *tokens;
} parser_t;

void parse_expr(parser_t *parser);

#endif
