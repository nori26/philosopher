#include "philo.h"

void	mymsleep(int64_t msec)
{
	int64_t	usec;

	if (!msec)
		return ;
	usec = msec * 1000;
	while (usec > 1000)
	{
		usleep(1000);
		usec -= 1000;
	}
	usleep(usec);
}
