#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <stdlib.h>

uint32_t foo(void)
{
	static uint32_t counter;
	return counter++;
}

int main(int argc, const char *argv[])
{
	int status = 0;

	if (argc != 2) {
		printf("Not enough arguments!\n");
		printf("USAGE IS:\n");
		printf("\t./main [number_of_calls]\n");
		status = -EINVAL;
		goto err;
	}

	for (uint32_t i = 0; i < atoi(argv[1]); i++)
		foo();

	printf("Num of calls is %u\n", foo());

err:
	return status;
}
