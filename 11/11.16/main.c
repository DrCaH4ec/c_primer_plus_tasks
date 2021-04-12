#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <math.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "prot.h"

#define LENGTH_OF_STRING 10000

int main(int argc, char *argv[])
{
	int status = 0;
	size_t i;
	int c;
	int res;

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

	while ((res = getopt(argc, argv, "pul")) != -1) {
		switch (res) {
		case 'l':
			str_tolower(text);
			goto print;
			break;

		case 'u':
			str_toupper(text);
			goto print;
			break;

		case 'p':
		default:
			goto print;
			break;
		}
	}

print:
	printf("\n%s\n", text);

err:
	free(text);
	return status;
}
