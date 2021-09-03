/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   continue_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:01:27 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/09/03 10:57:29 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int64_t	continue_simulation(t_phi *philo)
{
	return (sem_do_func(philo, philo->outer, continue_inner));
}

int64_t	continue_inner(t_phi *philo)
{
	printf("%lld in out lock\n", philo->num);
	return (sem_do_func(philo, philo->inner, continue_check));
}

int64_t	continue_check(t_phi *philo)
{
	printf("%lld in out lock\n", philo->num);
	return (!philo->end);
}
