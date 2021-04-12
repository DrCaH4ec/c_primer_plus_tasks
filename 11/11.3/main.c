#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <math.h>
#include <string.h>

#include "prot.h"

#define MAX_WORD_SIZE 255

int main(void)
{
	int status = 0;

	char *text = zalloc(sizeof(*text) * MAX_WORD_SIZE);
	if (text == NULL) {
		printf("Can't initialise 'text'\n");
		status = -ENOMEM;
		goto err;
	}
	printf("Enter the text:\n");

	read_word(text, MAX_WORD_SIZE);

	printf("Printed string is '%s'\n", text);

	free(text);

err:
	return status;
}
