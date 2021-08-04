/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 06:45:34 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/08/03 21:49:55 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H
# include <stdint.h>
# include <limits.h>
# include <stdio.h>
typedef struct s_phi
{
	int32_t	num_of_phi;
	int32_t	deadline;
	int32_t	eat;
	int32_t	sleep;
	int32_t	times;
}t_phi;

int32_t	validate_args(int argc, char **argv, t_phi *phi);
int		ft_atoi_err(char *s, int *i);

#endif
