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

uint16_t num_of_upper(char *str)
{
	uint16_t counter = 0;

	for (size_t i = 0; str[i] != '\0'; i++)
		counter = isupper(str[i]) ? counter + 1 : counter;

	return counter;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

uint16_t num_of_lower(char *str)
{
	uint16_t counter = 0;

	for (size_t i = 0; str[i] != '\0'; i++)
		counter = islower(str[i]) ? counter + 1 : counter;

	return counter;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

uint16_t num_of_digits(char *str)
{
	uint16_t counter = 0;

	for (size_t i = 0; str[i] != '\0'; i++)
		counter = isdigit(str[i]) ? counter + 1 : counter;

	return counter;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

uint16_t num_of_punct(char *str)
{
	uint16_t counter = 0;

	for (size_t i = 0; str[i] != '\0'; i++)
		counter = ispunct(str[i]) ? counter + 1 : counter;

	return counter;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

uint16_t num_of_words(char *str)
{
	uint16_t counter = 1;

	for (size_t i = 0; i < (strlen(str) - 1); i++) {
		if (isspace(str[i]) && !isspace(str[i + 1]))
			counter++;
	}

	return counter;
}
