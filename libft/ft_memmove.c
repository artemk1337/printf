/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 23:50:34 by iuolo             #+#    #+#             */
/*   Updated: 2019/09/10 16:20:21 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;
	int				i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (ptr_dst <= ptr_src)
		while (i < (int)len)
		{
			ptr_dst[i] = ptr_src[i];
			i++;
		}
	else
	{
		i = len - 1;
		while (i >= 0)
		{
			ptr_dst[i] = ptr_src[i];
			i--;
		}
	}
	return (dst);
}
