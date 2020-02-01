/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:39:51 by iuolo             #+#    #+#             */
/*   Updated: 2019/09/15 20:03:55 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_st_itoa(char *str, int n, int i)
{
	if (n == 0)
		str[0] = '0';
	if (n == -2147483648)
	{
		str[0] = '-';
		str[1] = '2';
		n = 147483648;
	}
	else if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[i--] = n % 10 + '0';
		n /= 10;
	}
}

char		*ft_itoa(int n)
{
	char	*nb;
	int		i;
	int		k;

	k = n;
	i = 0;
	if (n == 0)
		i++;
	while (k != 0)
	{
		k = k / 10;
		i++;
	}
	if (n < 0)
		i++;
	if (!(nb = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	nb[i--] = '\0';
	ft_st_itoa(nb, n, i);
	return (nb);
}
