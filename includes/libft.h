/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:08:00 by arsciand          #+#    #+#             */
/*   Updated: 2021/04/23 15:47:00 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "log.h"
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>

# define BUFF_SIZE  4096
# define TRUE       1
# define FALSE      0

typedef struct      s_lst
{
    void            *content;
    size_t          content_size;
    struct s_lst    *next;
    struct s_lst    *prev;
}                   t_lst;

typedef struct      s_opt_set_db
{
    char            *current;
    char            *arg;
}                   t_opt_set_db;

typedef struct      s_opt
{
    uint64_t        all;
    char            *invalid;
    t_lst           *opt_set;
}                   t_opt;

void                free_opt(t_opt *opt);
char	            ft_isblank(char c);
t_lst	            *ft_lstappend(t_lst **alst, t_lst *new);
t_lst	            *ft_lstnew(const void *content, size_t content_size);
t_opt	            *ft_getopts(int argc, char **argv,
                        const char *allowed, const char **allowed_tab);
void	            *ft_memalloc(size_t size);
void	            *ft_memcpy(void *dst, const void *s, size_t n);
void	            *ft_memset(void *s, int c, size_t len);
char	            *ft_strchr(const char *s, int c);
int	                ft_strcmp(const char *s1, const char *s2);
char	            *ft_strcpy(char *dst, const char *s);
void	            ft_strdel(char **as);
char	            *ft_strdup(const char *s);
uint8_t	            ft_strequ(const char *s1, const char *s2);
size_t              ft_strlen(const char *s);
size_t	            ft_tablen(const char **array);

#endif
