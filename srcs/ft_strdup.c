/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:05:02 by arsciand          #+#    #+#             */
/*   Updated: 2021/04/23 15:53:00 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strdup(const char *s)
{
    char    *dst = NULL;

    if (!(dst = ft_memalloc(ft_strlen(s) + 1)))
        return (NULL);
    ft_strcpy(dst, s);
    return (dst);
}
