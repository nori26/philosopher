#include "philo_bonus.h"

void	sleeping(t_phi *philo)
{
	actions(philo, SLEEP, philo->sleep);
}

void	thinking(t_phi *philo)
{
	actions(philo, THINK, philo->think_time);
}
