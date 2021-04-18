#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <math.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int main(int argc, const char *argv[])
{
	int status = 0;
	FILE *f;
	uint32_t counter = 0;
	char c;
	char sought_sym;

	if (argc == 1) {
		printf("Not enough arguments!\n");
		printf("USAGE IS:\n");
		printf("\t./main [symbol] [in_file(s)](optional)\n");
		status = -EINVAL;
		goto err;
	}

	sought_sym = argv[1][0];

	if (argc > 2) {
		while (--argc > 1) {
			counter = 0;
			f = fopen(argv[argc], "r");
			if (f == NULL) {
				printf("Can't open the file '%s'\n",
				       argv[argc]);
				continue;
			}

			while ((c = fgetc(f)) != EOF)
				counter = (c == sought_sym) ? counter + 1 :
							      counter;

			printf("In file '%s' symbol '%c' exists %u times\n",
			       argv[argc], sought_sym, counter);

			fclose(f);
		}
	} else {
		printf("Enter a string:\n");

		while ((c = getchar()) != EOF && c != '\n')
			counter = (c == sought_sym) ? counter + 1 : counter;

		printf("In 'stdin' symbol '%c' exists %u times\n", sought_sym,
		       counter);
	}

err:
	return status;
}
