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

char *is_within(const char *str, char ch)
{
    uint16_t i;
    const char *tmp_str = str;

    for (i = 0; tmp_str[i] != ch && tmp_str[i] != '\0'; i++);

    if(tmp_str[i] == '\0')
        return NULL;

    return (char *)(tmp_str + i);
}
