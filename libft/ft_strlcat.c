/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 01:57:24 by iuolo             #+#    #+#             */
/*   Updated: 2019/09/10 23:20:37 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	d1;
	size_t	d2;

	d1 = ft_strlen(dest);
	d2 = ft_strlen(src);
	if (size == 0)
		return (d2);
	if (size - 1 < d1)
		return (d2 + size);
	i = 0;
	while ((d1 + i < size - 1) && src[i])
	{
		dest[d1 + i] = src[i];
		i++;
	}
	dest[d1 + i] = '\0';
	return (d1 + d2);
}
