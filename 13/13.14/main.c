#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STRING_LENGTH 200
#define WIDTH 30
#define HEIGHT 20

#define MAX(x, y) (x > y) ? (x) : (y)
#define MIN(x, y) (x < y) ? (x) : (y)

bool cmp(int a, int b);

uint8_t move_up(uint8_t x);

uint8_t move_down(uint8_t x);

uint8_t move_left(uint8_t y);

uint8_t move_right(uint8_t y);

uint8_t num_of_dir(uint8_t x, uint8_t y);

const char conv[] = { ' ', '.', '\'', ':', '~', '*', '=', '?', '%', '#' };

int main(int argc, const char *argv[])
{
	int status = 0;
	FILE *f;
	uint32_t i, j;
	uint8_t array[20][30];
	char c;
	uint8_t sum = 0;
	bool up_flag = false;
	bool down_flag = false;
	bool left_flag = false;
	bool right_flag = false;

	if (argc != 2) {
		printf("Not enough arguments!\n");
		printf("USAGE IS:\n");
		printf("\t./main [in_file]\n");
		status = -EINVAL;
		goto err;
	}

	f = fopen(argv[1], "r");
	if (f == NULL) {
		printf("Can't open the file '%s'\n", argv[2]);
		status = -EINVAL;
		goto err;
	}

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			c = fgetc(f);

			if (c == '\n')
				break;

			if (c == ' ')
				j--;
			else
				array[i][j] = c - '0';
		}
		fgetc(f);
	}

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			sum = 0;

			up_flag = false;
			down_flag = false;
			left_flag = false;
			right_flag = false;

			if (move_up(i)) {
				up_flag = cmp(array[i][j], array[i - 1][j]);
				sum += array[i - 1][j];
			}

			if (move_down(i)) {
				down_flag = cmp(array[i][j], array[i + 1][j]);
				sum += array[i + 1][j];
			}

			if (move_left(j)) {
				left_flag = cmp(array[i][j], array[i][j - 1]);
				sum += array[i][j - 1];
			}

			if (move_right(j)) {
				right_flag = cmp(array[i][j], array[i][j + 1]);
				sum += array[i][j + 1];
			}

			if (up_flag || down_flag || left_flag || right_flag)
				array[i][j] = sum / num_of_dir(i, j);
		}
	}

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++)
			printf("%c", conv[array[i][j]]);

		printf("\n");
	}

	fclose(f);
err:
	return status;
}

bool cmp(int a, int b)
{
	return (MAX(a, b) - MIN(a, b)) > 1;
}

uint8_t move_up(uint8_t x)
{
	return (x > 0) ? 1 : 0;
}

uint8_t move_down(uint8_t x)
{
	return (x < (HEIGHT - 1)) ? 1 : 0;
}

uint8_t move_left(uint8_t y)
{
	return (y > 0) ? 1 : 0;
}

uint8_t move_right(uint8_t y)
{
	return (y < (WIDTH - 1)) ? 1 : 0;
}

uint8_t num_of_dir(uint8_t x, uint8_t y)
{
	return move_up(x) + move_down(x) + move_right(y) + move_left(y);
}
