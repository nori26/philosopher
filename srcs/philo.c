#include "philo.h"

int	main(int argc, char **argv)
{
	t_phi		*philo;

	if ((argc != 5 && argc != 6)
		|| philo_init(&philo)
		|| validate_args(argc, argv, philo))
		return (1);
	free(philo);
}

int32_t	philo_init(t_phi **philo)
{
	*philo = malloc(sizeof(philo));
	if (!*philo)
		return (1);
	**philo = (t_phi){};
	return (0);
}

int32_t	validate_args(int argc, char **argv, t_phi *philo)
{
	if (ft_atol_err(argv[1], &philo->num_of_phi)
		|| ft_atol_err(argv[2], &philo->deadline)
		|| ft_atol_err(argv[3], &philo->eat)
		|| ft_atol_err(argv[4], &philo->sleep)
		|| (argc == 6 && ft_atol_err(argv[5], &philo->times))
		|| philo->num_of_phi < 0
		|| philo->deadline < 0
		|| philo->eat < 0
		|| philo->sleep < 0
		|| philo->times < 0)
		return (freeturn(&philo, 1));
	printf("%d %d %d %d %d\n", philo->num_of_phi, philo->deadline, philo->eat, philo->sleep, philo->times);
	return (0);
}

int	create_threads(t_phi *philo)
{
	size_t		i;
	pthread_t	*th;

	th = malloc(philo->num_of_phi);
	if (!th)
		return (1);
	i = 0;
	while (i < philo->num_of_phi)
		if (pthread_create(&th[i++], NULL, start_philo, philo))
			return (freeturn(&th, 1));
	i = 0;
	while (i < philo->num_of_phi)
		if (pthread_join(th[i++], NULL))
			return (freeturn(&th, 1));
	return (freeturn(&th, 0));
}
