#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <math.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	int status = 0;
	char c;
	FILE *f;

	if (argc == 1) {
		printf("Not enough arguments!\n");
		printf("USAGE IS:\n");
		printf("\t./main [in_file(s)]\n");
		status = -EINVAL;
		goto err;
	}

	argc--;
	for (; argc > 0; argc--) {
		f = fopen(argv[argc], "r");
		if (f == NULL) {
			printf("Can't open the file '%s'\n", argv[argc]);
			status = -EINVAL;
			goto err;
		}

		printf("*****file '%s'\n", argv[argc]);
		while ((c = fgetc(f)) != EOF)
			printf("%c", c);

		fclose(f);
	}

err:
	return status;
}
