/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:37:56 by iuolo             #+#    #+#             */
/*   Updated: 2019/09/21 02:03:12 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ffree(char **arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char		*func(char const *s, char c, int i, char **arr)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * (ft_found_len(s, c)));
	if (!str)
	{
		ffree(arr, i);
		return (NULL);
	}
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**arr;

	i = 0;
	if (!s || !(arr = (char**)malloc(sizeof(char*) *
					(ft_words_counter(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			if (!(arr[i] = func(s, c, i, arr)))
				return (NULL);
			j = 0;
			while (*s != c && *s)
				arr[i][j++] = *(s++);
			arr[i++][j] = '\0';
		}
	}
	arr[i] = NULL;
	return (arr);
}
