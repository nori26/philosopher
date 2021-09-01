#include "philo_bonus.h"

int	ft_sem_init(t_phi *philo)
{
	unsigned	*value;
	sem_t		**sems;
	char		**name;

	sems = (sem_t *[]){philo->forks1, philo->forks2, philo->outer,
		philo->inner, philo->stop, philo->restart, philo->end_ready};
	name = (char *[]){"/forks1", "/forks2", "/outer", "/inner", "/stop",
		"/restart", "/end_ready"};
	value = (unsigned []){philo->num_of_phi / 2,
		philo->num_of_phi - philo->num_of_phi / 2, 1, 1, 0, 0, 0};
	return (sems_open(sems, name, value));
}

int	sems_open(sem_t **sems, char **name, unsigned *value)
{
	int	i;
	int	j;

	i = 0;
	while (i < 7)
	{
		sems[i] = sem_open(name[i], O_CREAT | O_EXCL, value[i]);
		if (sems[i] == SEM_FAILED)
		{
			j = 0;
			while (j < i)
			{
				sem_end(sems[j], name[j]);
				j++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

void	sem_end(sem_t *sem, char *name)
{
	sem_close(sem);
	sem_unlink(name);
}
