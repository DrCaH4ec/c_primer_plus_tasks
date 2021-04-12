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

char *string_in(const char *str, const char *search_str)
{
    uint16_t i, j;

    for (i = 0; str[i] != '\0'; i++) {
        for (j = 0; search_str[j] != '\0'; j++) {
            if (str[i + j] != search_str[j])
                break;
        }

        if (search_str[j] == '\0')
            return (char *)(str + i);
    }
    return NULL;
}
