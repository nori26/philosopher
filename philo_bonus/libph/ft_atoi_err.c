/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_err.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 23:40:26 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/09/02 23:40:26 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atol_err(char *s, int64_t *i)
{
	char		sign;
	uint64_t	num;
	uint64_t	prev;

	if (!s || !*s)
		return (1);
	num = 0;
	sign = 1;
	if (*s == '-' && '0' <= s[1] && s[1] <= '9')
		sign = -!!*s++;
	if (*s == '0' && s[1])
		return (1);
	while ('0' <= *s && *s <= '9')
	{
		prev = num;
		num = num * 10 + *s++ - '0';
		if (prev >> 60 || (num - (sign < 0)) >> 63)
			return (1);
	}
	*i = sign * num;
	return (*s && !('0' <= *s && *s <= '9'));
}
