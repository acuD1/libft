/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:18:04 by arsciand          #+#    #+#             */
/*   Updated: 2021/04/23 15:32:22 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_isblank(char c)
{
    return (c == ' ' || c == '\n' || c == '\t');
}