/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:36:34 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/17 22:43:04 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_output_chr(t_print *ptr)
{
	char	c;

	c = (char)va_arg(ptr->vl, int);
	if (ptr->minus)
	{
		pf_putchar(ptr, c);
		pf_repeat(ptr, ' ', ptr->width - 1);
	}
	else
	{
		pf_repeat(ptr, ' ', ptr->width - 1);
		pf_putchar(ptr, c);
	}
}
