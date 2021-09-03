/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handler_funcp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:01:27 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/09/03 13:11:26 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	wait_ready_post_inner(t_phi *philo)
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
void	post_died(t_phi *philo)
{
	sem_post(philo->died);
}
