/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejolyn <ejolyn@stud.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 12:19:58 by ejolyn            #+#    #+#             */
/*   Updated: 2020/11/02 21:00:15 by ejolyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *substr;
	char *flag;

	substr = (char *)malloc(len + 1);
	flag = substr;
	if (s == NULL)
		return (NULL);
	if (substr == NULL || (int) start >= ft_strlen(s))
		return (substr);
	while (start--)
		s++;
	while (len-- && *s != '\0')
		*substr++ = *s++;
	*substr = '\0';
	return (flag);
}
