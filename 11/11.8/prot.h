#ifndef _PROT_H_
#define _PROT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

void *zalloc(size_t size);

char *string_in(const char *str, const char *search_str);

/*_PROT_H_*/
#endif
