/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:46:49 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/09/02 21:46:53 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	err_exit(t_phi *philo, char *message)
{
	free(philo);
	write(2, message, ft_strlen(message));
	kill(0, SIGINT);
}

void	free_exit(t_phi *philo, int status)
{
	free(philo);
	exit(status);
}
