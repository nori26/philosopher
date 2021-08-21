#include "philo.h"

void	actions(t_data *data, int action, int64_t sleeptime, int64_t now)
{
	if (is_dead(data))
		return ;
	print_status(data, action, now);
	// printf("%ld\n", sleeptime);
	mymsleep(sleeptime);
	// usleep(sleeptime * 1000);
}

void	sleeping(t_data *data)
{
	actions(data, SLEEP, data->phi->sleep, get_msec());
}

void	thinking(t_data *data)
{
	actions(data, THINK, 0, get_msec());
}
