/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_ctx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:19:53 by arsciand          #+#    #+#             */
/*   Updated: 2021/09/10 16:30:46 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t ft_lstiter_ctx(t_lst *lst, void *context,
            uint8_t (*f)(void *content, void *context))
{
    if (lst)
    {
        if (f(lst->content, context) == FAILURE)
            return (FAILURE);
        return (ft_lstiter_ctx(lst->next, context, f));
    }
    return (SUCCESS);
}
