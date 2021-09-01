#include "philo_bonus.h"

size_t	ft_strlen(const char *str)
{
	uint64_t		longvalue;
	uint64_t const	*longptr;
	char const		*char_tmp;

	char_tmp = str;
	while ((uint64_t)char_tmp & 0b111)
		if (!*char_tmp++)
			return (--char_tmp - str);
	longptr = (uint64_t *)char_tmp;
	while (1)
	{
		longvalue = *longptr++;
		if (((longvalue - LSB_MASK) & ~longvalue & MSB_MASK))
		{
			char_tmp = (const char *)(longptr - 1);
			while (*char_tmp)
				char_tmp++;
			return (char_tmp - str);
		}
	}
}
