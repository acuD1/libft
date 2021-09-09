/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:17:51 by arsciand          #+#    #+#             */
/*   Updated: 2021/09/09 12:21:24 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_lst    *eraser(t_lst *current, void (*del)(void *))
{
    if (current)
    {
        eraser(current->next, del);
        ft_lstdelone(&current, del);
    }
    return (NULL);
}

void            *ft_lstdel(t_lst **alst, void (*del)(void *))
{
    if (!alst || !*alst)
        return (NULL);
    *alst = eraser(*alst, del);
    return (NULL);
}
