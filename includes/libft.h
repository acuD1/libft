/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:08:00 by arsciand          #+#    #+#             */
/*   Updated: 2021/04/09 16:41:14 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "log.h"
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>

void	    *ft_memset(void *s, int c, size_t len);
uint64_t	ft_getopts(int argc, char **argv, char *allowed);
char	    *ft_strchr(const char *s, int c);
size_t      ft_strlen(const char *s);

#endif
