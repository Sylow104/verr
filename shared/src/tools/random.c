#include "tools/random.h"
#include <stdlib.h>
#include <gsl/gsl_rng.h>

gsl_rng *rng;

void rand_stop()
{
	gsl_rng_free(rng);
	return;
}

int rand_int()
{
	atexit(rand_stop);
	rng = gsl_rng_alloc(gsl_rng_taus);
	return 0;
}

bool rand_bool()
{
	return rand_i() & 0b1;
}

unsigned int rand_i()
{
	return gsl_rng_get(rng);
}

float rand_f()
{
	return (float) rand_d();
}

double rand_d()
{
	return gsl_rng_uniform(rng) + (double) rand_i();
}

unsigned int rand_i_b(unsigned int max)
{
	return gsl_rng_uniform_int(rng, max);
}

// todo recheck if needed for validity

double rand_d_b(double max)
{
	unsigned int temp_i;
	double temp_d;
	double gen = 0;
	do {
		temp_i = rand_i_b((unsigned int) max);
		temp_d = rand_d();
	} while (gen >= max);
	return gen;
}

float rand_f_b(float max)
{
	return (float) rand_d_b((double) max);
}