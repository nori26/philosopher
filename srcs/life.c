#include "philo.h"

void	actions(t_data *data, int action, int64_t sleeptime, int64_t now)
{
	if (is_dead(data))
		return ;
	print_status(data, action, now);
	mymsleep(sleeptime);
}

void	eating(t_data *data)
{
	int64_t	now;

	now = start_time_init(data);
	actions(data, EAT, data->phi->eat, now);
}

void	sleeping(t_data *data)
{
	actions(data, SLEEP, data->phi->sleep, get_msec());
}

void	thinking(t_data *data)
{
	actions(data, THINK, 0, get_msec());
}

int64_t	start_time_init(t_data *data)
{
	return ((int64_t)mtx_do_func(data, &data->mstart, store_start_time));
}

int64_t	store_start_time(t_data *data)
{
	data->start = get_msec();
	return (data->start);
}
