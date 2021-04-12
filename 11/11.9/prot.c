#include "prot.h"

void *zalloc(size_t size)
{
	void *p = malloc(size);

	if (p == NULL)
		return p;

	memset(p, 0, size);
	return p;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

static void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

char *xchng(char *text)
{
    uint16_t length = strlen(text);
    for (uint16_t i = 0; i < (length / 2); i++) {
        swap(&(text[i]), &(text[length - i - 1]));
    }

    return text;
}
