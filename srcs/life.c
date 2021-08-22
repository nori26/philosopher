#include "philo.h"

void	sleeping(t_data *data)
{
	actions(data, SLEEP, data->phi->sleep, wrap_printf);
}

void	thinking(t_data *data)
{
	actions(data, THINK, data->phi->think_time, wrap_printf);
}

// void	think_odd(t_data *data)
// {
// 	think(data);
// 	mymsleep(data->phi->eat);
// }

void	actions(t_data *data, int action, int64_t sleeptime, void (*printer)())
{
	if (is_dead(data) || !is_hungry(data))
		return ;
	print_status(data, action, printer);
	mymsleep(sleeptime);
}

void	print_status(t_data *data, int action, void (*printer)())
{
	pthread_mutex_lock(&data->phi->output);
	printer(data, action);
	pthread_mutex_unlock(&data->phi->output);
}

void	eat_print(t_data *data, int idx)
{
	int64_t	msec;

	msec = start_time_init(data);
	printf(data->phi->format[idx], msec, data->phi->width, data->num);
}

void	wrap_printf(t_data *data, int idx)
{
	printf(data->phi->format[idx], get_msec(), data->phi->width, data->num);
}
