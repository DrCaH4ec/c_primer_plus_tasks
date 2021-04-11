#ifndef _PROT_H_
#define _PROT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX(x, y) (x > y) ? (x) : (y)

void *zalloc(size_t size);

void **czalloc(size_t rowspan, size_t colspan, size_t cell_size);

void cfree(void** array, size_t rowspan);

void print_matrix(double **source, size_t rowspan, size_t colspan);

double average(double *source, size_t size);

double find_max(double **source, size_t rowspan, size_t colspan);

/*_PROT_H_*/
#endif
