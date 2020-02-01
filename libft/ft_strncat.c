/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 23:43:51 by iuolo             #+#    #+#             */
/*   Updated: 2019/09/10 16:39:48 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t len)
{
	size_t q;
	size_t z;

	q = 0;
	z = 0;
	while (dest[q] != '\0')
		q++;
	while (src[z] != '\0' && z < len)
	{
		dest[q] = src[z];
		q++;
		z++;
	}
	dest[q] = '\0';
	return (dest);
}
