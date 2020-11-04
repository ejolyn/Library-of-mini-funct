/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejolyn <ejolyn@stud.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:10:07 by ejolyn            #+#    #+#             */
/*   Updated: 2020/11/04 10:33:10 by ejolyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t needlelen;
	size_t len2;

	len2 = len;
	needlelen = ft_strlen(needle);
	if (!needlelen)
		return ((char *)haystack);
	if (*haystack == 0)
		return (NULL);
	while (len >= needlelen)
	{
		if (*haystack++ == *needle)
			if (ft_strncmp(--haystack, needle, len) == 0)
				return ((char *)haystack);
		len--;
	}
	return (NULL);
}
