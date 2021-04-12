#ifndef _PROT_H_
#define _PROT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

void *zalloc(size_t size);

char *mystrncpy(char *dest, const char *source, size_t count);

/*_PROT_H_*/
#endif
