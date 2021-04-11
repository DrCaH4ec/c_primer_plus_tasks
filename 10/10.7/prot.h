#ifndef _PROT_H_
#define _PROT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void *zalloc(size_t size);

void **czalloc(size_t rowspan, size_t colspan, size_t cell_size);

void cfree(void** array, size_t rowspan);

void copy_matrix(double **source, double **dest, size_t rowspan, size_t colspan);

/*_PROT_H_*/
#endif
