#include "philo.h"

void	*philosopher(void *arg)
{
	delay_if_even(arg);
	forks_init(arg);
	while (is_alive(arg) && is_hungry(arg))
	{
		get_forks(arg);
		eating(arg);
		release_forks(arg);
		sleeping(arg);
		thinking(arg);
	}
	return (NULL);
}

void	delay_if_even(t_data *data)
{
	if (!(data->num % 2))
		usleep(1000);
}

void	*nop(void *arg)
{
	return (arg);
}
