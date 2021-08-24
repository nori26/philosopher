#include "philo.h"

int64_t	is_alive(t_data *data)
{
	return (!is_dead(data));
}

int64_t	is_dead(t_data *data)
{
	return (mtx_do_func(data, &data->phi->eos, dead_func));
}

int64_t	dead_func(t_data *data)
{
	return (data->phi->end_of_simulation + data->died);
}

void	died_notice(t_data *data)
{
	mtx_do_func(data, &data->phi->eos, notice_func);
}

int64_t	notice_func(t_data *data)
{
	if (data->phi->end_of_simulation)
		return (0);
	data->phi->end_of_simulation = 1;
	data->died = 1;
	usleep(1000);
	print_status(data, DIE, wrap_printf);
	return (0);
}
