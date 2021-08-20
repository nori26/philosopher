#include "philo.h"

int	mtx_do_func(void *arg, pthread_mutex_t *lock, int (*func)())
{
	int32_t	ret;

	pthread_mutex_lock(lock);
	ret = func(arg);
	pthread_mutex_unlock(lock);
	return (ret);
}
