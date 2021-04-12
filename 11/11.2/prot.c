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
    char tmp;

    for (uint8_t i = 0; i < size; i++) {
        tmp = getchar();

        if (tmp == '\n' || tmp == '\t' || tmp == ' ')
            return;

        text[i] = tmp;
    }
}

