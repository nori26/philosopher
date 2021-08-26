#include "philo.h"

int64_t	is_hungry(t_data *data)
{
	return (mtx_do_func(data, &data->phi->mtxeatcount, is_hungry_funcp));
}

int64_t	is_hungry_funcp(t_data *data)
{
	return (data->phi->eatmax == -1
		|| data->phi->enough != data->phi->num_of_phi);
}
