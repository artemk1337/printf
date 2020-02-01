/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:21:15 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/20 19:55:12 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void					output_p_del(t_print *ptr, int len)
{
	if (ptr->minus)
	{
		if (ptr->hash)
		{
			pf_putchar(ptr, '0');
			pf_putchar(ptr, 'x');
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
			pf_putchar(ptr, 'x');
		}
		pf_repeat(ptr, '0', ptr->point);
		pf_putnstr(ptr, ptr->buff, len);
	}
}

void						pf_output_p(t_print *ptr)
{
	unsigned long long	n;
	int					len;

	n = (unsigned long long)va_arg(ptr->vl, unsigned long long);
	pf_itoa_base(ptr->buff, n, "0123456789abcdef");
	len = ft_strlen(ptr->buff);
	if (ptr->point == 0 && n == 0)
	{
		ptr->buff[0] = '\0';
		len = 0;
	}
	ptr->hash = 1;
	if (ptr->minus)
		ptr->zero = 0;
	if (ptr->point < 0 && ptr->zero)
		ptr->point = ptr->width;
	ptr->point -= len;
	ptr->width -= len + (ptr->hash ? 2 : 0);
	if (ptr->point > 0)
		ptr->width -= ptr->point;
	output_p_del(ptr, len);
}
