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
	sem_t		*inner;//
	sem_t		*stop;//
	sem_t		*restart;//
	sem_t		*musteat;
	pid_t		*pid;
	pthread_t	thp;
	pthread_t	thd;
	int64_t		num_of_phi;
	int64_t		deadline;
	int64_t		eat;
	int64_t		sleep;
	int64_t		eatmax;
	int64_t		dead;
	int64_t		think_time;
	int64_t		enough;
	int64_t		num;
	int32_t		width;
	int32_t		end;
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
int64_t	alive_and_hungry(t_phi *philo);
int64_t	is_hungry(t_phi *philo);
int64_t	is_alive(t_phi *philo);
void	*doctor(void *arg);
int64_t	over_deadline(t_data *data);
int64_t	check_deadline(t_data *data);
int64_t	died_notice(t_data *data);
void	exit_philo(t_phi *philo);
void	err_exit(t_phi *philo, char *message);
void	free_exit(t_phi *philo, int status);
void	new_process(t_phi *philo);
void	wait_process(t_phi *philo);
void	wait_for_no_option(t_phi *philo);
void	wait_for_must_eat(t_phi *philo);
void	sem_wait_n_times(int64_t n, sem_t *sem);
int		philo_manager(t_phi *philo);
int32_t	philo_init(t_phi **philo);
int32_t	validate_args(int argc, char **argv, t_phi *philo);
int		philo_utils_init(t_phi *philo);
int		ft_sem_init(t_phi *philo);
void	sem_end(sem_t *sem, char *name);
void	*philosopher(void *arg);
void	*phisolopher(void *arg);
void	philo_manager(t_phi *philo);
int		create_threads(t_phi *philo);
t_func	select_simulation(t_phi *philo);
void	notice_die_or_eat_enough(t_phi *philo);
void	wait_threads(t_phi *philo);
void	actions(t_phi *philo, int action, int64_t sleeptime);
int64_t	print_status(t_print p);
int64_t	print(t_print *p);
int64_t	timestamp(t_phi *philo, int action);
void	sleeping(t_phi *data);
void	thinking(t_phi *data);
void	get_forks(t_phi *data);
void	release_forks(t_phi *data);
void	take_a_fork(t_phi *data);

#endif
