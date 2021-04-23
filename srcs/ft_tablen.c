/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 12:41:56 by arsciand          #+#    #+#             */
/*   Updated: 2021/04/23 12:45:25 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_tablen(const char **array)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (array[i])
	{
		count++;
		i++;
	}
	return (count);
}
