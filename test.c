#include <string.h>
#include <limits.h>
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

// int	ft_atol_err2(char *s, int64_t *i)
// {
// 	char		sign;
// 	uint64_t	num;
// 	uint64_t	prev;

// 	if (!s || !*s)
// 		return (1);
// 	num = 0;
// 	sign = 0;
// 	if (*s == '-' && '0' <= s[1] && s[1] <= '9')
// 		sign = !!*s++;
// 	if (*s == '0' && s[1])
// 		return (1);
// 	while ('0' <= *s && *s <= '9')
// 	{
// 		prev = num;
// 		num = num * 10 + *s++ - '0';
// 		if (prev >> 60 || (num - sign) >> 63)
// 			return (1);
// 	}
// 	*i = num - (sign && num);
// 	if (sign)
// 		*i *= -1;
// 	return (*s && !('0' <= *s && *s <= '9'));
// }

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
	x = x ^ (x >> 16);
	x = x ^ (x >> 8);
	x = x ^ (x >> 4);
	x = x ^ (x >> 2);
	return ((x ^ (x >> 1)) & 1);
}
int add(int a, int b) { 
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

void    p(int (*f)())
{
    f("%daiueo\n", 1);
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	// int i = 7;
	// int n = **++argv - '0';

	// printf("%d\n", (n - !(n % 2)) % i);
	// printf("%d\n", (n - (n % 2)) % i);
    p(printf);
}