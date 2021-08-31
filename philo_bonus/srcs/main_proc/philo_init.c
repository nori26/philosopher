#include "philo_bonus.h"

int32_t	philo_init(t_phi **philo)
{
	*philo = malloc(sizeof(t_phi));
	if (!*philo)
		err_exit(philo, "malloc failed");
	**philo = (t_phi){
		.format[0] = YELLOW"%ld %*ld has taken a fork\n"RESET,
		.format[1] = GREEN"%ld %*ld is eating\n"RESET,
		.format[2] = CYAN"%ld %*ld is sleeping\n"RESET,
		.format[3] = "%ld %*ld is thinking\n",
		.format[4] = RED"%ld %*ld died\n"RESET,
		.eatmax = -1
	};
	return (0);
}

int32_t	validate_args(int argc, char **argv, t_phi *philo)
{
	if (ft_atol_err(argv[1], &philo->num_of_phi)
		|| ft_atol_err(argv[2], &philo->deadline)
		|| ft_atol_err(argv[3], &philo->eat)
		|| ft_atol_err(argv[4], &philo->sleep)
		|| (argc == 6 && ft_atol_err(argv[5], &philo->musteat))
		|| philo->num_of_phi <= 0
		|| philo->deadline < 0
		|| philo->eat < 0
		|| philo->sleep < 0
		|| (argc == 6 && philo->musteat < 0))
		err_exit(1, "invalid argument");
	return (0);
}

int	philo_utils_init(t_phi *philo)
{
	if (ft_sem_init(philo))
	{
		write(2, "semfailed", 9);
		free(philo);
		exit(1);
	}
	philo->pid = malloc(sizeof(pid_t) * philo->num_of_phi);
	if (!philo->pid)
		err_exit(philo, "malloc failed");
	philo->width = count_digits(philo->num_of_phi);
	philo->think_time = (int64_t [2]){0, philo->eat}[philo->num_of_phi % 2];
	return (0);
}

int	ft_sem_init(t_phi *philo)
{
	philo->forks1 = sem_open("/fork1", O_CREAT | O_EXCL, philo->num_of_phi / 2);
	if (philo->forks2 == SEM_FAILED)
		return (1);
	philo->forks2 = sem_open("/forks2", O_CREAT | O_EXCL, philo->num_of_phi - (philo->num_of_phi / 2));
	if (philo->forks2 == SEM_FAILED)
	{
		sem_end(philo->forks1, "/forks1");
		return (1);
	}
	philo->print = sem_open("/print", O_CREAT | O_EXCL, 1);
	if (philo->forks2 == SEM_FAILED)
	{
		sem_end(philo->forks1, "/forks1");
		sem_end(philo->forks2, "/forks2");
		return (1);
	}
	philo->print = sem_open("/musteat", O_CREAT | O_EXCL, 0);
	if (philo->forks2 == SEM_FAILED)
	{
		sem_end(philo->forks1, "/forks1");
		sem_end(philo->forks2, "/forks2");
		sem_end(philo->print, "/print");
		return (1);
	}
	return (0);
}

void	sem_end(sem_t *sem, char *name)
{
	sem_close(sem);
	sem_unlink(name);
}