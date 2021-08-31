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
	sem_t	*forks1;
	sem_t	*forks2;
	sem_t	*print;
	sem_t	*musteat;
	pid_t	*pid;
	int64_t	num_of_phi;
	int64_t	deadline;
	int64_t	eat;
	int64_t	sleep;
	int64_t	eatmax;
	int64_t	dead;
	int64_t	think_time;
	int64_t	enough;
	int32_t	width;
	char	*format[5];
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

void	exit_philo(t_phi *philo);
void	err_exit(t_phi *philo, char *message);
size_t	ft_fastrlen(const char *str);
void	new_process(t_phi *philo);
void	wait_process(t_phi *philo);
void	sem_wait_for_end(t_phi *philo);
int		philosopher(t_phi *philo);
int32_t	philo_init(t_phi **philo);
int32_t	validate_args(int argc, char **argv, t_phi *philo);
int		philo_utils_init(t_phi *philo);
int		ft_sem_init(t_phi *philo);
void	sem_end(sem_t *sem, char *name);

#endif
