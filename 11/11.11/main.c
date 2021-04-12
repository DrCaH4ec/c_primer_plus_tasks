#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <math.h>
#include <string.h>
#include <fcntl.h>

#include "prot.h"

#define LENGTH_OF_STRING 255
#define MAX_NUM_OF_STRINGS 255

#define TOTAL_LENGTH_SYM 'l'
#define FIRST_WORD_LENGTH_SYM 'w'
#define ASCII_SYM 'a'
#define QUIT_SYM 'q'

int main(int argc, char const *argv[])
{
	int status = 0;
	uint8_t num_of_strings;

	if (argc != 2) {
		printf("Not enough arguments!\n");
		printf("USAGE IS:\n");
		printf("\t./main [num_of_strings]\n");
		status = -EINVAL;
		goto err;
	}

	if (atoi(argv[1]) <= 0 || atoi(argv[1]) > MAX_NUM_OF_STRINGS) {
		printf("Bad num_of_strings! Must be in range [1:%d]\n",
		       MAX_NUM_OF_STRINGS);
		status = -EINVAL;
		goto err;
	}
	num_of_strings = atoi(argv[1]);

	char **text = (char **)czalloc(num_of_strings, LENGTH_OF_STRING,
				       sizeof(**text));
	if (text == NULL) {
		printf("Can't initialise 'text'\n");
		status = -ENOMEM;
		goto err;
	}

	for (uint8_t i = 0; i < 3; i++) {
		if (gets(text[i], LENGTH_OF_STRING) == NULL)
			break;
	}

	for (uint8_t i = 0; i < num_of_strings; i++)
		printf("'%s'\n", text[i]);

try_again:
	printf("%c - sort by total length\n", TOTAL_LENGTH_SYM);
	printf("%c - sort by length of first word\n", FIRST_WORD_LENGTH_SYM);
	printf("%c - sort by ascii\n", ASCII_SYM);
	printf("%c - quit\n", QUIT_SYM);
	printf("Choose the option: ");

	switch (getchar()) {
	case TOTAL_LENGTH_SYM:
		length_sort(text, num_of_strings);
		break;

	case FIRST_WORD_LENGTH_SYM:
		first_word_length_sort(text, num_of_strings);
		break;

	case ASCII_SYM:
		ascii_sort(text, num_of_strings);
		break;

	case QUIT_SYM:
		break;

	default:
		for (int c = getchar(); c != '\n' && c != EOF; c = getchar())
			; //cleaning buffer
		printf("Please try again\n");
		goto try_again;
	}

	printf("*************************************\n");
	for (uint8_t i = 0; i < num_of_strings; i++)
		printf("'%s'\n", text[i]);

	cfree((void **)text, num_of_strings);
err:
	return status;
}
