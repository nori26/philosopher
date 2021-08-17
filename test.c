#include <stdlib.h>
#include <errno.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include "includes/philo.h"
#include <pthread.h>

// int	ft_atol_err2(char *s, int64_t *i)
// {
// 	char		sign;
// 	uint64_t	num;
// 	uint64_t	prev;

// 	if (!s || !*s)
// 		return (1);
// 	num = 0;
// 	sign = 1;
// 	if (*s == '-' && '0' <= s[1] && s[1] <= '9')
// 		sign = -!!*s++;
// 	if (*s == '0' && s[1])
// 		return (1);
// 	while ('0' <= *s && *s <= '9')
// 	{
// 		prev = num;
// 		num = num * 10 + *s++ - '0';
// 		if (prev >> 60 || (num - (sign < 0)) >> 63)
// 			return (1);
// 	}
// 	*i = sign * num;
// 	return (*s && !('0' <= *s && *s <= '9'));
// }

int	ft_atol_err2(char *s, int64_t *i)
{
	char		sign;
	uint64_t	num;
	uint64_t	prev;

	if (!s || !*s)
		return (1);
	num = 0;
	sign = 0;
	if (*s == '-' && '0' <= s[1] && s[1] <= '9')
		sign = !!*s++;
	if (*s == '0' && s[1])
		return (1);
	while ('0' <= *s && *s <= '9')
	{
		prev = num;
		num = num * 10 + *s++ - '0';
		if (prev >> 60 || (num - sign) >> 63)
			return (1);
	}
	*i = num - (sign && num);
	if (sign)
		*i *= -1;
	return (*s && !('0' <= *s && *s <= '9'));
}

#include <string.h>
int g;
void *func(void *arg)
{
    int i = 0;
    char *s = arg;
    struct timeval t;

    printf("%d\n", g++);
    while (i < 10)
    {
        s[i] = 'a' + i;
        s[i + 1] = 0;
        gettimeofday(&t, NULL);
        printf("%ld %s\n", t.tv_usec, s);
        fflush(stdout);
        // write(1, "ai\n", 3);
        i++;
    }
    return (arg);
}

int odd_ones(unsigned x)
{
	unsigned j = x ^ (x >> 16);
	unsigned k = j ^ (j >> 8);
	unsigned l = k ^ (k >> 4);
	unsigned m = l ^ (l >> 2);
	return ((m ^ (m >> 1)) & 1);
}
int main()
{
	printf("%d\n", odd_ones(0b01100000000110000000010000000011));
}
