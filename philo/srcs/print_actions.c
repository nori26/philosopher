#include "philo.h"

void	actions(t_data *data, int action, int64_t sleeptime)
{
	if (print_status(data, action))
		return ;
	mymsleep(sleeptime);
}

int	print_status(t_data *data, int action)
{
	int	ret;

	pthread_mutex_lock(&data->phi->output);
	ret = print(data, action);
	pthread_mutex_unlock(&data->phi->output);
	return (ret);
}

int	print(t_data *data, int idx)
{
	if (data->phi->dead || !is_hungry(data))
		return (1);
	printf(data->phi->format[idx],
		timestamp(data, idx), data->phi->width, data->num);
	return (0);
}

int64_t	timestamp(t_data *data, int idx)
{
	if (idx == EAT)
		return (start_time_init(data));
	else
		return (get_msec());
}
