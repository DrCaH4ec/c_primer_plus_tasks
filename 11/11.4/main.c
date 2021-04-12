#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <math.h>
#include <string.h>

#include "prot.h"

#define MAX_WORD_SIZE 255

int main(int argc, char const *argv[])
{
	int status = 0;
	uint8_t word_size;

	if (argc != 2) {
		printf("Not enough arguments!\n");
		printf("USAGE IS:\n");
		printf("\t./main [word_size]\n");
		status = -EINVAL;
		goto err;
	}

	if (atoi(argv[1]) <= 0 || atoi(argv[1]) > MAX_WORD_SIZE) {
		printf("Bad size_of_array! Must be in range [1:%d]\n",
		       MAX_WORD_SIZE);
		status = -EINVAL;
		goto err;
	}
	word_size = atoi(argv[1]);

	char *text = zalloc(sizeof(*text) * word_size);
	if (text == NULL) {
		printf("Can't initialise 'text'\n");
		status = -ENOMEM;
		goto err;
	}
	printf("Enter the text:\n");

	read_word(text, word_size);

	printf("Printed string is '%s'\n", text);

	free(text);

err:
	return status;
}
