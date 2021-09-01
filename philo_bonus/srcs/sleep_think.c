#include "philo_bonus.h"

void	sleeping(t_phi *data)
{
	actions(data, SLEEP, data->phi->sleep);
}

void	thinking(t_phi *data)
{
	actions(data, THINK, data->phi->think_time);
}
