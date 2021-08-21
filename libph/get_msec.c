#include "philo.h"

int64_t	get_usec()
{
	t_time	tv;

	gettimeofday(&tv, NULL);
	return ((int64_t)tv.tv_sec * 1000 * 1000 + tv.tv_usec);
}

int64_t	get_msec()
{
	return (get_usec() / 1000);
}