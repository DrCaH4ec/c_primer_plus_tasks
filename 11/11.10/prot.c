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

char *delete_spaces(const char *text)
{
	char *tmp = zalloc(sizeof(*tmp) * strlen(text) + 1);
	uint16_t shift = 0;

	for (uint16_t i = 0; text[i] != '\0'; i++) {
		if (text[i] == ' ') {
			shift++;
		} else {
			tmp[i - shift] = text[i];
		}
	}

	return tmp;
}
