/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:01:27 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/09/03 00:01:27 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	end_flag_handler(t_phi *philo)
{
	wait_die_or_musteat(philo);
	post_all_flags(philo);
	wait_to_set_all_flags(philo);
	sem_post(philo->inner);
	sem_post(philo->died);
}

void	wait_die_or_musteat(t_phi *philo)
{
	philo_iterator(philo, philo->num_of_phi - 1, wait_ready_post_inner);
	sem_wait(philo->end_ready);
}

void	post_all_flags(t_phi *philo)
{
	philo_iterator(philo, philo->num_of_phi, post_stop);
}

void	wait_to_set_all_flags(t_phi *philo)
{
	philo_iterator(philo, philo->num_of_phi, wait_restart);
}
