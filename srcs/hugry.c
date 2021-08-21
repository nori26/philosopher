#include "philo.h"

int64_t	is_hungry(t_data *data)
{
	return (mtx_do_func(data, &data->mtxeatcount, is_hungry_funcp));
}

int64_t	is_hungry_funcp(t_data *data)
{
	return (data->eatmax == -1 || data->eatcount < data->eatmax);
}
