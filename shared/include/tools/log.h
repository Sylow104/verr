#pragma once
#include <stdarg.h>

// 0 debug
// 1 info
// 2 status
// 3 warning
// 4 error
// 5 exception
// 6 unimplemented 

int log_init();
int log_0(const char *msg);
int log_1(const char *msg);
int log_2(const char *msg);
int log_3(const char *msg);
int log_4(const char *msg);
int log_5(const char *msg);
int log_6(const char *msg);
