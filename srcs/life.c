#include "philo.h"

void	actions(t_data *data, int action, int64_t msec)
{
	print_status(data, action);
	mymsleep(msec);
}

void	eating(t_data *data)
{
	actions(data, EAT, data->phi->eat);
}

void	sleeping(t_data *data)
{
	actions(data, SLEEP, data->phi->sleep);
}

void	thinking(t_data *data)
{
	print_status(data, THINK);
}
