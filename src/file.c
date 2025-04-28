#include "file.h"

#include "str.h"

#include <stdlib.h>
#include <string.h>

int open_file(FILE **fptr, const char *path)
{
	FILE *f = fopen(path, "r");
	if (f == NULL)
	{
		printf("ERROR: Could not open file %s", path);
		return 0;
	}
	*fptr = f;
	return 1;
}

void close_file(FILE *f)
{
	fclose(f);
}

string *parse_file_to_str(FILE *f)
{
	string *str = str_create_empty();
	int inp;
	while ((inp = fgetc(f)) != EOF)
	{
		char current = (char) inp;
		str_append(str, current);
	}
	str_append(str, '\0');
	return str;
}
