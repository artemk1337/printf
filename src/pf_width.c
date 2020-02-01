/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:06:26 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/20 20:29:12 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_width(t_print *ptr)
{
	char	c;

	ptr->width = 0;
	if (ptr->format[ptr->i] == '*')
	{
		ptr->width = va_arg(ptr->vl, int);
		ptr->i++;
		if (ptr->width < 0)
			ptr->minus = 1;
		if (ptr->width < 0)
			ptr->width = -ptr->width;
	}
	c = ptr->format[ptr->i];
	if (c >= '0' && c <= '9')
		ptr->width = 0;
	while ((c = ptr->format[ptr->i]))
	{
		if (c >= '0' && c <= '9')
		{
			ptr->width = ptr->width * 10 + (c - '0');
			ptr->i++;
		}
		else
			break ;
	}
}
