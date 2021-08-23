#include "philo.h"

void	mymsleep(int64_t msec)
{
	register int64_t	sleeptime;
	register int64_t	start;

	if (!msec)
		return ;
	start = get_usec();
	sleeptime = msec * 1000;
	while (get_usec() - start < sleeptime - 1000)
		usleep(1000);
	sleeptime = start + sleeptime - get_usec();
	if (sleeptime > 0)
		usleep(sleeptime);
}
