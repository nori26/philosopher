#include "philo.h"

void	mymsleep(int64_t msec)
{
	int64_t	usec;

	if (!msec)
		return ;
	usec = msec * 1000;
	int64_t t = get_msec();
	while (usec > 100000)
	{
		usleep(100000);
		usec -= 100000;
	}
	usleep(usec);
	printf("now %ld\n", (long)(get_msec() - t));
}
