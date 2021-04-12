#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <math.h>
#include <string.h>
#include <fcntl.h>

#include "prot.h"

#define LENGTH_OF_STRING 10000

int main(int argc, char const *argv[])
{
	int status = 0;
	size_t i;
	int c;

	char *text = zalloc(LENGTH_OF_STRING * sizeof(*text));
	if (text == NULL) {
		printf("Can't initialise 'text'\n");
		status = -ENOMEM;
		goto err;
	}

	for (c = getchar(), i = 0; i < LENGTH_OF_STRING && c != EOF;
	     c = getchar(), i++) {
		text[i] = c;
	}

	printf("\n'%s'\n", text);

	printf("*************************************\n");
	printf("Num of uppercases is %d\n", num_of_upper(text));
	printf("Num of lowercases is %d\n", num_of_lower(text));
	printf("Num of punctuation marks is %d\n", num_of_punct(text));
	printf("Num of words is %d\n", num_of_words(text));
	printf("Num of digits is %d\n", num_of_digits(text));

	free(text);
err:
	return status;
}
