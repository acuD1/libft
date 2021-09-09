/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:40:48 by arsciand          #+#    #+#             */
/*   Updated: 2021/09/09 12:25:09 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strcmp(const char *s1, const char *s2)
{
    return (*s1 && *s2 && *s1 == *s2
            ? ft_strcmp(++s1, ++s2) : (unsigned char)*s1 - (unsigned char)*s2);
}
