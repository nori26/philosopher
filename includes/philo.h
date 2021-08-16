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
typedef struct s_phi
{
	int64_t		num_of_phi;
	int64_t		deadline;
	int64_t		eat;
	int64_t		sleep;
	int64_t		times;
	pthread_t	*th;
}t_phi;

int32_t	philo_init(t_phi **philo);
int32_t	validate_args(int argc, char **argv, t_phi *philo);
int		create_threads(t_phi *philo);
void	*start_philo(void *arg);
void	print_status(t_phi *philo);
int64_t	get_msec();
int		freeturn(void *p, int ret);
int		ft_atol_err(char *s, int64_t *i);
t_list	*del_set(t_list *lst, t_list *next, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
t_list	*ft_lstnew(void *content);

#endif
