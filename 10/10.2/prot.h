#ifndef _PROT_H_
#define _PROT_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void *zalloc(size_t size);

void copy_arr(double *source, double *dest, uint8_t size);

void copy_ptr(double *source, double *dest, uint8_t size);

void copy_ptrs(double *source, double *dest, double *max_data);

/*_PROT_H_*/
#endif
