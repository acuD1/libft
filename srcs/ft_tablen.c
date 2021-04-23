/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:41:56 by arsciand          #+#    #+#             */
/*   Updated: 2021/04/23 15:53:32 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_tablen(const char **array)
{
    size_t  count = 0;

    for (size_t i = 0; array[i]; i++)
        count++;
    return (count);
}
