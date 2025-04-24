#include "file.h"
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

char *parse_file_to_cstr(FILE *f)
{
	char *string = (char*)calloc(1, sizeof(char));
	int inp;
	while ((inp = fgetc(f)) != EOF)
	{
		char *str = (char *)calloc(2, sizeof(char));
		str[0] = (char)inp;
		str[1] = '\0';

		string = (char*)realloc(string, (strlen(string)+strlen(str)+1)*sizeof(char));
		strcat(string, str);
	}
	return string;
}
