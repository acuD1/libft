/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:08:00 by arsciand          #+#    #+#             */
/*   Updated: 2021/02/26 15:15:10 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "stddef.h"

/*
**  STRING
*/

void        ft_putstr(char const *s);
void		ft_putstr_fd(char const *s, int fd);
size_t		ft_strlen(const char *s);

#endif
