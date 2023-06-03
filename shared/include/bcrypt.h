#pragma once

char *bcrypt(const char *phrase, const char *salt);

/*
#include <stdint.h>
#include <stdlib.h>
int hash_password(char *password, size_t pass_len, 
	char *salt, size_t salt_len);
*/