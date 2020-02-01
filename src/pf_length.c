/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:59:22 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/20 16:04:11 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	length(t_print *ptr, char c0, char c1)
{
	if (c0 == 'h' && c1 == 'h')
	{
		ptr->length = LENGTH_HH;
		ptr->i += 2;
	}
	else if (c0 == 'h')
	{
		ptr->length = LENGTH_H;
		ptr->i += 1;
	}
	else if (c0 == 'l' && c1 == 'l')
	{
		ptr->length = LENGTH_LL;
		ptr->i += 2;
	}
	else if (c0 == 'l')
	{
		ptr->length = LENGTH_L;
		ptr->i += 1;
	}
	else if (c0 == 'L')
	{
		ptr->length = LENGTH_BIG_L;
		ptr->i += 1;
	}
}

void		pf_length(t_print *ptr)
{
	char	c0;
	char	c1;

	ptr->length = LENGTH_NONE;
	c0 = ptr->format[ptr->i];
	if (c0)
	{
		c1 = ptr->format[ptr->i + 1];
		length(ptr, c0, c1);
	}
}
