#include "philo.h"

void	sleeping(t_data *data)
{
	actions(data, SLEEP, data->phi->sleep, get_msec());
}

void	thinking(t_data *data)
{
	actions(data, THINK, 0, get_msec());
}

void	actions(t_data *data, int action, int64_t sleeptime, int64_t now)
{
	if (is_dead(data) || !is_hungry(data))
		return ;
	print_status(data, action, now);
	mymsleep(sleeptime);
}

void	print_status(t_data *data, int idx, int64_t msec)
{
	pthread_mutex_lock(&data->phi->output);
	printf(data->phi->format[idx], msec, data->phi->width, data->num);
	pthread_mutex_unlock(&data->phi->output);
}
