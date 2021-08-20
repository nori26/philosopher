#include "philo.h"

void	doctor(t_data *data)
{
	while (1)
	{
		pthread_mutex_lock(&data->mstart);
		if (data->start + data->phi->deadline < get_msec())
		{
			pthread_mutex_lock(&data->mdied);
			data->died = 1;
			pthread_mutex_unlock(&data->mdied);
			break ;
		}
		pthread_mutex_unlock(&data->mstart);
		usleep(1000);
	}
}
