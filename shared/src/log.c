#include "log.h"
#include <stdlib.h>
#include <syslog.h>

void log_stop()
{
	closelog();
}

int log_init(const char *ident)
{
	atexit(log_stop);
	openlog(ident, LOG_PERROR | LOG_CONS, 0);
	return 0;
}

int log_0(const char *msg)
{
	return 0;
}

int log_1(const char *msg)
{
	return -1;
}

int log_2(const char *msg)
{
	return -2;
}

int log_3(const char *msg)
{
	return -3;
}

int log_4(const char *msg)
{
	return -4;
}

int log_5(const char *msg)
{
	return -5;
}

int log_6(const char *msg)
{
	return -6;
}