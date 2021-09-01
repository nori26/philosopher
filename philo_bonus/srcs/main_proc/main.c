#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	int		ret;
	t_phi	*philo;
	sem_t	*sem;

	ret = 0;
	philo = NULL;
	if ((argc != 5 && argc != 6)
		|| philo_init(&philo)
		|| validate_args(argc, argv, philo)
		|| philo_utils_init(philo)
		|| 0)
		return (1);
	
}
