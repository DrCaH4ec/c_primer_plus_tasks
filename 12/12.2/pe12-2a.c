#include "pe12-2a.h"

static int8_t mode;
const static char *mode_name[] = { "metric", "imperial" };
const static char *mode_vol_name[] = { "liters", "gallons" };
const static char *mode_dist_name[] = { "kilometers", "miles" };

static double dist;
static double vol;

void set_mode(int8_t tmp_mode)
{
	switch (tmp_mode) {
	case METRIC_MODE:
	case IMPERIAL_MODE:
		mode = tmp_mode;
		break;

	default:
		printf("Invalid mode specified. Mode %d(%s) used.\n", mode,
		       mode_name[mode]);
		break;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void get_info(void)
{
dist_again:
	printf("Enter distance traveled in %s: ", mode_dist_name[mode]);
	if (scanf("%lf", &dist) != 1)
		printf("scanf err\n");

	if (dist <= 0) {
		printf("Bad value of distance! Must be bigger than 0.\n");
		goto dist_again;
	}

vol_again:
	printf("Enter fuel consumed in %s: ", mode_vol_name[mode]);
	if (scanf("%lf", &vol) != 1)
		printf("scanf err\n");

	if (vol <= 0) {
		printf("Bad value of volume! Must be bigger than 0.\n");
		goto vol_again;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void show_info(void)
{
	printf("Fuel consuption is ");
	switch (mode) {
	case METRIC_MODE:
		printf("%f %s per 100 %s\n", vol * 100 / dist,
		       mode_vol_name[mode], mode_dist_name[mode]);
		break;

	case IMPERIAL_MODE:
		printf("%f %s per %s\n", dist / vol, mode_dist_name[mode],
		       mode_vol_name[mode]);
		break;
	}
}
