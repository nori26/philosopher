/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_a_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:34:44 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/09/03 13:18:25 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	get_forks(t_phi *philo)
{
	sem_wait(philo->forks1);
	take_a_fork(philo);
	sem_wait(philo->forks2);
	take_a_fork(philo);
}

void	release_forks(t_phi *philo)
{
	sem_post(philo->forks1);
	sem_post(philo->forks2);
}

void	take_a_fork(t_phi *philo)
{
	actions(philo, FORK, 0);
}
