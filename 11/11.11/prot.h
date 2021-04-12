#ifndef _PROT_H_
#define _PROT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

void *zalloc(size_t size);

void **czalloc(size_t rowspan, size_t colspan, size_t cell_size);

char *gets(char *buf, size_t size);

void ascii_sort(char **str, uint8_t num_of_str);

void length_sort(char **str, uint8_t num_of_str);

void first_word_length_sort(char **str, uint8_t num_of_str);

void cfree(void **array, size_t rowspan);

/*_PROT_H_*/
#endif
