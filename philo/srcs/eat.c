/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:01:27 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/09/03 12:02:51 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_data *data)
{
	actions(data, EAT, data->phi->eat);
	inc_eatcount(data);
}

int64_t	store_start_time(t_data *data)
{
	data->start = get_msec();
	return (data->start);
}

void	inc_eatcount(t_data *data)
{
	mtx_do_func(data, &data->phi->output, inc_eatcount_func);
}

int64_t	inc_eatcount_func(t_data *data)
{
	if (data->phi->eatmax != -1)
		data->eatcount++;
	data->phi->enough += data->eatcount == data->phi->eatmax;
	return (0);
}
