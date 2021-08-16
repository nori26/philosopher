#include "philo.h"
int g;
void	*start_philo(void *arg)
{
	t_phi	*philo;

	philo = arg;
	print_status(philo);
	return (NULL);
	(void)philo;
}

void	print_status(t_phi *philo)
{
	int g2;
	int64_t	timestamp;

	g2 = g++;
	timestamp = get_msec();
	while (get_msec() - timestamp < 10000)
	{
		printf("%d %ld eating\n", g2, timestamp);
		sleep(1);
	}
	(void)philo;
}

int64_t	get_msec()
{
	t_time	tv;

	gettimeofday(&tv, NULL);
	return ((int64_t)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
