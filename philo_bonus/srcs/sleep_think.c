/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:01:27 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/09/03 10:56:13 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	sleeping(t_phi *philo)
{
	actions(philo, SLEEP, philo->sleep);
}

void	thinking(t_phi *philo)
{
	actions(philo, THINK, philo->think_time);
}

void	mymsleep(int64_t msec, t_phi *philo)
{
	register int64_t	sleeptime;
	register int64_t	start;

	if (!msec)
		return ;
	start = get_usec();
	sleeptime = msec * 1000;
	while (get_usec() - start < sleeptime - 1000 && continue_simulation(philo))
		usleep(1000);
	sleeptime = start + sleeptime - get_usec();
	if (sleeptime > 0 && sleeptime < 1000)
		usleep(sleeptime);
}
