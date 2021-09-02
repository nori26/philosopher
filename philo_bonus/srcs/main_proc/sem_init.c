/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:01:27 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/09/03 00:01:27 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_sem_init(t_phi *philo)
{
	sem_t			***sems;
	char			**name;
	unsigned int	*value;

	sems = (sem_t **[]){&philo->forks1, &philo->forks2, &philo->outer,
		&philo->inner, &philo->stop, &philo->restart,
		&philo->end_ready, &philo->died};
	name = (char *[]){"/forks1", "/forks2", "/outer", "/inner", "/stop",
		"/restart", "/end_ready", "/died"};
	value = (unsigned []){philo->num_of_phi - philo->num_of_phi / 2,
		philo->num_of_phi / 2, 1, 1, 0, 0, 0, 0};
	sems_open(philo, sems, name, value);
}

void	sems_open(t_phi *philo, sem_t ***sems, char **name, uint32_t *value)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		*(sems[i]) = sem_open(name[i], O_CREAT | O_EXCL, 0700, value[i]);
		sem_unlink(name[i]);
		if (*(sems[i]) == SEM_FAILED)
			err_exit(philo, "semfailed\n");
		i++;
	}
}
