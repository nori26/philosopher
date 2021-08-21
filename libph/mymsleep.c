#include "philo.h"

void	mymsleep(int64_t msec)
{
	register int64_t	usec;
	register int64_t	start;

	if (!msec)
		return ;
	start = get_usec();
	usec = msec * 1000;
	// while (get_usec() - start < usec)
	while (get_msec() * 1000 - start < usec)
		usleep(1000);
}
