/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:43:35 by arsciand          #+#    #+#             */
/*   Updated: 2021/04/29 12:44:47 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstfind(
            t_lst *lst, void *to_find, void *content, int (*f)(void *, void *))
{
	if (lst == NULL)
		return (NULL);
	return (f(content, to_find)
        ? lst : ft_lstfind(lst->next, content, to_find, f));
}
