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

void str_toupper(char *str)
{
	for (size_t i = 0; str[i] != '\0'; i++)
		str[i] = toupper(str[i]);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void str_tolower(char *str)
{
	for (size_t i = 0; str[i] != '\0'; i++)
		str[i] = tolower(str[i]);
}
