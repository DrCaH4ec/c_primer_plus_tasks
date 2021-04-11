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
	uint8_t first_to_copy;
	uint8_t ammount_to_copy;
	uint8_t i;

	if (argc != 4) {
		printf("Not enough arguments!\n");
		printf("USAGE IS:\n");
		printf("\t./main [size_of_array] [first_el_to_copy] [ammount_to_copy]\n");
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

	if (atoi(argv[2]) <= 0 || atoi(argv[2]) > arr_size) {
		printf("Bad first_to_copy! Must be less than 'arr_size'\n");
		status = -EINVAL;
		goto err;
	}
	first_to_copy = atoi(argv[2]);

	if (atoi(argv[3]) <= 0 || atoi(argv[3]) > (arr_size - first_to_copy)) {
		printf("Bad size_of_array! Must be less than ('arr_size' - 'first_to_copy')\n");
		status = -EINVAL;
		goto err;
	}
	ammount_to_copy = atoi(argv[3]);

	double *source = zalloc(sizeof(*source) * arr_size);
	if (source == NULL) {
		printf("Can't initialise 'source'\n");
		status = -ENOMEM;
		goto err;
	}

	double *dest = zalloc(sizeof(*dest) * ammount_to_copy);
	if (source == NULL) {
		printf("Can't initialise 'dest'\n");
		status = -ENOMEM;
		goto err;
	}

	for (i = 0; i < arr_size; i++) {
		source[i] = drand();
		printf("%f\n", source[i]);
	}

	copy(source, dest, first_to_copy, ammount_to_copy);
	printf("**************************************\n");

	for (i = 0; i < ammount_to_copy; i++) {
		printf("%f\n", dest[i]);
	}

	free(source);

err:
	return status;
}
