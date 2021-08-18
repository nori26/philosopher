#ifndef PHILO_H
# define PHILO_H
# include <stdint.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
typedef struct timeval	t_time;
typedef struct s_list	t_list;
struct		s_list
{
	void	*content;
	t_list	*next;
};
typedef struct	s_phi
{
	int64_t			num_of_phi;
	int64_t			deadline;
	int64_t			eat;
	int64_t			sleep;
	int64_t			times;
	pthread_mutex_t	*forks;
	char			*format[5];
}t_phi;
typedef struct	s_data
{
	t_phi			*phi;
	int64_t			num;
	pthread_t		th;
	int32_t			status[5];
	int32_t			idx[2];
	pthread_mutex_t	*fork1;
	pthread_mutex_t	*fork2;
}t_data;
enum	e_status
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
};

void	exit_philo(t_data *data, t_phi *philo);
int32_t	philo_init(t_phi **philo);
int32_t	validate_args(int argc, char **argv, t_phi *philo);
int		create_threads(t_data **data, t_phi *philo);
void	*start_philo(void *arg);
void	take_forks(t_data *data);
void	fork_init(t_data *data);
int		calc_idx(int64_t n, int64_t max, int offset);
void	get_forks(t_data *data);
void	release_forks(t_data *data);
void	print_status(t_data *data, int idx);
void	format_init(char **format);
int64_t	get_msec();
int		freeturn(void *p, int ret);
int		ft_atol_err(char *s, int64_t *i);

#endif
