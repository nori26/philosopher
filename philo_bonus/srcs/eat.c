/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:01:27 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/09/03 12:01:58 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eating(t_phi *philo)
{
	actions(philo, EAT, philo->eat);
	inc_eatcount(philo);
}

int64_t	store_start_time(t_phi *philo)
{
	philo->start = get_msec();
	return (philo->start);
}

void	inc_eatcount(t_phi *philo)
{
	sem_do_func(philo, philo->outer, inc_eatcount_func);
}

int64_t	inc_eatcount_func(t_phi *philo)
{
	if (philo->musteat != -1)
		philo->eatcount++;
	if (philo->eatcount == philo->musteat)
	{
		sem_wait(philo->inner);
		sem_post(philo->end_ready);
	}
	return (0);
}
