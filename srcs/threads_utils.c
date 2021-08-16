#include "philo.h"

void	*start_philo(void *arg)
{
	t_data	*data;

	data = arg;
	print_status(data);
	return (NULL);
	(void)data;
}

void	print_status(t_data *data)
{
	int64_t	timestamp;

	timestamp = get_msec();
	while (get_msec() - timestamp < 10000)
	{
		printf("%ld %ld eating\n", data->num, timestamp);
		sleep(1);
	}
}

int64_t	get_msec()
{
	t_time	tv;

	gettimeofday(&tv, NULL);
	return ((int64_t)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
