/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:14:49 by arsciand          #+#    #+#             */
/*   Updated: 2021/09/18 16:15:25 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t ft_isnum(char *str)
{
	if (str == NULL)
		return (FALSE);
	if (*str == '\0')
		return (FALSE);
	if (*str == '-')
		str++;
	while (*str != '\0')
	{
		if (ft_isdigit(*str) == 0)
			return (FALSE);
		++str;
	}
	return (TRUE);
}
