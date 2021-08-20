#include "philo.h"

int64_t mtx_do_func(void *arg, pthread_mutex_t *lock, int64_t (*func)())
{
	int64_t	ret;

	pthread_mutex_lock(lock);
	ret = func(arg);
	pthread_mutex_unlock(lock);
	return (ret);
}
