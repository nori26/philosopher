#include "philo_bonus.h"

void	exit_philo(t_phi *philo)
{
	if (philo)
		free(philo->pid);
	sem_end(philo->forks1, "/forks1");
	sem_end(philo->forks2, "/forks2");
	sem_end(philo->print, "/print");
	sem_end(philo->musteat, "/musteat");
	free(philo);
}

void	err_exit(t_phi *philo, char *message)
{
	exit_philo(philo);
	write(2, message, ft_strlen(message));
	kill(0, SIGINT);
}

size_t	ft_strlen(const char *str)
{
	uint64_t		longvalue;
	uint64_t const	*longptr;
	char const		*char_tmp;

	char_tmp = str;
	while ((uint64_t)char_tmp & 0b111)
		if (!*char_tmp++)
			return (--char_tmp - str);
	longptr = (uint64_t *)char_tmp;
	while (1)
	{
		longvalue = *longptr++;
		if (((longvalue - LSB_MASK) & ~longvalue & MSB_MASK))
		{
			char_tmp = (const char *)(longptr - 1);
			while (*char_tmp)
				char_tmp++;
			return (char_tmp - str);
		}
	}
}
