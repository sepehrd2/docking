#include <iostream>
#include "Monte_Carlo.h"
#include <math.h>       /* exp */


bool metropolis_accept(const float & old_f,\
 	const float & new_f,\
	const float & temperature) {
	if(new_f < old_f) return true;
	const float acceptance_probability = exp((old_f - new_f) / temperature);
	return uniform() < acceptance_probability;
}
