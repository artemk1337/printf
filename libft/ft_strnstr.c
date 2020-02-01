/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 03:43:13 by iuolo             #+#    #+#             */
/*   Updated: 2019/09/10 17:34:49 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	int		i;
	size_t	len_needle;

	if (needle[0] == 0)
		return ((char *)str);
	i = 0;
	len_needle = ft_strlen(needle);
	while (str[i] && len - i >= len_needle)
	{
		if (!ft_memcmp(&str[i], needle, len_needle))
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
