#include "philo.h"

void	*start_philo(void *arg)
{
	if (num_of_phi(arg) == 1)
		return (NULL);
	forks_init(arg);
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
