/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 21:48:36 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/09/02 21:48:44 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPH_H
# define LIBPH_H
# include <pthread.h>
# include <stdint.h>

int		count_digits(int64_t n);
int		ft_atol_err(char *s, int64_t *i);
int64_t	get_msec(void);
int64_t	get_usec(void);
int64_t	mtx_do_func(void *arg, pthread_mutex_t *lock, int64_t (*func)());

#endif
