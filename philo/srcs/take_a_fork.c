/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_a_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:01:27 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/09/03 00:01:27 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forks_init(t_data *data)
{
	int	idx1;
	int	idx2;

	idx1 = calc_idx(data->num, data->phi->num_of_phi, !(data->num % 2));
	idx2 = calc_idx(data->num, data->phi->num_of_phi, (data->num % 2));
	data->fork1 = &data->phi->forks[idx1];
	data->fork2 = &data->phi->forks[idx2];
}

int	calc_idx(int64_t n, int64_t max, int offset)
{
	return ((n - offset) % max);
}

void	get_forks(t_data *data)
{
	pthread_mutex_lock(data->fork1);
	take_a_fork(data);
	pthread_mutex_lock(data->fork2);
	take_a_fork(data);
}

void	release_forks(t_data *data)
{
	pthread_mutex_unlock(data->fork1);
	pthread_mutex_unlock(data->fork2);
}

void	take_a_fork(t_data *data)
{
	actions(data, FORK, 0);
}
