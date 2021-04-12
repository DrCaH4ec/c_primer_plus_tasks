#ifndef _PROT_H_
#define _PROT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void *zalloc(size_t size);

uint16_t num_of_upper(char *str);

uint16_t num_of_lower(char *str);

uint16_t num_of_digits(char *str);

uint16_t num_of_punct(char *str);

uint16_t num_of_words(char *str);

/*_PROT_H_*/
#endif
