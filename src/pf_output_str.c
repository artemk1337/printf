/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 19:41:24 by iuolo             #+#    #+#             */
/*   Updated: 2020/01/20 17:19:43 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_output_str(t_print *ptr)
{
	char	*str;
	int		len;

	str = (char *)va_arg(ptr->vl, char *);
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (ptr->point >= 0 && ptr->point < len)
		len = ptr->point;
	if (ptr->minus)
	{
		pf_putnstr(ptr, str, len);
		pf_repeat(ptr, ' ', ptr->width - len);
	}
	else
	{
		pf_repeat(ptr, ' ', ptr->width - len);
		pf_putnstr(ptr, str, len);
	}
}
