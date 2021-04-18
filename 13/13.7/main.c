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
	char str_1[MAX_STRING_LENGTH];
	char str_2[MAX_STRING_LENGTH];
	char *p_1;
	char *p_2;

	if (argc != 3) {
		printf("Not enough arguments!\n");
		printf("USAGE IS:\n");
		printf("\t./main [in_file_1] [in_file_2]\n");
		status = -EINVAL;
		goto err;
	}

	FILE *f_1 = fopen(argv[1], "r");
	if (f_1 == NULL) {
		printf("Can't open the file '%s'\n", argv[1]);
		status = -EINVAL;
		goto err;
	}

	FILE *f_2 = fopen(argv[2], "r");
	if (f_2 == NULL) {
		printf("Can't open the file '%s'\n", argv[2]);
		fclose(f_1);
		status = -EINVAL;
		goto err;
	}

	p_1 = fgets(str_1, MAX_STRING_LENGTH, f_1);
	p_2 = fgets(str_2, MAX_STRING_LENGTH, f_2);

	while (!feof(f_1) || !feof(f_2)) {
		if ((p_1 != NULL) && (p_2 != NULL)) {
			str_1[strlen(str_1) - 1] = '\0';
			printf("%s %s", str_1, str_2);
			p_1 = fgets(str_1, MAX_STRING_LENGTH, f_1);
			p_2 = fgets(str_2, MAX_STRING_LENGTH, f_2);
		} else if (p_1 != NULL) {
			printf("%s", str_1);
			p_1 = fgets(str_1, MAX_STRING_LENGTH, f_1);
		} else {
			printf("%s", str_2);
			p_2 = fgets(str_2, MAX_STRING_LENGTH, f_2);
		}
	}

	fclose(f_1);
	fclose(f_2);

err:
	return status;
}
