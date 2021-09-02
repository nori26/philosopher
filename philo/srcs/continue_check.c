/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   continue_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:01:27 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/09/03 00:01:27 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int64_t	continue_simulation(t_data *data)
{
	return (mtx_do_func(data, &data->phi->output, alive_and_hungry));
}

int64_t	alive_and_hungry(t_data *data)
{
	return (is_alive(data) && is_hungry(data));
}

int64_t	is_hungry(t_data *data)
{
	return (data->phi->eatmax == -1
		|| data->phi->enough != data->phi->num_of_phi);
}

int64_t	is_alive(t_data *data)
{
	return (!data->phi->dead);
}
