/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_esc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 18:41:11 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/13 19:36:03 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_output_esc(t_print *ptr)
{
	if (ptr->minus)
	{
		pf_putchar(ptr, '%');
		pf_repeat(ptr, ' ', ptr->width - 1);
	}
	else
	{
		if (ptr->zero)
			pf_repeat(ptr, '0', ptr->width - 1);
		else
			pf_repeat(ptr, ' ', ptr->width - 1);
		pf_putchar(ptr, '%');
	}
}
