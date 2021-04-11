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

int *summ_of_arrays(int *a, int *b, uint8_t size)
{
	int *tmp = zalloc(size * sizeof(*tmp));
	if (tmp == NULL)
		return NULL;

	while (size--) {
		tmp[size] = a[size] + b[size];
	}
	return tmp;
}
