#ifndef _PROT_H_
#define _PROT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void *zalloc(size_t size);

void read_word(char *text, uint8_t size);

/*_PROT_H_*/
#endif
