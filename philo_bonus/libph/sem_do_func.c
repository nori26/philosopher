#include "philo_bonus.h"

int64_t	sem_do_func(void *arg, sem_t *sem, int64_t (*func)())
{
	int64_t	ret;

	sem_wait(sem);
	ret = func(arg);
	sem_post(sem);
	return (ret);
}
