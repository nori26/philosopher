/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:01:27 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/09/03 00:01:27 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <stdint.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
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
	sem_t		*forks1;
	sem_t		*forks2;
	sem_t		*outer;
	sem_t		*inner;
	sem_t		*stop;
	sem_t		*restart;
	sem_t		*end_ready;
	sem_t		*died;
	pthread_t	thp;
	pthread_t	thd;
	int64_t		num_of_phi;
	int64_t		deadline;
	int64_t		eat;
	int64_t		sleep;
	int64_t		musteat;
	int64_t		think_time;
	int64_t		end;
	int64_t		num;
	int64_t		now;
	int64_t		start;
	int64_t		eatcount;
	int32_t		width;
	char		*format[5];
}t_phi;
typedef struct s_print
{
	t_phi	*philo;
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

int64_t	continue_simulation(t_phi *philo);
int64_t	continue_inner(t_phi *philo);
int64_t	continue_check(t_phi *philo);
int64_t	over_deadline(t_phi *philo);
int64_t	check_deadline(t_phi *philo);
int64_t	died_notice(t_phi *philo);
void	post_all_endready(t_phi *philo);
void	post_endready(t_phi *philo);
void	*doctor(void *arg);
void	eating(t_phi *philo);
int64_t	store_start_time(t_phi *philo);
void	inc_eatcount(t_phi *philo);
int64_t	inc_eatcount_func(t_phi *philo);
void	err_exit(t_phi *philo, char *message);
void	free_exit(t_phi *philo, int status);
void	end_flag_handler(t_phi *philo);
void	wait_die_or_musteat(t_phi *philo);
void	post_all_flags(t_phi *philo);
void	wait_to_set_all_flags(t_phi *philo);
void	wait_ready_post_inner(t_phi *philo);
void	wait_restart(t_phi *philo);
void	post_stop(t_phi *philo);
int32_t	philo_init(t_phi **philo);
int32_t	validate_args(int argc, char **argv, t_phi *philo);
int		philo_utils_init(t_phi *philo);
void	start_simulation(t_phi *philo);
void	wait_process(t_phi *philo);
void	ft_sem_init(t_phi *philo);
void	sems_open(t_phi *philo, sem_t ***sems, char **name, uint32_t *value);
void	*philosopher(void *arg);
void	*phisolopher(void *arg);
void	philo_manager(t_phi *philo);
void	create_threads(t_phi *philo);
t_func	select_simulation(t_phi *philo);
void	notice_die_or_eat_enough(t_phi *philo);
void	wait_threads(t_phi *philo);
void	actions(t_phi *philo, int action, int64_t sleeptime);
int64_t	print_status(t_print *p);
int64_t	inner_lock(t_print *p);
int64_t	print(t_print *p);
int64_t	timestamp(t_phi *philo, int action);
void	sleeping(t_phi *philo);
void	thinking(t_phi *philo);
void	mymsleep(int64_t msec, t_phi *philo);
void	get_forks(t_phi *philo);
void	release_forks(t_phi *philo);
void	take_a_fork(t_phi *philo);

#endif
