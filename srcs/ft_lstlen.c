/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:09:20 by arsciand          #+#    #+#             */
/*   Updated: 2021/04/28 15:10:51 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_lstlen(t_lst *lst)
{
    t_lst   *node   = lst;
    size_t  len     = 0;

    if (!lst)
        return (0);
    while (node->next)
    {
        node = node->next;
        len++;
    }
    return (len + 1);
}
