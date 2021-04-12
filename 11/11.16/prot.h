#ifndef _PROT_H_
#define _PROT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void *zalloc(size_t size);

void str_toupper(char *str);

void str_tolower(char *str);

/*_PROT_H_*/
#endif
