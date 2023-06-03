#pragma once
#include <stdbool.h>
// using gsl for randomization
// assume that rand_bool can determine signages, but for now
// assume returned RANDOM numbers are unsigned
// use helper functions (TODO) to housekeep on signing of numbers

int rand_init();

bool rand_bool();

unsigned int rand_i();
unsigned float rand_f();
unsigned double rand_d();

unsigned int rand_i_b(unsigned int max);
unsigned float rand_f_b(unsigned float max);
unsigned double rand_d_b(unsigned double max);
