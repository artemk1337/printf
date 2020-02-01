/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:03:42 by iuolo             #+#    #+#             */
/*   Updated: 2019/09/18 03:16:57 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	str = (char *)malloc((len + 1) * sizeof(char));
	ft_strncpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}
