#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int *make_array(int elem, int val);

void show_array(const int ar[], int n);

int main(void)
{
	int status = 0;
	int *pa;
	int size;
	int value;
	printf("Enter the number of elements: ");

	while (scanf("%d", &size) == 1 && size > 0) {
		printf("Enter the initialization value: ");

		if (scanf("%d", &value) != 1) {
			status = -EINVAL;
			goto err;
		}

		pa = make_array(size, value);

		if (pa) {
			show_array(pa, size);
			free(pa);
		}

		printf("Enter the number of elements (<1 to quit): ");
	}
err:
	printf("Done.\n");
	return status;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

int *make_array(int elem, int val)
{
	int *tmp = malloc(sizeof(*tmp) * elem);
	if (tmp == NULL)
		goto ret;

	for (int i = 0; i < elem; i++)
		tmp[i] = val;

ret:
	return tmp;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void show_array(const int ar[], int n)
{
	for (int i = 0; i < n / 8 + 1; i++) {
		for (int j = 0; j < 8 && (i * 8 + j) < n; j++)
			printf("%d ", ar[i * 8 + j]);

		printf("\n");
	}
}
