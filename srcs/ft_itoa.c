/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 16:11:32 by arsciand          #+#    #+#             */
/*   Updated: 2021/09/09 12:23:04 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t   count_n_len(int32_t n)
{
    size_t	i;

    i = 0;
    while (n)
    {
        n /= 10;
        i++;
    }
    return (i);
}

static void     do_conv(char *buffer, int64_t n, size_t i)
{
    if (n > 0)
    {
        do_conv(buffer, n / 10, --i);
        buffer[i] = n % 10 + '0';
    }
}

char            *ft_itoa(int32_t n)
{
    char    s[12];
    size_t  len;

    ft_memset(&s, 0, sizeof(s));
    len = count_n_len(n);
    if (n == 0)
        return (ft_strdup("0"));
    if (n < 0)
    {
        s[0] = '-';
        do_conv(s + 1, -(int64_t)n, len);
    }
    else
        do_conv(s + 0, (int64_t)n, len);
    return (ft_strdup(s));
}
