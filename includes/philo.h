/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 06:45:34 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/08/16 10:07:29 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdint.h>
# include <limits.h>
# include <stdio.h>
# include <pthread.h>
typedef struct s_phi
{
	int64_t		num_of_phi;
	int64_t		deadline;
	int64_t		eat;
	int64_t		sleep;
	int64_t		times;
}t_phi;

int32_t	philo_init(t_phi **philo);
int32_t	validate_args(int argc, char **argv, t_phi *philo);
int		create_threads(t_phi *philo);
void	*start_philo(void *arg);
int		freeturn(char **p, int ret);
int		ft_atol_err(char *s, int64_t *i);

#endif
