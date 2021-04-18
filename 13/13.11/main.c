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
	char str[MAX_STRING_LENGTH];

	if (argc != 3) {
		printf("Not enough arguments!\n");
		printf("USAGE IS:\n");
		printf("\t./main [string] [in_file]\n");
		status = -EINVAL;
		goto err;
	}

	f = fopen(argv[2], "r");
	if (f == NULL) {
		printf("Can't open the file '%s'\n", argv[2]);
		status = -EINVAL;
		goto err;
	}

	while (fgets(str, MAX_STRING_LENGTH, f) != NULL) {
		if (strstr(str, argv[1]) != NULL)
			printf("%s\n", str);
	}

	fclose(f);
err:
	return status;
}
