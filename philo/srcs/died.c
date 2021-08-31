#include "philo.h"

int64_t	is_alive(t_data *data)
{
	return (!mtx_do_func(&data->phi->dead, &data->phi->output, ret_arg));
}

int64_t	ret_arg(int64_t	*arg)
{
	return (*arg);
}

int64_t	died_notice(t_data *data)
{
	print(&(t_print){data, DIE});
	data->phi->dead = 1;
	return (0);
}
