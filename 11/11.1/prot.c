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

void read_symbols(char *text, uint8_t size)
{
	for (uint8_t i = 0; i < size; i++) {
		text[i] = getchar();
	}
}
