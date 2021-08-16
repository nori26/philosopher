/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nosuzuki <nosuzuki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 06:00:44 by nosuzuki          #+#    #+#             */
/*   Updated: 2021/08/16 15:56:08 by nosuzuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_list	*del_set(t_list *lst, t_list *next, void (*del)(void*))
{
	ft_lstdelone(lst, del);
	return (next);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!lst)
		return ;
	while (*lst)
		*lst = del_set(*lst, (*lst)->next, del);
}
