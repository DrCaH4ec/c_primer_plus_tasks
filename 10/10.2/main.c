#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <math.h>
#include <string.h>

#include "prot.h"

#define MAX_NUMBER 100.00
#define MAX_ARR_SIZE 255

#define drand() (sin((double)rand()) * MAX_NUMBER)

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

	double *source = zalloc(sizeof(*source) * arr_size);
	if (source == NULL) {
		printf("Can't initialise 'source'\n");
		status = -ENOMEM;
		goto err;
	}

	double *target1 = zalloc(sizeof(*target1) * arr_size);
	if (target1 == NULL) {
		printf("Can't initialise 'target1'\n");
		status = -ENOMEM;
		goto err;
	}

	double *target2 = zalloc(sizeof(*target2) * arr_size);
	if (target2 == NULL) {
		printf("Can't initialise 'target2'\n");
		status = -ENOMEM;
		goto err;
	}

	double *target3 = zalloc(sizeof(*target3) * arr_size);
	if (target3 == NULL) {
		printf("Can't initialise 'target3'\n");
		status = -ENOMEM;
		goto err;
	}

	for (i = 0; i < arr_size; i++) {
		source[i] = drand();
	}

	copy_arr(source, target1, arr_size);
	copy_ptr(source, target2, arr_size);
	copy_ptrs(source, target3, source + arr_size);

	printf("iter\toriginal\t\tcopy_arr\t\tcopy_ptr\t\tcopy_ptrs\n");

	for (i = 0; i < arr_size; i++) {
		printf("%d\t%f\t\t%f\t\t%f\t\t%f\n", i, source[i], target1[i],
		       target2[i], target3[i]);
	}

	free(target3);
	free(target2);
	free(target1);
	free(source);

err:
	return status;
}
