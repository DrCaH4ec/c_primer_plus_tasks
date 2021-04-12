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

	if (argc != 3) {
		printf("Not enough arguments!\n");
		printf("USAGE IS:\n");
		printf("\t./main [string] [search_string]\n");
		status = -EINVAL;
		goto err;
	}

	printf("Search string is '%s'\n", string_in(argv[1], argv[2]));

err:
	return status;
}
