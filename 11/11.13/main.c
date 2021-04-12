#include <stdio.h>

int main(int argc, char const *argv[])
{
	while (argc--) {
		printf("%s ", argv[argc]);
	}
	printf("\n");

	return 0;
}
