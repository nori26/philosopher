#include "philo_bonus.h"

int	sem_init(sem_t **forks, t_phi *philo)
{
	*forks = sem_open("/philo", O_CREAT | O_EXCL, philo->num_of_phi);
	if (*forks == SEM_FAILED)
	{
		write(2, "semfailed : file exist", 22);
		return (1);
	}
	
	return (0);
}
