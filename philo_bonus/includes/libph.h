/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 00:01:27 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/09/03 13:39:52 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBPH_H
# define LIBPH_H
# include <pthread.h>
# include <stdint.h>
# include <semaphore.h>
# define LSB_MASK 0x0101010101010101ull
# define MSB_MASK 0x8080808080808080ull

int		count_digits(int64_t n);
int		ft_atol_err(char *s, int64_t *i);
size_t	ft_strlen(const char *str);
int64_t	get_msec(void);
int64_t	get_usec(void);
void	philo_iterator(void *philo, int64_t n, void (*func)());
int64_t	sem_do_func(void *arg, sem_t *sem, int64_t (*func)());

#endif
