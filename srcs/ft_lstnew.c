/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:17:17 by arsciand          #+#    #+#             */
/*   Updated: 2021/04/19 15:17:24 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstnew(const void *content, size_t content_size)
{
	t_lst	*node;
	void	*elem;

	if (!(node = ft_memalloc(sizeof(t_lst))))
		return (NULL);
	if (!content)
	{
		node->content = NULL;
		node->content_size = 0;
		node->next = NULL;
		node->prev = NULL;
		return (node);
	}
	if (!(elem = ft_memalloc(content_size)))
	{
		free(node);
		return (NULL);
	}
	ft_memcpy(elem, content, content_size);
	node->content = elem;
	node->content_size = content_size;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
