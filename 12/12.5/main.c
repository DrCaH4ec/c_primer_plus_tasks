#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define ARR_SIZE 100

#define uirand(min, max) (int)(rand() % (max - min + 1) + min)

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main(void)
{
	int array[ARR_SIZE];

	for (int i = 0; i < ARR_SIZE; i++)
		array[i] = uirand(1, 10);

	qsort(array, ARR_SIZE, sizeof(*array), cmp);

	for (int i = 0; i < ARR_SIZE; i++)
		printf("%d\n", array[i]);

	return 0;
}
