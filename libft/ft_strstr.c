/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:19:40 by iuolo             #+#    #+#             */
/*   Updated: 2019/09/10 17:02:29 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strstr(const char *str, const char *needle)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)str);
	while (str[j] != '\0')
	{
		if (str[j] == needle[0])
		{
			while (needle[i] && str[j + i] == needle[i])
				i++;
			if (needle[i] == '\0')
				return ((char *)&str[j]);
		}
		j++;
	}
	return (NULL);
}
