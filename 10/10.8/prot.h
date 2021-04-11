#ifndef _PROT_H_
#define _PROT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX(x, y) (x > y) ? (x) : (y)
#define MIN(x, y) (x < y) ? (x) : (y)


void *zalloc(size_t size);

void copy(double *source, double *dest, uint8_t first_index, uint8_t ammount);

/*_PROT_H_*/
#endif
