/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iuolo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:47:16 by iuolo             #+#    #+#             */
/*   Updated: 2019/09/18 23:59:57 by iuolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*str1;
	t_list	*str2;

	str1 = *alst;
	while (str1)
	{
		str2 = str1->next;
		del(str1->content, str1->content_size);
		free(str1);
		str1 = str2;
	}
	*alst = NULL;
}
