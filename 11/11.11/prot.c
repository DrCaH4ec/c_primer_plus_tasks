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

void **czalloc(size_t rowspan, size_t colspan, size_t cell_size)
{
	void **tmp = zalloc(rowspan * sizeof(void *));

	if (tmp == NULL)
		return NULL;

	for (size_t i = 0; i < rowspan; i++) {
		tmp[i] = zalloc(colspan * cell_size);
		if (tmp[i] == NULL) {
			return NULL;
		}
	}

	return tmp;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void cfree(void **array, size_t rowspan)
{
	for (size_t i = 0; i < rowspan; i++)
		free(array[i]);
	free(array);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

char *gets(char *buf, size_t size)
{
	if (buf != NULL && size > 0) {
		if (fgets(buf, size, stdin)) {
			buf[strcspn(buf, "\n")] = '\0';
			return buf;
		}
		*buf = '\0'; /* clear buffer at end of file */
	}
	return NULL;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

static int ascii_cmp(const char **a, const char **b)
{
	if (*a[0] < *b[0])
		return -1;

	if (*a[0] > *b[0])
		return 1;

	return 0;
}

void ascii_sort(char **str, uint8_t num_of_str)
{
	qsort(str, num_of_str, sizeof(char *),
	      (int (*)(const void *, const void *))ascii_cmp);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

static int length_cmp(const char **a, const char **b)
{
	if (strlen(*a) < strlen(*b))
		return -1;

	if (strlen(*a) > strlen(*b))
		return 1;

	return 0;
}

void length_sort(char **str, uint8_t num_of_str)
{
	qsort(str, num_of_str, sizeof(char *),
	      (int (*)(const void *, const void *))length_cmp);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

static char *read_word(const char *text, uint8_t size)
{
	uint8_t i, shift;
	char *result = zalloc(sizeof(*result) * size);
	if (result == NULL)
		return NULL;

	for (i = 0; text[i] == '\n' || text[i] == '\t' || text[i] == ' '; i++)
		;

	i++;
	shift = i;

	for (; i < size; i++) {
		if (text[i] == '\n' || text[i] == '\t' || text[i] == ' ')
			return result;

		result[i - shift] = text[i];
	}

	return NULL;
}

static int first_word_length_cmp(const char **a, const char **b)
{
	uint8_t lw1 = strlen(read_word(*a, strlen(*a)));
	uint8_t lw2 = strlen(read_word(*b, strlen(*b)));

	if (lw1 < lw2)
		return -1;

	if (lw1 > lw2)
		return 1;

	return 0;
}

void first_word_length_sort(char **str, uint8_t num_of_str)
{
	qsort(str, num_of_str, sizeof(char *),
	      (int (*)(const void *, const void *))first_word_length_cmp);
}
