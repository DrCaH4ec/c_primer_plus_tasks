#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <math.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

int main(void)
{
	int status = 0;
	uint32_t num_of_words = 0;
	uint32_t i, j;
	char **array;
	char word[MAX_WORD_LENGTH] = { 0 };

	printf("How many words do you wanna to enter? ");
	if (scanf("%u", &num_of_words) != 1) {
		printf("Bad number of words\n");
		status = -EINVAL;
		goto err;
	}

	array = malloc(sizeof(array) * num_of_words);
	if (array == NULL) {
		status = -ENOMEM;
		goto err;
	}

	printf("Now enter %d words:\n", num_of_words);
	getchar();
	for (i = 0; i < num_of_words; i++) {
		j = 0;
		while ((word[j] = getchar()) != ' ' && word[j] != '\n' &&
		       j++ < MAX_WORD_LENGTH);

		if (word[j] == '\n' || word[j] == ' ')
			word[j] = '\0';

		array[i] = strndup(word, j);
		memset(word, 0, MAX_WORD_LENGTH);
	}

	printf("There are the entered words:\n");
	for (i = 0; i < num_of_words; i++)
		printf("%s\n", array[i]);

	for (i = 0; i < num_of_words; i++)
		free(array[i]);

	free(array);

err:
	return status;
}
