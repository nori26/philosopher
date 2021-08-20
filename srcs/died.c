#include "philo.h"

int32_t	is_dead(t_data *data)
{
	return (mtx_do_func(data, &data->mdied, dead_check));
}

void	i_am_dead(t_data *data)
{
	mtx_do_func(data, &data->mdied, set_deadflag);
}

int	dead_check(t_data *data)
{
	return (data->died + data->phi->end_of_simulation);
}

int	set_deadflag(t_data *data)
{
	data->died = 1;
	data->phi->end_of_simulation = 1;
	return (0);
}
