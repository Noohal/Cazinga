#ifndef __FILEPARSER_H
#define __FILEPARSER_H

#include <stdio.h>

int open_file(FILE **fptr, const char *path);
void close_file(FILE *fptr);

char *parse_file_to_cstr(FILE *fptr);

#endif // __FILEPARSER_H
