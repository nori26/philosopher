#include "philo.h"

void	eating(t_data *data)
{
	int64_t	now;

	now = start_time_init(data);
	printf("now %ld\n", (long)(get_usec()));
	actions(data, EAT, data->phi->eat, now);
}

int64_t	start_time_init(t_data *data)
{
	return ((int64_t)mtx_do_func(data, &data->mtxstart, store_start_time));
}

int64_t	store_start_time(t_data *data)
{
	data->start = get_msec();
	return (data->start);
}
