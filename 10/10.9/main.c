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
	uint8_t arr_cols;
	uint8_t arr_rows;
	uint8_t i, j;

	if (argc != 3) {
		printf("Not enough arguments!\n");
		printf("USAGE IS:\n");
		printf("\t./main [rows] [cols]\n");
		status = -EINVAL;
		goto err;
	}

	if (atoi(argv[1]) <= 0 || atoi(argv[1]) > MAX_ARR_SIZE) {
		printf("Bad rowspan! Must be in range [1:%d]\n", MAX_ARR_SIZE);
		status = -EINVAL;
		goto err;
	}
	arr_rows = atoi(argv[1]);

	if (atoi(argv[2]) <= 0 || atoi(argv[2]) > MAX_ARR_SIZE) {
		printf("Bad colspan! Must be in range [1:%d]\n", MAX_ARR_SIZE);
		status = -EINVAL;
		goto err;
	}
	arr_cols = atoi(argv[2]);

	double **source =
		(double **)czalloc(arr_rows, arr_cols, sizeof(**source));
	if (source == NULL) {
		printf("Can't initialise 'source'\n");
		status = -ENOMEM;
		goto err;
	}

	double **dest = (double **)czalloc(arr_rows, arr_cols, sizeof(**dest));
	if (source == NULL) {
		printf("Can't initialise 'dest'\n");
		status = -ENOMEM;
		goto err;
	}

	for (i = 0; i < arr_rows; i++)
		for (j = 0; j < arr_cols; j++)
			source[i][j] = drand();

	print_matrix(source, arr_rows, arr_cols);

	copy_matrix(source, dest, arr_rows, arr_cols);
	printf("*********************************\n");

	print_matrix(dest, arr_rows, arr_cols);

	cfree((void **)dest, arr_rows);
	cfree((void **)source, arr_rows);

err:
	return status;
}
