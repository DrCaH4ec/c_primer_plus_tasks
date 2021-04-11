#include "prot.h"

void *zalloc(size_t size)
{
	void *p;
	p = malloc(size);

	if (p == NULL)
		return p;

	memset(p, 0, size);
	return p;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void copy_arr(double *source, double *dest, uint8_t size)
{
	while (--size) {
		dest[size] = source[size];
	}
	dest[size] = source[size];
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void copy_ptr(double *source, double *dest, uint8_t size)
{
	while (--size) {
		*(dest + size) = *(source + size);
	}
	*(dest + size) = *(source + size);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void copy_ptrs(double *source, double *dest, double *max_data)
{
	if (max_data < source) {
		dest = NULL;
		return;
	}

	copy_ptr(source, dest, max_data - source);
}
