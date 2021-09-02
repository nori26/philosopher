#ifndef LIBPH_H
# define LIBPH_H
# include <pthread.h>
# include <stdint.h>
# define LSB_MASK 0x0101010101010101ull
# define MSB_MASK 0x8080808080808080ull

int		count_digits(int64_t n);
int		ft_atol_err(char *s, int64_t *i);
size_t	ft_strlen(const char *str);
int64_t	get_msec(void);
int64_t	get_usec(void);
int64_t	sem_do_func(void *arg, sem_t *sem, int64_t (*func)());

#endif
