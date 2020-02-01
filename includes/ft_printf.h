/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <iuolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:41:38 by iuolo             #+#    #+#             */
/*   Updated: 2020/02/01 23:49:30 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define BUFF_SIZE 100

typedef enum		e_length
{
	LENGTH_NONE,
	LENGTH_HH,
	LENGTH_H,
	LENGTH_L,
	LENGTH_LL,
	LENGTH_BIG_L
}					t_length;

typedef	struct		s_print
{
	const char		*format;
	int				i;
	va_list			vl;
	int				res;
	char			type;
	int				minus;
	int				plus;
	int				space;
	int				hash;
	int				zero;
	int				width;
	int				point;
	t_length		length;
	unsigned int	p_i;
	char			buff[100];
	char			bp[BUFF_SIZE];
	int				bp_i;
	int				fd;
}					t_print;

int					ft_printf(const char *format, ...);
int					ft_printf_fd(int fd, const char *format, ...);
void				pf_cycle(t_print *ptr);
void				pf_repeat(t_print *ptr, char c, int len);
void				pf_output_esc(t_print *ptr);
void				pf_output_sign(t_print *ptr);
void				pf_output_chr(t_print *ptr);
void				pf_output_str(t_print *ptr);
void				pf_output_u(t_print *ptr);
void				pf_output_d(t_print *ptr);
void				pf_output_o(t_print *ptr);
void				pf_output_x(t_print *ptr);
void				pf_putchar(t_print *ptr, char c);
void				pf_putnstr(t_print *ptr, char *str, int len);
void				pf_itoa_base(char *buff, unsigned long long n, char *base);
void				pf_length(t_print *ptr);
void				pf_width(t_print *ptr);
void				pf_output_p(t_print *ptr);
void				pf_print_buff(t_print *ptr);
void				pf_output_b(t_print *ptr);
void				pf_output_f(t_print *ptr);
void				pf_colour(t_print *ptr);

#endif
