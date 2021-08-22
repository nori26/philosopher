#include "philo.h"

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

void	wrap_printf(t_data *data, int idx)
{
	printf(data->phi->format[idx], get_msec(), data->phi->width, data->num);
}

void	eat_print(t_data *d, int idx)
{
	printf(d->phi->format[idx], start_time_init(d), d->phi->width, d->num);
}
