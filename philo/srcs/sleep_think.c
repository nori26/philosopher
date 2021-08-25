#include "philo.h"

void	sleeping(t_data *data)
{
	actions(data, SLEEP, data->phi->sleep);
}

void	thinking(t_data *data)
{
	actions(data, THINK, data->phi->think_time);
}
