/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 21:42:51 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/20 21:44:45 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_fd(int fd, const char *format, ...)
{
	t_print		ptr;

	ft_bzero(&ptr, sizeof(ptr));
	ptr.fd = fd;
	ptr.format = format;
	va_start(ptr.vl, format);
	pf_cycle(&ptr);
	va_end(ptr.vl);
	return (ptr.res);
}
