#include "philo.h"

void	*start_philo(void *arg)
{
	fork_init(arg);
	take_fork(arg);
	return (NULL);
}

void	take_fork(t_data *data)
{
	get_fork(data);
	release_fork(data);
}

void	fork_init(t_data *data)
{
	int	idx1;
	int	idx2;

	idx1 = calc_idx(data->num, data->phi->num_of_phi, !(data->num % 2));
	idx2 = calc_idx(data->num, data->phi->num_of_phi, (data->num % 2));
	data->fork1 = &data->phi->fork[idx1];
	data->fork2 = &data->phi->fork[idx2];
}

int	calc_idx(int64_t n, int64_t max, int offset)
{
	return (((n - offset) % max));
}

void	get_fork(t_data *data)
{
	pthread_mutex_lock(data->fork1);
	print_status(data, FORK);
	pthread_mutex_lock(data->fork2);
	print_status(data, FORK);
}

void	release_fork(t_data *data)
{
	pthread_mutex_unlock(data->fork1);
	pthread_mutex_unlock(data->fork2);
}

void	print_status(t_data *data, int idx)
{
	printf(data->phi->format[idx], get_msec(), data->num);
}

int64_t	get_msec()
{
	t_time	tv;

	gettimeofday(&tv, NULL);
	return ((int64_t)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
