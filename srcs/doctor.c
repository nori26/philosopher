#include "philo.h"

void	doctor(t_data *data)
{
	while (!is_dead(data))
	{
		data->now = get_msec();
		if (within_deadline(data))
		{
			i_have_died(data);
			print_status(data, DIE, data->now);
			return ;
		}
		usleep(1000);
	}
}

int64_t	within_deadline(t_data *data)
{
	return (mtx_do_func(data, &data->mstart, check_deadline));
}

int64_t	check_deadline(t_data *data)
{
	return (data->start + data->phi->deadline < data->now);
}
