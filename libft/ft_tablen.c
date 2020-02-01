/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 23:22:53 by iuolo             #+#    #+#             */
/*   Updated: 2019/09/17 23:41:56 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_tablen(char const *s)
{
	size_t	i1;
	size_t	i2;

	i1 = 0;
	i2 = 0;
	if (s == NULL)
		return (0);
	while (s[i1] == ' ' || s[i1] == '\n' || s[i1] == '\t')
		i1++;
	if (s[i1] == '\0')
		return (0);
	i2 = ft_strlen((char *)s) - 1;
	while (s[i2] == ' ' || s[i2] == '\n' || s[i2] == '\t')
		i2--;
	i2 = ft_strlen((char *)s) - i2;
	return (ft_strlen((char *)s) - i1 - i2 + 1);
}
