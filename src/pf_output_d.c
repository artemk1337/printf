/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 23:31:01 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/20 15:36:20 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	pf_long(t_print *ptr)
{
	long long		n;

	if (ptr->length == LENGTH_HH)
		n = (long long)(char)va_arg(ptr->vl, int);
	else if (ptr->length == LENGTH_H)
		n = (long long)(short)va_arg(ptr->vl, int);
	else if (ptr->length == LENGTH_L)
		n = (long long)va_arg(ptr->vl, long);
	else if (ptr->length == LENGTH_LL)
		n = (long long)va_arg(ptr->vl, long long);
	else
		n = (long long)va_arg(ptr->vl, int);
	return (n);
}

static void			output_d(t_print *ptr, char sign, int len)
{
	if (sign)
		ptr->width -= 1;
	if (ptr->minus)
		ptr->zero = 0;
	if (ptr->point <= 0 && ptr->zero)
		ptr->point = ptr->width;
	ptr->point -= len;
	ptr->width -= len;
	if (ptr->point > 0)
		ptr->width -= ptr->point;
}

static void			output(t_print *ptr, char sign, int len)
{
	if (ptr->minus)
	{
		if (sign)
			pf_putchar(ptr, sign);
		pf_repeat(ptr, '0', ptr->point);
		pf_putnstr(ptr, ptr->buff, len);
		pf_repeat(ptr, ' ', ptr->width);
	}
	else
	{
		pf_repeat(ptr, ' ', ptr->width);
		if (sign)
			pf_putchar(ptr, sign);
		pf_repeat(ptr, '0', ptr->point);
		pf_putnstr(ptr, ptr->buff, len);
	}
}

void				pf_output_d(t_print *ptr)
{
	long long	n;
	int			len;
	char		sign;

	n = pf_long(ptr);
	pf_itoa_base(ptr->buff, (n < 0 ? -n : n), "0123456789");
	len = ft_strlen(ptr->buff);
	sign = '\0';
	if (ptr->space)
		sign = ' ';
	if (ptr->plus)
		sign = '+';
	if (n < 0)
		sign = '-';
	if (ptr->point == 0 && n == 0 && !sign)
	{
		ptr->buff[0] = '\0';
		len = 0;
	}
	output_d(ptr, sign, len);
	output(ptr, sign, len);
}
