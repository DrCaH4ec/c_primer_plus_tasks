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

	double *aver = zalloc(arr_rows * sizeof(*aver));
	if (aver == NULL) {
		printf("Can't initialise 'aver'\n");
		status = -ENOMEM;
		goto err;
	}

	for (i = 0; i < arr_rows; i++) {
		for (j = 0; j < arr_cols; j++) {
			printf("source[%d][%d] = ", i, j);

			while (scanf("%lf", &(source[i][j])) != 1) {
				for (int c = getchar(); c != '\n' && c != EOF;
				     c = getchar())
					; //cleaning buffer

				printf("try again.\n");
				printf("source[%d][%d] = ", i, j);
			}
		}
	}

	print_matrix(source, arr_rows, arr_cols);

	for (i = 0; i < arr_rows; i++) {
		aver[i] = average(source[i], arr_cols);
		printf("aver[%d] = %f\n", i, aver[i]);
	}

	printf("general average = %f\n", average(aver, arr_rows));
	printf("max val is %f\n", find_max(source, arr_rows, arr_cols));

	free(aver);
	cfree((void **)source, arr_rows);

err:
	return status;
}
