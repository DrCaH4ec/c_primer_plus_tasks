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

	if (argc != 3) {
		printf("Not enough arguments!\n");
		printf("USAGE IS:\n");
		printf("\t./main [in_file] [out_file]\n");
		status = -EINVAL;
		goto err;
	}

	FILE *infile = fopen(argv[1], "r");
	if (infile == NULL) {
		printf("Can't open the file '%s'\n", argv[1]);
		status = -EINVAL;
		goto err;
	}

	FILE *outfile = fopen(argv[2], "w");
	if (infile == NULL) {
		printf("Can't open the file '%s'\n", argv[2]);
		status = -EINVAL;
		goto err;
	}

	while ((c = fgetc(infile)) != EOF)
		fputc(c, outfile);

	fclose(infile);
	fclose(outfile);

err:
	return status;
}
