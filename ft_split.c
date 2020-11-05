/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejolyn <ejolyn@stud.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:12:21 by ejolyn            #+#    #+#             */
/*   Updated: 2020/11/05 13:12:06 by ejolyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_counter_str(char const *s, char c)
{
	int str;

	str = 0;
	while (*s++ == c)
		;
	s--;
	if (c == '\0')
		return (1);
	while (*s)
	{
		while (*s != c && *s != '\0')
			s++;
		str++;
		while (*s == c)
			s++;
	}
	return (str);
}

static	int		ft_counter_len(char const *s, char c, int *j)
{
	int len;
	int k;

	len = 0;
	k = (*j > 0) ? (*j + 1) : (*j);
	while (s[k] == c && s[k] != '\0')
		k++;
	while (s[k] != c && s[k] != '\0')
	{
		len++;
		k++;
	}
	*j = k - len;
	return (len);
}

static	char	**free_helper(char **divide, int i)
{
	while (--i >= 0)
		free(divide[i]);
	free(divide);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**divide;
	int		i;
	int		j;
	int		str;
	int		len;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	str = ft_counter_str(s, c);
	divide = (char **)malloc((str + 1) * sizeof(char *));
	if (divide == NULL)
		return (NULL);
	while (i < str)
	{
		len = ft_counter_len(s, c, &j);
		divide[i] = ft_substr(s, j, len);
		if (divide[i] == NULL)
			return (free_helper(divide, i));
		j = (j + len < ft_strlen(s)) ? j + len : j;
		i++;
	}
	divide[i] = NULL;
	return (divide);
}
