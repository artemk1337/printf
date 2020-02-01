/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:55:15 by iuolo             #+#    #+#             */
/*   Updated: 2019/09/17 23:49:12 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		k;
	char		*str;

	i = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * ft_tablen(s) + 1)))
		return (NULL);
	while ((s[k] == ' ') || s[k] == '\t' || s[k] == '\n')
		k++;
	while (i < ft_tablen(s))
	{
		str[i] = s[k];
		k++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
