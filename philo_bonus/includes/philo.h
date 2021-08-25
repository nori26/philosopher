#ifndef PHILO_H
# define PHILO_H
# include <stdint.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include "libph.h"
# define GREEN  "\x1b[32m"
# define RED    "\x1b[31m"
# define YELLOW "\x1b[33m"
# define CYAN   "\x1b[36m"
# define BLUE   "\x1b[34m"
# define RESET  "\x1b[39m"
typedef struct timeval	t_time;
typedef struct s_list	t_list;
typedef void			*(*t_func)(void *);
struct		s_list
{
	void	*content;
	t_list	*next;
};
typedef struct s_phi
{
	int64_t			num_of_phi;
	int64_t			deadline;
	int64_t			eat;
	int64_t			sleep;
	int64_t			times;
	int64_t			dead;
	int64_t			think_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mtxdead;
	pthread_mutex_t	output;
	int32_t			width;
	char			*format[5];
}t_phi;
typedef struct s_data
{
	t_phi			*phi;
	pthread_t		thd;
	pthread_t		thp;
	int32_t			status[5];
	int32_t			idx[2];
	int64_t			num;
	int64_t			start;
	int64_t			died;
	int64_t			now;
	int64_t			eatmax;
	int64_t			eatcount;
	pthread_mutex_t	*fork1;
	pthread_mutex_t	*fork2;
	pthread_mutex_t	mtxstart;
	pthread_mutex_t	mtxdied;
	pthread_mutex_t	mtxnum;
	pthread_mutex_t	mtxeatcount;
}t_data;
enum	e_status
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
};



#endif
