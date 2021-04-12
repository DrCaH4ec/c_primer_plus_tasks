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

void read_word(char *text, uint8_t size)
{   
    char tmp;

    do {
        tmp = getchar();
    } while(tmp == ' ' || tmp == '\t');

    text[0] = tmp;

    for (uint8_t i = 1; i < size; i++) {
        tmp = getchar();

        if (tmp == '\n' || tmp == '\t' || tmp == ' ')
            return;

        text[i] = tmp;
    }
}

