#include "philo_bonus.h"

int32_t	philo_init(t_phi **philo)
{
	*philo = malloc(sizeof(t_phi));
	if (!*philo)
		err_exit(*philo, "malloc failed\n");
	**philo = (t_phi){
		.format[0] = YELLOW"%ld %*ld has taken a fork\n"RESET,
		.format[1] = GREEN"%ld %*ld is eating\n"RESET,
		.format[2] = CYAN"%ld %*ld is sleeping\n"RESET,
		.format[3] = "%ld %*ld is thinking\n",
		.format[4] = RED"%ld %*ld died\n"RESET,
		.musteat = -1
	};
	return (0);
}

int32_t	validate_args(int argc, char **argv, t_phi *philo)
{
	if (ft_atol_err(argv[1], &philo->num_of_phi)
		|| ft_atol_err(argv[2], &philo->deadline)
		|| ft_atol_err(argv[3], &philo->eat)
		|| ft_atol_err(argv[4], &philo->sleep)
		|| (argc == 6 && ft_atol_err(argv[5], &philo->musteat))
		|| philo->num_of_phi < 0
		|| philo->num_of_phi > INT_MAX
		|| philo->deadline < 0
		|| philo->eat < 0
		|| philo->sleep < 0
		|| (argc == 6 && philo->musteat < 0))
		err_exit(philo, "invalid argument\n");
	return (0);
}

int	philo_utils_init(t_phi *philo)
{
	ft_sem_init(philo);
	philo->pid = malloc(sizeof(pid_t) * philo->num_of_phi);
	if (!philo->pid)
		err_exit(philo, "malloc failed\n");
	philo->width = count_digits(philo->num_of_phi);
	philo->think_time = (int64_t [2]){0, philo->eat}[philo->num_of_phi % 2];
	return (0);
}
