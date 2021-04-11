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

static void swap(double *a, double *b)
{
	double tmp = *a;
	*a = *b;
	*b = tmp;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void xchng(double *source, uint8_t size)
{
	uint8_t i;
	for(i = 0; i < size / 2; i++) {
		swap(&source[i], &source[size - i - 1]);
	}
}
