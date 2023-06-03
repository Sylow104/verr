#include "random.h"
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

unsigned float rand_f()
{
	return (unsigned float) rand_d();
}

unsigned double rand_d()
{
	return gsl_rng_uniform(rng) + (unsigned double) rand_i();
}

unsigned int rand_i_b(unsigned int max)
{
	return gsl_rng_uniform_int(rng, max);
}

// todo recheck if needed for validity

unsigned double rand_d_b(unsigned double max)
{
	unsigned int temp_i;
	unsigned double temp_d;
	unsigned double gen = 0;
	do {
		temp_i = rand_i_b((unsigned int) max);
		temp_d = rand_d();
	} while (gen >= max);
	return gen;
}

unsigned float rand_f_b(unsigned float max)
{
	return (unsigned float) rand_d_b((unsigned double) max);
}