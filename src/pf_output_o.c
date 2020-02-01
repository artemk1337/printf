/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 22:46:39 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/20 20:33:08 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	output_o(t_print *ptr, int len)
{
	if (ptr->minus)
	{
		if (ptr->hash)
			pf_putchar(ptr, '0');
		pf_repeat(ptr, '0', ptr->point);
		pf_putnstr(ptr, ptr->buff, len);
		pf_repeat(ptr, ' ', ptr->width);
	}
	else
	{
		pf_repeat(ptr, ' ', ptr->width);
		if (ptr->hash)
			pf_putchar(ptr, '0');
		pf_repeat(ptr, '0', ptr->point);
		pf_putnstr(ptr, ptr->buff, len);
	}
}

static void	output_op(t_print *ptr, int len)
{
	if (ptr->minus)
		ptr->zero = 0;
	if (ptr->point < 0 && ptr->zero)
		ptr->point = ptr->width;
	ptr->point -= len + (ptr->hash ? 1 : 0);
	ptr->width -= len + (ptr->hash ? 1 : 0);
	if (ptr->point > 0)
		ptr->width -= ptr->point;
}

void		pf_output_o(t_print *ptr)
{
	unsigned long long	n;
	int					len;

	if (ptr->length == LENGTH_HH)
		n = (unsigned long long)(unsigned char)va_arg(ptr->vl, unsigned int);
	else if (ptr->length == LENGTH_H)
		n = (unsigned long long)(unsigned short)va_arg(ptr->vl, unsigned int);
	else if (ptr->length == LENGTH_L)
		n = (unsigned long long)va_arg(ptr->vl, unsigned long);
	else if (ptr->length == LENGTH_LL)
		n = (unsigned long long)va_arg(ptr->vl, unsigned long long);
	else
		n = (unsigned long long)va_arg(ptr->vl, unsigned);
	pf_itoa_base(ptr->buff, n, "01234567");
	len = ft_strlen(ptr->buff);
	if ((ptr->hash || ptr->point == 0) && n == 0)
	{
		ptr->buff[0] = '\0';
		len = 0;
	}
	output_op(ptr, len);
	output_o(ptr, len);
}
