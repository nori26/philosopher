/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:01:27 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/09/03 00:01:27 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdint.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include "libph.h"
# define GREEN  "\x1b[32m"
# define RED    "\x1b[31m"
# define YELLOW "\x1b[33m"
# define CYAN   "\x1b[36m"
# define BLUE   "\x1b[34m"
# define RESET  "\x1b[39m"
typedef struct timeval	t_time;
typedef void			*(*t_func)(void *);
typedef struct s_phi
{
	int64_t			num_of_phi;
	int64_t			deadline;
	int64_t			eat;
	int64_t			sleep;
	int64_t			eatmax;
	int64_t			dead;
	int64_t			think_time;
	int64_t			enough;
	pthread_mutex_t	*forks;
	pthread_mutex_t	output;
	int32_t			width;
	char			*format[5];
}t_phi;
typedef struct s_data
{
	t_phi			*phi;
	pthread_t		thd;
	pthread_t		thp;
	int64_t			num;
	int64_t			start;
	int64_t			now;
	int64_t			eatcount;
	pthread_mutex_t	*fork1;
	pthread_mutex_t	*fork2;
}t_data;
typedef struct s_print
{
	t_data	*data;
	int		action;
}t_print;
enum	e_status
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
};

int64_t	continue_simulation(t_data *data);
int64_t	alive_and_hungry(t_data *data);
int64_t	is_hungry(t_data *data);
int64_t	is_alive(t_data *data);
void	*doctor(void *arg);
int64_t	over_deadline(t_data *data);
int64_t	check_deadline(t_data *data);
int64_t	died_notice(t_data *data);
void	eating(t_data *data);
int64_t	store_start_time(t_data *data);
void	inc_eatcount(t_data *data);
int64_t	inc_eatcount_func(t_data *data);
int		create_threads(t_data *data, t_phi *philo);
void	mtx_init_philo(t_phi *philo);
t_func	select_simulation(t_phi *philo);
void	data_init(t_data *data, int64_t idx, t_phi *philo);
int		end_of_simulation(t_data *data, t_phi *philo);
int		wait_threads(t_data *data, t_phi *philo);
void	mtx_destroy(t_phi *philo);
void	exit_philo(t_data *data, t_phi *philo);
int32_t	philo_init(t_phi **philo);
int32_t	validate_args(int argc, char **argv, t_phi *philo);
int		philo_utils_init(t_data **data, t_phi *philo);
void	*philosopher(void *arg);
void	delay_if_even(t_data *data);
void	*phisolopher(void *arg);
void	actions(t_data *data, int action, int64_t sleeptime);
int64_t	print_status(t_print p);
int64_t	print(t_print *p);
int64_t	timestamp(t_data *data, int action);
void	mymsleep(int64_t msec, t_data *data);
void	sleeping(t_data *data);
void	thinking(t_data *data);
void	forks_init(t_data *data);
int		calc_idx(int64_t n, int64_t max, int offset);
void	get_forks(t_data *data);
void	release_forks(t_data *data);
void	take_a_fork(t_data *data);

#endif
