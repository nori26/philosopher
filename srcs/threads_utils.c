#include "philo.h"

void	*start_philo(void *arg)
{
	forks_init(arg);
	for (;;)
	{
		// printf("aiueo\n");
		take_forks(arg);
		sleep(1);
	}
	return (NULL);
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
