/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:19:28 by iuolo             #+#    #+#             */
/*   Updated: 2019/09/21 01:33:04 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*str;

	if (!(str = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == 0)
	{
		str->content = NULL;
		str->content_size = 0;
	}
	else
	{
		if (!(str->content = malloc(content_size)))
		{
			free(str);
			return (NULL);
		}
		ft_memmove((str->content), content, content_size);
		str->content_size = content_size;
	}
	str->next = NULL;
	return (str);
}
