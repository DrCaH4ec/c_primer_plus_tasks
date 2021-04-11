#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <math.h>
#include <string.h>

#include "prot.h"

#define MAX_NUMBER 100.00
#define MAX_ARR_SIZE 255

#define irand() (int)(sin((double)rand()) * MAX_NUMBER)

int main(int argc, char const *argv[])
{
	int status = 0;
	uint8_t arr_size;
	uint8_t i;

	if (argc != 2) {
		printf("Not enough arguments!\n");
		printf("USAGE IS:\n");
		printf("\t./main [size_of_array]\n");
		status = -EINVAL;
		goto err;
	}

	if (atoi(argv[1]) <= 0 || atoi(argv[1]) > MAX_ARR_SIZE) {
		printf("Bad size_of_array! Must be in range [1:%d]\n",
		       MAX_ARR_SIZE);
		status = -EINVAL;
		goto err;
	}
	arr_size = atoi(argv[1]);

	int *source = zalloc(sizeof(*source) * arr_size);
	if (source == NULL) {
		printf("Can't initialise 'source'\n");
		status = -ENOMEM;
		goto err;
	}

	for (i = 0; i < arr_size; i++) {
		source[i] = irand();
		printf("%d\n", source[i]);
	}

	printf("max value is %d\n", find_max(source, arr_size));

	free(source);

err:
	return status;
}
