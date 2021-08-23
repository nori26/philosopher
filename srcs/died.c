#include "philo.h"

int64_t	is_living(t_data *data)
{
	return (!is_dead(data));
}

int64_t	is_dead(t_data *data)
{
	return (mtx_do_func(&data->died, &data->mtxdied, ret_arg)
		+ mtx_do_func(&data->phi->end_of_simulation, &data->phi->eos, ret_arg));
}

int64_t	ret_arg(int64_t *arg)
{
	return (*arg);
}

void	died_notice(t_data *data)
{
	mtx_do_func(data, &data->phi->eos, notice_func);
	mtx_do_func(&data->died, &data->mtxdied, set_flag);
}

int64_t	notice_func(t_data *data)
{
	print_status(data, DIE, wrap_printf);
	set_flag(&data->phi->end_of_simulation);
	return (0);
}

int64_t	set_flag(int64_t *flag)
{
	*flag = 1;
	return (0);
}
