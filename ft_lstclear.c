/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejolyn <ejolyn@stud.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:09:39 by ejolyn            #+#    #+#             */
/*   Updated: 2020/11/04 11:01:24 by ejolyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list **copy;

	copy = lst;
	if (*lst != NULL)
	{
		while (*lst != NULL)
		{
			del((*lst)->content);
			copy = lst;
			free(*lst);
			*lst = (*copy)->next;
		}
	}
}
