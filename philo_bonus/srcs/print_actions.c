/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:01:27 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/09/03 10:42:43 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	actions(t_phi *philo, int action, int64_t sleeptime)
{
	// if (print_status(&(t_print){philo, action}))
	if (print_status(&(t_print){philo, action}) | (action == EAT ? !printf("%lld back outer\n", philo->num) : 0))
		return ;
	mymsleep(sleeptime, philo);
	printf("%lld is eated\n", philo->num);
}

int64_t	print_status(t_print *p)
{
	// return (sem_do_func(p, p->philo->outer, inner_lock));
	return (sem_do_func(p, p->philo->outer, inner_lock)  | (p->action == EAT ? !printf("%lld back inner\n", p->philo->num) : 0));
}

int64_t	inner_lock(t_print *p)
{
	// return (sem_do_func(p, p->philo->inner, print));
	return (sem_do_func(p, p->philo->inner, print) | (p->action == EAT ? !printf("%lld back print\n", p->philo->num) : 0));
}

int64_t	print(t_print *p)
{
	if (!continue_check(p->philo))
		return (1);
	printf(p->philo->format[p->action],
		timestamp(p->philo, p->action), p->philo->width, p->philo->num);
	return (0);
}

int64_t	timestamp(t_phi *philo, int action)
{
	if (action == EAT)
		return (store_start_time(philo));
	else
		return (get_msec());
}
