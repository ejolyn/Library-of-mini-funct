/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejolyn <ejolyn@stud.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 12:18:21 by ejolyn            #+#    #+#             */
/*   Updated: 2020/11/02 20:58:31 by ejolyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void static reverse(char *str, int len)
{
	int i;
	char c;

	i = 0;
	c = 0;
	while (len >= i)
	{
		c = str[i];
		str[i] = str[len];
		str[len] = c;
		i++;
		len--;
	}
}

char *ft_itoa(int n)
{
	int n2;
	int len;
	char *str;
	int i;
	unsigned int nbr;

	i = 0;
	n2 = n;
	len = 1;
	while (n2 /= 10)
		len++;
	nbr = (n < 0) ? (unsigned int)-n : n;
	n2 = (n < 0) ? 1 : 0;
	len = (n < 0) ? len + 1 : len;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return(str);
	if (n == 0)
		str[i++] = '0';
	while (nbr)
	{
		str[i++] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (n2)
		str[i++] = '-';
	str[i] = '\0';
	reverse (str, i-1);
	return (str);
}