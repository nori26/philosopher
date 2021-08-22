#include "philo.h"

void	*start_philo(void *arg)
{
	t_thinkfunc	thinking;

	if (((t_data *)arg)->phi->num_of_phi == 1)
		return (NULL);
	forks_init(arg);
	thinking = select_thinking(arg);
	while (is_living(arg) && is_hungry(arg))
	{
		get_forks(arg);
		eating(arg);
		release_forks(arg);
		sleeping(arg);
		thinking(arg);
	}
	return (NULL);
}

int64_t	num_of_phi(t_data *data)
{
	return (mtx_do_func(&data->phi->num_of_phi, &data->mtxnum, ret_arg));
}

t_thinkfunc	select_thinking(t_data *data)
{
	return ((t_thinkfunc[2]){think, think_odd}[data->phi->num_of_phi % 2]);
}
