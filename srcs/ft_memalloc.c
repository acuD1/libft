/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:01:13 by arsciand          #+#    #+#             */
/*   Updated: 2021/04/23 15:32:36 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
    void	*mem = NULL;

    if (!size)
        return (NULL);
    if (!(mem = (void *)malloc(size)))
        return (NULL);
    ft_memset(mem, 0, size);
    return (mem);
}
