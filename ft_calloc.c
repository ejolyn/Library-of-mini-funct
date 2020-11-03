/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejolyn <ejolyn@stud.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 09:47:17 by ejolyn            #+#    #+#             */
/*   Updated: 2020/11/02 20:58:06 by ejolyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
	void *xx;
	size_t size2;

	size2 = size * count;
	xx = malloc (size2);
	if (xx)
		ft_bzero(xx, size2);
	return (xx);
}
