#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <math.h>
#include <string.h>

#define MAX_STRING_LENGTH 200

int main(int argc, const char *argv[])
{
	int status = 0;
	FILE *f;
	uint32_t pos;
	char c;
	char str[MAX_STRING_LENGTH];

	if (argc != 2) {
		printf("Not enough arguments!\n");
		printf("USAGE IS:\n");
		printf("\t./main [in_file]\n");
		status = -EINVAL;
		goto err;
	}

	f = fopen(argv[1], "r");
	if (f == NULL) {
		printf("Can't open the file '%s'\n", argv[1]);
		status = -EINVAL;
		goto err;
	}

	while (1) {
		printf("Enter a position(negative value or non-number to exit): ");
		if (scanf("%u", &pos) != 1 || pos < 0)
			goto err;

		if (fseek(f, pos - 1, SEEK_SET))
			goto err;

		while ((c = fgetc(f)) != '\n')
			printf("%c", c);

		printf("\n");

		printf("%s", fgets(str, MAX_STRING_LENGTH, f));
	}

	fclose(f);
err:
	return status;
}
