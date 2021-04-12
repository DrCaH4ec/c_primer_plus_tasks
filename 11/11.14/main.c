#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int status = 0;
	double base;
	double power;

	if (argc != 3) {
		printf("Not enough arguments!\n");
		printf("USAGE IS:\n");
		printf("\t./main [base] [exp]\n");
		status = -EINVAL;
		goto err;
	}

	base = atof(argv[1]);
	power = atoi(argv[2]);

	printf("%f\n", pow(base, power));

err:
	return status;
}
