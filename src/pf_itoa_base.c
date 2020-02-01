/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:52:20 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/18 21:37:43 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	buff_rev(char *buff, int len)
{
	int		i;
	char	tmp;

	i = (len / 2);
	while (i-- > 0)
	{
		tmp = buff[i];
		buff[i] = buff[len - i - 1];
		buff[len - i - 1] = tmp;
	}
}

void		pf_itoa_base(char *buff, unsigned long long n, char *base)
{
	int		len;
	int		len_base;

	len_base = ft_strlen(base);
	len = 0;
	while (n)
	{
		buff[len++] = base[n % len_base];
		n /= len_base;
	}
	if (len == 0)
		buff[len++] = base[0];
	buff[len] = '\0';
	buff_rev(buff, len);
}
