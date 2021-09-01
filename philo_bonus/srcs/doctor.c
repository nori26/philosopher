#include "philo.h"

void	*doctor(void *arg)
{
	t_data	*data;

	data = arg;
	while (continue_simulation(data))
	{
		data->now = get_msec();
		if (over_deadline(data))
			break ;
		usleep(1000);
	}
	return (NULL);
}

int64_t	over_deadline(t_data *data)
{
	return (mtx_do_func(data, &data->phi->output, check_deadline));
}

int64_t	check_deadline(t_data *data)
{
	if (data->start + data->phi->deadline < data->now)
	{
		died_notice(data);
		return (1);
	}
	return (0);
}

int64_t	died_notice(t_data *data)
{
	print(&(t_print){data, DIE});
	data->phi->dead = 1;
	return (0);
}
