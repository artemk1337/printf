/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:42:02 by iuolo             #+#    #+#             */
/*   Updated: 2019/09/13 12:10:29 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_is_nbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
}

void			ft_putnbr(int n)
{
	int		f;
	int		i;
	char	s[12];

	f = 0;
	i = 0;
	ft_is_nbr(n);
	if (n == -2147483648)
		return ;
	if (n < 0)
	{
		n *= -1;
		f = 1;
	}
	while (n > 0)
	{
		s[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	if (f == 1)
		s[i++] = '-';
	while (i > 0)
		ft_putchar(s[--i]);
}
