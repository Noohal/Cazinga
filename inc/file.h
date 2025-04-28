#ifndef __FILEPARSER_H
#define __FILEPARSER_H

#include "str.h"
#include <stdio.h>

int open_file(FILE **fptr, const char *path);
void close_file(FILE *fptr);

string *parse_file_to_str(FILE *fptr);

#endif // __FILEPARSER_H
