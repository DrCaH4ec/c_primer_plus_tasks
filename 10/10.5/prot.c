#include "prot.h"

void *zalloc(size_t size)
{
	void *p;
	p = malloc(size);

	if (p == NULL)
		return p;

	memset(p, 0, size);
	return p;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

double diff_btw_min_and_max(double *source, uint8_t size)
{
	size--;
	double min = source[size];
	double max = source[size];

	while (size--) {
		min = MIN(min, source[size]);
		max = MAX(min, source[size]);
	}

	printf("max is %f\n", max);
	printf("min is %f\n", min);

	return (max - min);
}
