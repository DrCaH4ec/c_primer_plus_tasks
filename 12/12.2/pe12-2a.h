#ifndef _PE12_2A_H_
#define _PE12_2A_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define METRIC_MODE 0
#define IMPERIAL_MODE 1

void set_mode(int8_t tmp_mode);

void get_info(void);

void show_info(void);

/*_PE12_2A_H_*/
#endif
