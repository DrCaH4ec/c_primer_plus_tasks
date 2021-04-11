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

uint8_t index_of_max_val(double *source, uint8_t size)
{
	uint8_t index = --size;

	while (size--) {
		if (source[index] < source[size])
			index = size;
	}

	return index;
}
