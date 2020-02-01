/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 22:00:22 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/20 22:06:08 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	get_arg(t_print *ptr)
{
	unsigned long long	n;

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
	return (n);
}

static void					output_b_del(t_print *ptr, int len)
{
	if (ptr->minus)
	{
		if (ptr->hash)
		{
			pf_putchar(ptr, '0');
			pf_putchar(ptr, 'b');
		}
		pf_repeat(ptr, '0', ptr->point);
		pf_putnstr(ptr, ptr->buff, len);
		pf_repeat(ptr, ' ', ptr->width);
	}
	else
	{
		pf_repeat(ptr, ' ', ptr->width);
		if (ptr->hash)
		{
			pf_putchar(ptr, '0');
			pf_putchar(ptr, 'b');
		}
		pf_repeat(ptr, '0', ptr->point);
		pf_putnstr(ptr, ptr->buff, len);
	}
}

void						pf_output_b(t_print *ptr)
{
	unsigned long long	n;
	int					len;

	n = get_arg(ptr);
	pf_itoa_base(ptr->buff, n, "01");
	len = ft_strlen(ptr->buff);
	if (ptr->point == 0 && n == 0)
	{
		ptr->buff[0] = '\0';
		len = 0;
	}
	if (n == 0)
		ptr->hash = 0;
	if (ptr->minus)
		ptr->zero = 0;
	if (ptr->point < 0 && ptr->zero)
		ptr->point = ptr->width;
	ptr->point -= len + (ptr->zero && ptr->hash ? 2 : 0);
	ptr->width -= len + (ptr->hash ? 2 : 0);
	if (ptr->point > 0)
		ptr->width -= ptr->point;
	output_b_del(ptr, len);
}
