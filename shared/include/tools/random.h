#pragma once
#include <stdbool.h>
// using gsl for randomization
// assume that rand_bool can determine signages, but for now
// assume returned RANDOM numbers are unsigned
// use helper functions (TODO) to housekeep on signing of numbers

int rand_init();

bool rand_bool();

unsigned int rand_i();
float rand_f();
double rand_d();

unsigned int rand_i_b(unsigned int max);
float rand_f_b(float max);
double rand_d_b(double max);
