#include "philo_bonus.h"

void	new_process(t_phi *philo)
{
	int64_t	i;

	i = 0;
	while (i < philo->num_of_phi)
	{
		philo->num = i + 1;
		philo->pid[i] = fork();
		if (philo->pid[i] == -1)
			err_exit(philo, "fork failed");
		else if (!philo->pid[i])
		{
			philo_manager(philo);
			free_exit(philo, 0);
		}
		i++;
	}
}

void	wait_process(t_phi *philo)
{
	int64_t	i;
	int		status;
	pid_t	pid;

	if (philo->musteat == -1)
		wait_for_no_option(philo);
	else
		wait_for_must_eat(philo);
	pid = wait(&status);
	if (pid == -1)
		err_exit(philo, "wait failed");
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status))
			err_exit(philo, "");
		i = 0;
		while (i < philo->num_of_phi)
		{
			if (philo->pid[i] != pid)
			{
				if (kill(philo->pid[i], SIGINT))
					err_exit(philo, "kill failed");
				if (waitpid(philo->pid[i], NULL, 0) == -1)
					err_exit(philo, "wait failed");
			}
			i++;
		}
	}
	else
		err_exit(philo, "unknown error");
}
void wait_for_no_option(t_phi *philo)
{

}

void wait_for_must_eat(t_phi *philo)
{
	pid_t	pid;
	int		status;

	sem_wait_n_times(philo->num_of_phi, philo->musteat);
	sem_post(philo->stop);
	sem_wait_n_times(philo->num_of_phi, philo->restart);
	sem_post(philo->inner);
	// if (pid)
}

void	sem_wait_n_times(int64_t n, sem_t *sem)
{
	int64_t	i;

	i = 0;
	while (i < n)
	{
		sem_wait(sem);
		i++;
	}
}
