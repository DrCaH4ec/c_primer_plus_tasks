#ifndef _PROT_H_
#define _PROT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX(x, y) (x > y) ? (x) : (y)

void *zalloc(size_t size);

int find_max(int *source, uint8_t size);

/*_PROT_H_*/
#endif
