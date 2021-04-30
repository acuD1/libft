/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:08:00 by arsciand          #+#    #+#             */
/*   Updated: 2021/04/30 15:20:39 by arsciand         ###   ########.fr       */
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
    struct s_lst    *next;
    struct s_lst    *prev;
    size_t          content_size;
    void            *content;
}                   t_lst;

typedef struct      s_opt_set_db
{
    char            *current;
    char            *arg;
}                   t_opt_set_db;

typedef struct      s_opts_args
{
    t_lst           *opt_set;
    uint64_t        all;
    char            **args;
    char            *invalid;
}                   t_opts_args;

typedef struct      s_opts_conf
{
    const char      *allowed_opt;
    const char      *allowed_opt_arg;
    const char      **allowed_opt_tab;
    const char      **allowed_opt_tab_arg;
}                   t_opts_conf;


void                free_opts_args(t_opts_args *opts_args);
char	            ft_isblank(char c);
t_lst	            *ft_lstappend(t_lst **alst, t_lst *new);
t_lst	            *ft_lstfind(
                        t_lst *lst, void *to_find, void *content,
                        int (*f)(void *, void *));
size_t              ft_lstlen(t_lst *lst);
t_lst	            *ft_lstnew(const void *content, size_t content_size);
t_opts_args	        *ft_get_opts_and_args(
                        int argc, char **argv, t_opts_conf *opts_conf);
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
char                **ft_tabcopy(char **tab_dest, const char **tab_copy);
void                ft_tabdel(char ***array);
size_t	            ft_tablen(const char **array);
void                debug_opts_args(t_opts_args *opt);
char                *get_opt_set_arg(t_lst **alst_opt_set, char *to_find);

#endif
