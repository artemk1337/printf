/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cycle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 19:27:25 by iuolo             #+#    #+#             */
/*   Updated: 2020/02/02 00:43:27 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_flags(t_print *ptr)
{
	char	c;

	ptr->hash = 0;
	ptr->zero = 0;
	ptr->minus = 0;
	ptr->plus = 0;
	ptr->space = 0;
	while ((c = ptr->format[ptr->i]))
	{
		if (c == '#')
			ptr->hash = 1;
		else if (c == '0')
			ptr->zero = 1;
		else if (c == '-')
			ptr->minus = 1;
		else if (c == '+')
			ptr->plus = 1;
		else if (c == ' ')
			ptr->space = 1;
		else
			break ;
		ptr->i++;
	}
}

void	pf_point(t_print *ptr)
{
	char	c;

	ptr->point = -1;
	if (ptr->format[ptr->i] == '.')
	{
		ptr->point = 0;
		ptr->i++;
		if (ptr->format[ptr->i] == '*')
		{
			ptr->point = va_arg(ptr->vl, int);
			ptr->i++;
		}
		c = ptr->format[ptr->i];
		if (c >= '0' && c <= '9')
			ptr->point = 0;
		while ((c = ptr->format[ptr->i]))
			if (c >= '0' && c <= '9')
			{
				ptr->point = ptr->point * 10 + (c - '0');
				ptr->i++;
			}
			else
				break ;
	}
}

void	pf_type(t_print *ptr)
{
	ptr->type = ptr->format[ptr->i];
	ptr->i++;
}

void	pf_output(t_print *ptr)
{
	if (ptr->type == '%')
		pf_output_esc(ptr);
	else if (ptr->type == 'c')
		pf_output_chr(ptr);
	else if (ptr->type == 's')
		pf_output_str(ptr);
	else if (ptr->type == 'u')
		pf_output_u(ptr);
	else if (ptr->type == 'd')
		pf_output_d(ptr);
	else if (ptr->type == 'i')
		pf_output_d(ptr);
	else if (ptr->type == 'o')
		pf_output_o(ptr);
	else if (ptr->type == 'x')
		pf_output_x(ptr);
	else if (ptr->type == 'X')
		pf_output_x(ptr);
	else if (ptr->type == 'p')
		pf_output_p(ptr);
	else if (ptr->type == 'b')
		pf_output_b(ptr);
	else if (ptr->type == 'f')
		pf_output_f(ptr);
}

void	pf_cycle(t_print *ptr)
{
	char	c;

	if (ft_strcmp(ptr->format, "%") == 0)
		return ;
	while ((c = ptr->format[ptr->i]))
	{
		if (c == '%')
		{
			ptr->i++;
			pf_flags(ptr);
			pf_width(ptr);
			pf_point(ptr);
			pf_length(ptr);
			pf_type(ptr);
			pf_output(ptr);
		}
		else if (c == '{')
			pf_colour(ptr);
		else
		{
			pf_putchar(ptr, c);
			ptr->i++;
		}
	}
	pf_print_buff(ptr);
}
