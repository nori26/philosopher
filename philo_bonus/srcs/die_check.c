/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:01:27 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/09/03 11:52:38 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int64_t	over_deadline(t_phi *philo)
{
	return (sem_do_func(philo, philo->outer, check_deadline));
}

int64_t	check_deadline(t_phi *philo)
{
	if (philo->deadline < philo->now - philo->start)
	{
		died_notice(philo);
		return (1);
	}
	return (0);
}

int64_t	died_notice(t_phi *philo)
{
	inner_lock(&(t_print){philo, DIE});
	post_all_endready(philo);
	sem_wait(philo->died);
	return (0);
}

void	post_all_endready(t_phi *philo)
{
	philo_iterator(philo, philo->num_of_phi, post_endready);
}

void	post_endready(t_phi *philo)
{
	sem_post(philo->end_ready);
}
