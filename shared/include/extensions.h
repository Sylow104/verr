#pragma once
#include <stdint.h>
#include <stdbool.h>

int levenshtein_dist(char *str, size_t str_len,
	char *comp, size_t comp_len,
	bool case_sens);

size_t rand_ind(size_t min_bound, size_t max_bound);
float rand_bound_f(float min, float max);

// not too sure what invarients are
char *to_invar_f(float f, char fmt);
char *to_invar_d(double d, char fmt);