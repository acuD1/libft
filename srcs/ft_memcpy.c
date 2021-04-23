/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:39:34 by arsciand          #+#    #+#             */
/*   Updated: 2021/04/23 15:51:17 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memcpy(void *dst, const void *s, size_t n)
{
    const char  *tmp_s = s;
    char        *tmp_dst = dst;

    for (size_t i = 0; n--; i++)
        tmp_dst[i] = tmp_s[i];
    return (dst);
}
