/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 20:09:16 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/31 17:54:07 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double		get_arg(t_print *ptr)
{
	long double		n;

	if (ptr->length == LENGTH_BIG_L)
		n = (long double)va_arg(ptr->vl, long double);
	else
		n = (long double)va_arg(ptr->vl, double);
	return (n);
}

static unsigned long	pf_power(int n)
{
	unsigned long	res;

	res = 1;
	while (n > 0)
	{
		res *= 10;
		n--;
	}
	return (res);
}

static void				itoa_f(t_print *ptr, long double n)
{
	int				i;
	int				len;
	unsigned long	un;
	unsigned long	pt;

	pt = pf_power(ptr->point + 1);
	un = (unsigned long)n;
	n = (n - (long double)un) * (long double)pt;
	n = ((unsigned long)n % 10 > 4) ? n / 10 + 1 : n / 10;
	un += (unsigned long)n / (pt / 10);
	pt = (unsigned long)n % (pt / 10);
	pf_itoa_base(ptr->buff, pt, "0123456789");
	len = ft_strlen(ptr->buff);
	pf_itoa_base(ptr->buff, un, "0123456789");
	i = ft_strlen(ptr->buff);
	if (ptr->point > 0)
	{
		ptr->buff[i++] = '.';
		len = ptr->point - len;
		while (len-- > 0)
			ptr->buff[i++] = '0';
		pf_itoa_base(ptr->buff + i, pt, "0123456789");
	}
}

static void				output_f(t_print *ptr, char sign)
{
	int		len;

	len = ft_strlen(ptr->buff);
	ptr->width -= len;
	if (ptr->minus)
	{
		if (sign)
			pf_putchar(ptr, sign);
		pf_putnstr(ptr, ptr->buff, len);
		pf_repeat(ptr, ' ', ptr->width);
	}
	else
	{
		pf_repeat(ptr, ' ', ptr->width);
		if (sign)
			pf_putchar(ptr, sign);
		pf_putnstr(ptr, ptr->buff, len);
	}
}

void					pf_output_f(t_print *ptr)
{
	long double		n;
	char			sign;
	unsigned long	pt;
	unsigned long	un;

	n = get_arg(ptr);
	sign = '\0';
	if (ptr->space)
		sign = ' ';
	if (ptr->plus)
		sign = '+';
	if (n < 0)
		sign = '-';
	if (n < 0)
		n = -n;
	if (ptr->point < 0)
		ptr->point = 6;
	if (sign)
		ptr->width -= 1;
	itoa_f(ptr, n);
	output_f(ptr, sign);
}
