/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words_counter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 01:26:26 by iuolo             #+#    #+#             */
/*   Updated: 2019/09/18 19:15:37 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_words_counter(const char *s, char c)
{
	size_t i;
	size_t words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		if (s[i] != c)
		{
			i = i + ft_found_len((char*)&s[i], c);
			words++;
		}
	}
	return (words);
}
