#include "philo.h"

int	create_threads(t_data *data, t_phi *philo)
{
	int64_t		i;

	i = 0;
	while (i < philo->num_of_phi)
	{
		data_init(&data[i], i, philo);
		if (pthread_create(&data[i].th, NULL, doctor, &data[i])
			|| pthread_create(&data[i].th2, NULL, start_philo, &data[i]))
			return (1);
		i++;
	}
	return (0);
}

void	data_init(t_data *data, int64_t idx, t_phi *philo)
{
	*data = (t_data){
		.phi = philo,
		.num = idx + 1,
		.start = get_msec(),
		.eatmax = philo->times
	};
	mtx_init_data(data);
}

void	mtx_init_data(t_data *data)
{
	pthread_mutex_init(&data->mtxstart, NULL);
	pthread_mutex_init(&data->mtxdied, NULL);
	pthread_mutex_init(&data->mtxeatcount, NULL);
}
