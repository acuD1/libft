/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:43:35 by arsciand          #+#    #+#             */
/*   Updated: 2021/09/06 12:30:09 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstfind(t_lst *lst, void *to_find, int (*f)(void *, void *))
{
	if (lst == NULL)
		return (NULL);
	return (f(lst->content, to_find) ? lst : ft_lstfind(lst->next, to_find, f));
}
