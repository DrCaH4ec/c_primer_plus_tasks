#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <math.h>
#include <string.h>

#include "prot.h"

int main(int argc, char const *argv[])
{
	int status = 0;

	if (argc != 2) {
		printf("Not enough arguments!\n");
		printf("USAGE IS:\n");
		printf("\t./main [string]\n");
		status = -EINVAL;
		goto err;
	}

	char *text = zalloc(sizeof(*text) * strlen(argv[1]) + 1);
	if (text == NULL) {
		printf("Can't initialise 'text'\n");
		status = -ENOMEM;
		goto err;
	}

	strcpy(text, argv[1]);

	printf("Normal string is '%s'\n", text);

	printf("Mirrored string is '%s'\n", xchng(text));

	free(text);
err:
	return status;
}
