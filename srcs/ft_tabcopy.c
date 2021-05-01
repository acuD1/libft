/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:53:18 by arsciand          #+#    #+#             */
/*   Updated: 2021/05/01 16:44:36 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    **ft_tabcopy(char **tab_dest, const char * const *tab_copy)
{
    size_t	i = 0;

    if (!tab_copy
        || !(tab_dest = malloc(sizeof(char *) * (ft_tablen(tab_copy) + 1))))
        return (NULL);
    while (tab_copy[i])
    {
        if (!(tab_dest[i] = ft_strdup(tab_copy[i])))
        {
            ft_tabdel(&tab_dest);
            return (NULL);
        }
        i++;
    }
    tab_dest[i] = NULL;
    return (tab_dest);
}
