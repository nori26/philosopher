#include "philo.h"

void	doctor(t_data *data)
{
	while (!is_dead(data))
	{
		data->now = get_msec();
		if (within_deadline(data))
		{
			i_am_dead(data);
			print_status(data, DIE, data->now);
			return ;
		}
		usleep(1000);
	}
}

int	within_deadline(t_data *data)
{
	return (mtx_do_func(data, &data->mstart, check_deadline));
}

int	check_deadline(t_data *data)
{
	return (data->start + data->phi->deadline < data->now);
}
