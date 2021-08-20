#include "philo.h"

void	*start_philo(void *arg)
{
	forks_init(arg);
	while (!is_dead(arg))
	{
		get_forks(arg);
		eating(arg);
		release_forks(arg);
		sleeping(arg);
		thinking(arg);
	}
	return (NULL);
}

void	print_status(t_data *data, int idx, int64_t msec)
{
	printf(data->phi->format[idx], msec, data->phi->width, data->num);
}

int64_t	get_msec()
{
	t_time	tv;

	gettimeofday(&tv, NULL);
	return ((int64_t)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
