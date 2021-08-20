#include "philo.h"

int64_t	is_dead(t_data *data)
{
	return (mtx_do_func(data, &data->mdied, dead_check));
}

int64_t	dead_check(t_data *data)
{
	return (data->died + data->phi->end_of_simulation);
}

void	i_have_died(t_data *data)
{
	mtx_do_func(data, &data->mdied, set_deadflag);
}

int64_t	set_deadflag(t_data *data)
{
	data->died = 1;
	data->phi->end_of_simulation = 1;
	return (0);
}
