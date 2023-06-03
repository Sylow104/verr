#pragma once
#include "bcrypt.h"
#include <stdbool.h>

// assuming everything is char string based
// we can implement in gcrypt but that's for later

// assume that we will use malloc for these calls
// so please deallocate them with free once done
// or we get a memory leak

char *raw_to_md5(const char *to_hash);
char *md5_to_sha256(const char *to_convert);
char *sha256_to_mid5(const char *to_convert);
char *hash(const char *to_hash);
bool check(const char *unhashed, char *hashed);