/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:16:34 by arsciand          #+#    #+#             */
/*   Updated: 2021/04/23 15:32:26 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstappend(t_lst **alst, t_lst *new)
{
    t_lst	*node = *alst;

    if (!new)
        return (NULL);
    if (node)
    {
        while (node->next)
            node = node->next;
        node->next = new;
        new->prev = node;
    }
    else
        *alst = new;
    return (new);
}
