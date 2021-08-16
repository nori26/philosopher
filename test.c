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
#include "../../00/libft/libft.h"

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

int main()
{
	// pthread_t	test;
    // char        *s = malloc(100);

    // pthread_create(&test, NULL, func, s);
    // pthread_create(&test, NULL, func, s);
    // pthread_create(&test, NULL, func, s);
    // sleep(1);
    // puts("aiueo");
    // int i = 0;
    // pthread_exit(&i);
    int64_t i;
    if (ft_atol_err2("-1", &i))
        puts("aiueo");
    printf("%ld\n", i);
}
// int global_val = 0;

// void *
// thread_start_routine(void *data)
// {
//   int val = (int)data;
//   int i;

//   printf("thread_start_routine : val=%d\n", val);
//   for (i=0; i<10; i++) {
//     global_val++;
//     printf("thread_start_routine : i=%d, g=%d\n", i, global_val);

//     sleep(1);
//   }

//   return NULL;
// }

// int
// main()
// {
// //   int i;
//   pthread_t th;
//   void *th_ret;

//   if (pthread_create(&th, NULL, thread_start_routine, (void *)100) != 0) {
//     perror("pthread_create");
//     return 1;
//   }

// //   for (i=0; i<10; i++) {
// //     global_val++;
// //     printf("main : i=%d, g=%d\n", i, global_val);

// //     sleep(1);
// //   }

//   if (pthread_join(th, &th_ret) != 0) {
//     perror("pthread_join");
//     return 1;
//   }

//   return 0;
// }
