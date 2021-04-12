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

char *mystrncpy(char *dest, const char *source, size_t count)
{
    _Bool flag = false;

    for (size_t i = 0; i < count; i++) {

        if (source[i] == '\0')
            flag = true;

        if (flag)
            dest[i] = '\0';
        else
            dest[i] = source[i];
    }

    return dest;
}
