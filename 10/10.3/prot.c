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

int find_max(int *source, uint8_t size)
{
	int max = source[--size];

	while (size--) {
		max = MAX(max, source[size]);
	}

	return max;
}
