#ifndef __STRING_H
#define __STRING_H

typedef struct
{
	char *raw;
	int length;
	int capacity;
} string;

string *str_create_empty();
string *str_create(char *value);
void str_free(string *str);

void str_append(string *str, char c);

#endif // __STRING_H
