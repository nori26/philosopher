#include "philo.h"

int64_t	continue_simulation(t_data *data)
{
	return (mtx_do_func(data, &data->phi->output, alive_and_hungry));
}

int64_t	alive_and_hungry(t_data *data)
{
	return (is_alive(data) && is_hungry(data));
}
