/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procces.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 23:40:26 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/09/02 23:40:26 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	start_simulation(t_phi *philo)
{
	pid_t	pid;
	int64_t	i;

	i = 0;
	while (i < philo->num_of_phi)
	{
		philo->num = i + 1;
		philo->start = get_msec();
		pid = fork();
		if (pid == -1)
			err_exit(philo, "fork failed");
		else if (!pid)
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
