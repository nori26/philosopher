#include "philo_bonus.h"

int	count_digits(int64_t n)
{
	int	ret;

	ret = !n;
	while (n)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}
