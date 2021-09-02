/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 23:40:26 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/09/02 23:40:26 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher(void *arg)
{
	delay_if_even(arg);
	forks_init(arg);
	while (continue_simulation(arg))
	{
		get_forks(arg);
		eating(arg);
		release_forks(arg);
		sleeping(arg);
		thinking(arg);
	}
	return (NULL);
}

void	delay_if_even(t_data *data)
{
	if (!(data->num % 2))
		usleep(1000);
}

void	*phisolopher(void *arg)
{
	take_a_fork(arg);
	return (arg);
}
