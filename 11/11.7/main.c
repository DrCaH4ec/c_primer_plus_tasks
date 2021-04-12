#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <math.h>
#include <string.h>

#include "prot.h"

#define MAX_COPY_SIZE 255

int main(int argc, char const *argv[])
{
	int status = 0;
	uint16_t copy_size;

	if (argc != 3) {
		printf("Not enough arguments!\n");
		printf("USAGE IS:\n");
		printf("\t./main [string] [num_of_symbols]\n");
		status = -EINVAL;
		goto err;
	}

	if (atoi(argv[2]) <= 0 || atoi(argv[2]) > MAX_COPY_SIZE) {
		printf("Bad num_of_symbols! Must be in range [1:%d]\n",
		       MAX_COPY_SIZE);
		status = -EINVAL;
		goto err;
	}
	copy_size = atoi(argv[2]);

	char *text = zalloc(sizeof(*text) * MAX_COPY_SIZE);
	if (text == NULL) {
		printf("Can't initialise 'text'\n");
		status = -ENOMEM;
		goto err;
	}


	printf("Copied string is '%s'\n", mystrncpy(text, argv[1], copy_size));


	free(text);
err:
	return status;
}
