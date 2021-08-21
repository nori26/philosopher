#include "philo.h"

int64_t	is_dead(t_data *data)
{
	return (mtx_do_func(&data->died, &data->mtxdied, ret_arg) +
		mtx_do_func(&data->phi->end_of_simulation, &data->phi->eos, ret_arg));
}

int64_t	ret_arg(int32_t *arg)
{
	return (*arg);
}

void	i_have_died(t_data *data)
{
	mtx_do_func(&data->died, &data->mtxdied, set_flag);
	mtx_do_func(&data->phi->end_of_simulation, &data->phi->eos, set_flag);
}

int64_t	set_flag(int32_t *flag)
{
	*flag = 1;
	return (0);
}
