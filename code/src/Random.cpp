#include <iostream>
#include "Random.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>       /* sqrt */

double uniform()
{
	srand (time(NULL) + rand());
	return (rand()/(RAND_MAX + 1.0));
}
double gaussian()
{
	double v1, v2, R;

	do
	{
		v1 = 2.0 * uniform() - 1.0;
		v2 = 2.0 * uniform() - 1.0;
		R = v1 * v1 + v2 * v2;
	} while (R > 1.0 || R < 1.523e-8);
	return (v1 * sqrt(-2.0 * log(R) / R));
}
