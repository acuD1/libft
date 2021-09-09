/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:00:05 by arsciand          #+#    #+#             */
/*   Updated: 2021/09/09 12:23:45 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstiter(t_lst *lst, void (*f)(void *content))
{
    if (lst)
    {
        f(lst->content);
        ft_lstiter(lst->next, f);
    }
}
