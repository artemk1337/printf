/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 04:49:32 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/20 21:45:54 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_print		ptr;

	ft_bzero(&ptr, sizeof(ptr));
	ptr.fd = 1;
	ptr.format = format;
	va_start(ptr.vl, format);
	pf_cycle(&ptr);
	va_end(ptr.vl);
	return (ptr.res);
}
