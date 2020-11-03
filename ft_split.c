/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejolyn <ejolyn@stud.21-school.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:12:21 by ejolyn            #+#    #+#             */
/*   Updated: 2020/11/03 11:16:22 by ejolyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int static counter_str(char const *s, char c)
{
	int str;

	str = 0;
	while (*s)
	{
		while (*s++ == c)
			;
		if (*--s != c)
		{
			str++;
			while (*s != c && *s++ != '\0')
				;
		}
	}
	return(str - 1);
}
size_t static counter_len(char const *s, char c, int *j)
{
	size_t len;
	int k;

	len = 0;
	k = *j;
	while (s[k] == c && s[k] != '\0')
		k++;
	while (s[k++] != c)
		len++;
	*j = k - 1 - len;
	return(len + 1);
}
char **free_helper(char **divide, int i)
{
	while (--i >= 0)
		free(divide[i]);
	free (divide);
	return ((char **)NULL);
}
char **ft_split(char const *s, char c)
{
	char **divide;
	int i;
	int j;
	int str;
	size_t len;

	i = 0;
	j = 0;
	str = counter_str(s, c) - 1;
	divide = (char **) malloc ((str + 1) * sizeof(char *));
	if (divide == NULL)
		return((char **)NULL);
	while (i < str)
	{
		len = counter_len(s, c, &j);
		divide[i] = (char *) malloc(len);
		if (divide[i] == NULL)
			return (free_helper(divide, i));
		divide[i] = ft_substr(s, j, len - 1);
		if (j < ft_strlen(s))
			j += len - 1;
		i++;
	}
	divide[i] = NULL;
	return(divide);
}
int main()
{
char *string = "split  ||this|for|me|||||!|";
char **result = ft_split(string, '|');
int i = -1;
while (result[++i])
    printf("%s\n", result[i]);
  return 0;
}