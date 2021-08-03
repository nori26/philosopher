/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 06:45:34 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/08/03 06:45:36 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdint.h>
# include <limits.h>
# include <stdio.h>
typedef struct s_phi
{
	int	num_of_phi;
	int	deadline;
	int	eat;
	int	sleep;
	int	times;
}t_phi;

int	validate_args(int argc, char **argv, t_phi *philo);
int	ft_atoi_err(char *s, int *i);

#endif
