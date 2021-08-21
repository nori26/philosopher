#include "philo.h"

void	*start_philo(void *arg)
{
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

int64_t	is_hungry(t_data *data)
{
	return (mtx_do_func(data, &data->mtxeatcount, is_hungry_funcp));
}

int64_t	is_hungry_funcp(t_data *data)
{
	return (data->eatmax == -1 || data->eatcount < data->eatmax);
}
