/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejolyn <ejolyn@stud.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:45:38 by ejolyn            #+#    #+#             */
/*   Updated: 2020/11/04 22:25:45 by ejolyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copy;
	int		len;
	int		len2;
	int		len3;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	len2 = 0;
	len3 = len;
	while (ft_strchr(set, s1[len2]))
		len2++;
	while (ft_strchr(set, s1[len]))
		len--;
	if (len2 >= len)
		return ("\0");
	copy = (char *)malloc(len - len2 + 2);
	if (copy == NULL)
		return (copy);
	ft_strlcat(copy, s1, len3 + 1);
	ft_strlcpy(&copy[0], &s1[len2], len - len2 + 2);
	copy[len + 1] = '\0';
	return (copy);
}