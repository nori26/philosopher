#include "philo.h"

void	*doctor(void *arg)
{
	t_data	*data;

	data = arg;
	while (is_alive(data) && is_hungry(data))
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
	//mtxprint
	return (mtx_do_func(data, &data->phi->output, check_deadline));
}

int64_t	check_deadline(t_data *data)
{
	if (data->start + data->phi->deadline < data->now)
	{
		notice_func(data);
		return (1);
	}
	return (0);
}
