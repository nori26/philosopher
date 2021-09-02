#include "philo_bonus.h"

void	start_simulation(t_phi *philo)
{
	// pid_t	pid;
	int64_t	i;

	i = 0;
	while (i < philo->num_of_phi)
	{
		philo->num = i + 1;
		philo->start = get_msec();
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

	i = 0;
	while (i < philo->num_of_phi)
	{
		pid = wait(&status);
		if (pid == -1)
			err_exit(philo, "wait failed");
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status))
				err_exit(philo, "child error");
		}
		else
			err_exit(philo, "unknown error");
		i++;
	}
}

void end_flag_handler(t_phi *philo)
{
	if (philo->num_of_phi <= 0)
		return ;
	wait_die_or_musteat(philo);
	post_all_flags(philo);
	wait_to_set_all_flags(philo);
	sem_post(philo->inner);
	sem_post(philo->died);
}

void	wait_die_or_musteat(t_phi *philo)
{
	philo_iterator(philo, philo->num_of_phi - 1, wait_and_post);
	sem_wait(philo->end_ready);
}

void	wait_to_set_all_flags(t_phi *philo)
{
	philo_iterator(philo, philo->num_of_phi, wait_restart);
}

void	post_all_flags(t_phi *philo)
{
	philo_iterator(philo, philo->num_of_phi, post_stop);
}

void	philo_iterator(t_phi *philo, int64_t n, void (*func)())
{
	int64_t	i;

	i = 0;
	while (i < n)
	{
		func(philo);
		i++;
	}
}

void	wait_and_post(t_phi *philo)
{
	sem_wait(philo->end_ready);
	sem_post(philo->inner);
}

void	wait_restart(t_phi *philo)
{
	sem_wait(philo->restart);
}

void	post_stop(t_phi *philo)
{
	sem_post(philo->stop);
}
