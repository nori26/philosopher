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
	char	*format[5];
	int64_t	timestamp;

	timestamp = get_msec();
	format_init(format);
	while (get_msec() - timestamp < 10000)
	{
		printf("%ld %ld is eating\n", timestamp, data->num);
		sleep(1);
	}
}

void	format_init(char **format)
{
	format[0] = "%ld %ld has taken a fork";
	format[1] = "%ld %ld is eating";
	format[2] = "%ld %ld is sleeping";
	format[3] = "%ld %ld is thinking";
	format[4] = "%ld %ld died";
}

int64_t	get_msec()
{
	t_time	tv;

	gettimeofday(&tv, NULL);
	return ((int64_t)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
