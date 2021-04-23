/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:26:15 by arsciand          #+#    #+#             */
/*   Updated: 2021/04/23 15:33:04 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t	ft_strequ(const char *s1, const char *s2)
{
    return (s1 && s2 && ft_strcmp(s1, s2) == 0 ? 1 : 0);
}
