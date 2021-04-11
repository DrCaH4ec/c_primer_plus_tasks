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

static void copy_arr(double *source, double *dest, size_t size)
{
	while (size--) {
		dest[size] = source[size];
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void copy(double *source, double *dest, uint8_t first_index, uint8_t ammount)
{
	copy_arr(&source[first_index], dest, ammount);
}
