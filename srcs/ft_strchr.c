/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:24:14 by arsciand          #+#    #+#             */
/*   Updated: 2021/05/01 17:04:34 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#pragma clang diagnostic ignored "-Wcast-qual"

char    *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if ((char)c == *s)
            return ((char *)s);
        s++;
    }
    return (!(char)c ? (char *)&s[ft_strlen(s)] : NULL);
}
