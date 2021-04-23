/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:24:14 by arsciand          #+#    #+#             */
/*   Updated: 2021/04/23 15:52:18 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
