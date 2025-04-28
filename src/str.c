#include "str.h"

#include <stdlib.h>
#include <string.h>

string *str_create_empty()
{
	string *str = (string*)malloc(1 * sizeof(string));
	str->raw = (char*)malloc(1 * sizeof(char));
	*str->raw = '\0';
	str->length = 0;
	str->capacity = 1;
	return str;
}

string *str_create(char *value)
{
	string *str = (string*)malloc(1 * sizeof(string));
	str->raw = value;
	int length = strlen(value);
	str->length = length;
	str->capacity = sizeof(char)*length;
	return str;
}

void str_free(string *str)
{
	free(str->raw);
	str->raw = NULL;
	free(str);
	str = NULL;
}

void str_append(string *str, char c)
{
	str->capacity += 2;
	str->raw = (char*)realloc(str->raw, (str->capacity) * sizeof(char));
	str->raw[str->length++] = c;
	str->raw[str->length] = '\0';
}
