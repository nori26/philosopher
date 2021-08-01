#include "../philo.h"

int	main(int argc, char **argv)
{
	t_phi	philo;

	if (argc != 5 && argc != 6)
		return (1);
	philo = (t_phi){};
	if (validate_args(argc, argv, &philo))
		return (1);
	printf("%d %d %d %d %d\n", philo.num_of_phi, philo.deadline, philo.eat, philo.sleep, philo.times);
}

int	validate_args(int argc, char **argv, t_phi *philo)
{
	int	i;

	i = 0;
	i |= ft_atoi_err(argv[1], &philo->num_of_phi);
	i |= ft_atoi_err(argv[2], &philo->deadline);
	i |= ft_atoi_err(argv[3], &philo->eat);
	i |= ft_atoi_err(argv[4], &philo->sleep);
	if (argc == 6)
		i |= ft_atoi_err(argv[5], &philo->times);
	return (i);
}

int	ft_atoi_err(char *s, int *i)
{
	char		sign;
	uint64_t	num;

	if (!s || !*s)
		return (1);
	num = 0;
	sign = 1;
	if (*s == '-' && '0' <= s[1] && s[1] <= '9')
		sign = -(!!*s++);
	if (*s == '0' && s[1])
		return (1);
	while ('0' <= *s && *s <= '9')
	{
		num = num * 10 + *s++ - '0';
		if ((sign > 0 && num > INT_MAX) || (sign < 0 && num > -(long)INT_MIN))
			return (1);
	}
	*i = sign * (int)num;
	return (*s && !('0' <= *s && *s <= '9'));
}
