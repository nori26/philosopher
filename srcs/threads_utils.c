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
	pthread_mutex_lock(&data->phi->output);
	printf(data->phi->format[idx], msec, data->phi->width, data->num);
	pthread_mutex_unlock(&data->phi->output);
}
