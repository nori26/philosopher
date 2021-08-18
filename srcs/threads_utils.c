#include "philo.h"

void	*start_philo(void *arg)
{
	forks_init(arg);
	for (int i = 0; i < 10; i++)
	{
		// printf("aiueo\n");
		take_forks(arg);
		sleep(1);
	}
	return (NULL);
}

void	take_forks(t_data *data)
{
	get_forks(data);
	release_forks(data);
}

void	forks_init(t_data *data)
{
	int	idx1;
	int	idx2;

	idx1 = calc_idx(data->num, data->phi->num_of_phi, !(data->num % 2));
	idx2 = calc_idx(data->num, data->phi->num_of_phi, (data->num % 2));
	data->fork1 = &data->phi->forks[idx1];
	data->fork2 = &data->phi->forks[idx2];
}

int	calc_idx(int64_t n, int64_t max, int offset)
{
	return (((n - offset) % max));
}

void	get_forks(t_data *data)
{
	pthread_mutex_lock(data->fork1);
	print_status(data, FORK);
	pthread_mutex_lock(data->fork2);
	print_status(data, FORK);
}

void	release_forks(t_data *data)
{
	pthread_mutex_unlock(data->fork1);
	pthread_mutex_unlock(data->fork2);
}

void	print_status(t_data *data, int idx)
{
	printf(data->phi->format[idx], get_msec(), data->phi->width, data->num);
}

int64_t	get_msec()
{
	t_time	tv;

	gettimeofday(&tv, NULL);
	return ((int64_t)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
