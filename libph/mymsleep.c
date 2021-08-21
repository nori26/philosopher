#include "philo.h"

void	mymsleep(int64_t msec)
{
	int64_t	usec;

	if (!msec)
		return ;
	usec = msec * 1000;
	int64_t t = get_msec();
	while (usec > 1000)
	{
		usleep(1000);
		usec -= 1000;
	}
	printf("now %ld\n", get_msec() - t);
	usleep(usec);
}
