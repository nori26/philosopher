#include "philo.h"

int	main(int argc, char **argv)
{
	t_phi	philo;

	if (argc != 5 && argc != 6)
		return (1);
	philo = (t_phi){};
	if (validate_args(argc, argv, &philo))
		return (1);
}

int32_t	validate_args(int argc, char **argv, t_phi *p)
{
	if (ft_atoi_err(argv[1], &p->num_of_phi)
		|| ft_atoi_err(argv[2], &p->deadline)
		|| ft_atoi_err(argv[3], &p->eat)
		|| ft_atoi_err(argv[4], &p->sleep)
		|| (argc == 6 && ft_atoi_err(argv[5], &p->times))
		|| p->num_of_phi < 0
		|| p->deadline < 0
		|| p->eat < 0
		|| p->sleep < 0 
		|| p->times < 0)
		return (1);
	printf("%d %d %d %d %d\n", philo.num_of_phi, philo.deadline, philo.eat, philo.sleep, philo.times);
	return (0);
}
