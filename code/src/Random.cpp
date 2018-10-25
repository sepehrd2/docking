#include <iostream>
#include "Random.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>       /* sqrt */

double uniform()
{
	srand (time(NULL));
	return (rand()/RAND_MAX);
}
double gaussian()
{
	double v1, v2, R;
	v1 = 2 * uniform() - 1.0;
	v2 = 2 * uniform() - 1.0;
	do
	{
		R = v1 * v1 + v2 * v2;
	} while (R > 1.0 || R < 1.523e-8);
	return (v1 * sqrt(-2.0 * log(R) / R));
}
