#include "philo.h"

void	eating(t_data *data)
{
	actions(data, EAT, data->phi->eat);
	inc_eatcount(data);
}

int64_t	start_time_init(t_data *data)
{
	return (mtx_do_func(data, &data->mtxstart, store_start_time));
}

int64_t	store_start_time(t_data *data)
{
	data->start = get_msec();
	return (data->start);
}

void	inc_eatcount(t_data *data)
{
	mtx_do_func(data, &data->phi->mtxeatcount, inc_eatcount_func);
}

int64_t	inc_eatcount_func(t_data *data)
{
	data->eatcount++;
	data->phi->enough += data->eatcount == data->phi->eatmax;
	return (0);
}
