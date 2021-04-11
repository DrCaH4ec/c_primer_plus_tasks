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

void print_matrix(int **source, size_t rowspan, size_t colspan)
{
	for (size_t i = 0; i < rowspan; i++) {
		for (size_t j = 0; j < colspan; j++) {
			printf("%d\t", source[i][j]);
		}
		printf("\n");
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void double_values(int **source, size_t rowspan, size_t colspan)
{
	for (size_t i = 0; i < rowspan; i++)
		for (size_t j = 0; j < colspan; j++)
			source[i][j] *= 2;
}
