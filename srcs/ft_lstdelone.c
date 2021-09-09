/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:19:22 by arsciand          #+#    #+#             */
/*   Updated: 2021/09/09 12:23:26 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstdelone(t_lst **alst, void (*del)(void *))
{
    if (!alst || !*alst)
        return ;
    if (del)
        del((*alst)->content);
    if ((*alst)->content)
        ft_memdel(&(*alst)->content);
    free(*alst);
    *alst = NULL;
}
