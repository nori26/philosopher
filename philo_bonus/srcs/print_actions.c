#include "philo_bonus.h"

void	actions(t_phi *philo, int action, int64_t sleeptime)
{
	if (print_status((t_print){philo, action}))
		return ;
	mymsleep(sleeptime);
}

int64_t	print_status(t_print p)
{
	return (sem_do_func(&p, &p.philo->outer, inner_lock));
}

int64_t	inner_lock(t_print p)
{
	return (sem_do_func(&p, &p.philo->inner, print));
}

int64_t	print(t_print *p)
{
	if (!is_alive(p->philo) || !is_hungry(p->philo))
		return (1);
	printf(p->philo->format[p->action],
		timestamp(p->philo, p->action), p->philo->width, p->philo->num);
	return (0);
}

int64_t	timestamp(t_phi *philo, int action)
{
	if (action == EAT)
		return (store_start_time(philo));
	else
		return (get_msec());
}
