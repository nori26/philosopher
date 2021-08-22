#include "philo.h"

void	sleeping(t_data *data)
{
	actions(data, SLEEP, data->phi->sleep, wrap_printf);
}

void	thinking(t_data *data)
{
	actions(data, THINK, data->phi->think_time, wrap_printf);
}
