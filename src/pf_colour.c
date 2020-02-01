/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_colour.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 22:14:20 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/31 17:57:48 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	col(t_print *ptr, char *find, char *replace)
{
	const char	*str;
	int			len;

	str = &ptr->format[ptr->i];
	len = ft_strlen(find);
	if (ft_memcmp(str, find, len) == 0)
	{
		pf_putnstr(ptr, replace, ft_strlen(replace));
		ptr->i += len;
		return (1);
	}
	return (0);
}

void		pf_colour(t_print *ptr)
{
	if (col(ptr, "{red}", "\033[0;31m") ||
		col(ptr, "{green}", "\033[0;32m") ||
		col(ptr, "{brown}", "\033[0;33m") ||
		col(ptr, "{yellow}", "\033[1;33m") ||
		col(ptr, "{blue}", "\033[0;34m") ||
		col(ptr, "{purple}", "\033[0;35m") ||
		col(ptr, "{cyan}", "\033[0;36m") ||
		col(ptr, "{eoc}", "\033[0m"))
		;
	else
	{
		pf_putchar(ptr, '{');
		ptr->i++;
	}
}
