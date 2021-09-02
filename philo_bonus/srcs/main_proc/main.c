/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:01:27 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/09/03 00:01:27 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_phi	*philo;

	if ((argc != 5 && argc != 6))
		return (!!write(2, "argument error\n", 15));
	philo_init(&philo);
	validate_args(argc, argv, philo);
	philo_utils_init(philo);
	start_simulation(philo);
	end_flag_handler(philo);
	wait_process(philo);
	free(philo);
}
