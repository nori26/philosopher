#include "philo_bonus.h"

void	eating(t_phi *philo)
{
	actions(philo, EAT, philo->eat);
	inc_eatcount(philo);
}

int64_t	store_start_time(t_phi *philo)
{
	philo->start = get_msec();
	return (philo->start);
}

void	inc_eatcount(t_phi *philo)
{
	mtx_do_func(philo, &philo->outer, inc_eatcount_func);
}

int64_t	inc_eatcount_func(t_phi *philo)
{
	philo->eatcount++;
	philo->enough += philo->eatcount == philo->eatmax;
	return (0);
}
