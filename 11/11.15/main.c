#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <stdbool.h>

#include "prot.h"

int main(int argc, char const *argv[])
{
	int status = 0;

	if (argc != 2) {
		printf("Not enough arguments!\n");
		printf("USAGE IS:\n");
		printf("\t./main [int number]\n");
		status = -EINVAL;
		goto err;
	}

	printf("%d\n", my_atoi(argv[1]));

err:
	return status;
}
