/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 15:08:00 by arsciand          #+#    #+#             */
/*   Updated: 2021/11/18 16:32:14 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# pragma clang diagnostic ignored "-Wreserved-id-macro"
// # pragma clang diagnostic ignored "-Wreserved-identifier"

# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define _PADDING(x)    _PADDING[x]
# define POSITION(x)    x
# define BUFF_SIZE      4096
# define TRUE           1
# define FALSE          0
# define SUCCESS        0
# define FAILURE        2

typedef struct          s_lst
{
    struct s_lst        *next;
    struct s_lst        *prev;
    size_t              content_size;
    void                *content;
}                       t_lst;

typedef struct          s_opt_set_db
{
    char                *current;
    char                *arg;
    char                _PADDING(4);
    int                 argc;
}                       t_opt_set_db;

typedef struct          s_args_db
{
    char                *arg;
    char                _PADDING(4);
    int                 argc;
}                       t_args_db;

typedef struct          s_opts_args
{
    t_lst               *opt_set;
    t_lst               *args;
    uint64_t            all;
    char                *invalid;
    char                _PADDING(4);
    int                 argc;
}                       t_opts_args;

typedef struct          s_opts_conf
{
    const char          *allowed_opt;
    const char          *allowed_opt_arg;
    const char          *allowed_opt_assign;
    const char          **allowed_opt_tab;
    const char          **allowed_opt_tab_arg;
    const char          **allowed_opt_assign_tab;
}                       t_opts_conf;

void                    free_opts_args(t_opts_args *opts_args);
int                     ft_atoi(const char *s);
long                    ft_atol(const char *s);
uint8_t                 ft_isdigit(char c);
uint8_t                 ft_isnum(char *str);
char                    *ft_itoa(int32_t n);
t_lst                   *ft_lstappend(t_lst **alst, t_lst *new);
void                    *ft_lstdel(t_lst **alst, void (*del)(void *));
void                    ft_lstdelone(t_lst **alst, void (*del)(void *));
t_lst                   *ft_lstfind(
                            t_lst *lst, void *to_find,
                            int (*f)(void *, void *));
void                    ft_lstiter(t_lst *lst, void (*f)(void *content));
uint8_t                 ft_lstiter_ctx(
                            t_lst *lst, void *context,
                            uint8_t (*f)(void *content, void *context));
size_t                  ft_lstlen(t_lst *lst);
t_lst                   *ft_lstnew(const void *content, size_t content_size);
uint8_t                 ft_get_opts_args(
                            t_opts_args *opts_args, t_opts_conf *opts_conf,
                            int argc, char **argv);
void                    *ft_memalloc(size_t size);
void                    *ft_memcpy(void *dst, const void *s, size_t n);
void                    ft_memdel(void **ap);
void                    *ft_memset(void *s, int c, size_t len);
char                    *ft_strchr(const char *s, int c);
int                     ft_strcmp(const char *s1, const char *s2);
char                    *ft_strcpy(char *dst, const char *s);
void                    ft_strdel(char **as);
char                    *ft_strdup(const char *s);
uint8_t                 ft_strequ(const char *s1, const char *s2);
size_t                  ft_strlen(const char *s);
char                    **ft_tabcopy(
                            char **tab_dest, const char * const *tab_copy);
void                    ft_tabdel(char ***array);
size_t                  ft_tablen(const char * const *array);
void                    debug_opts_args(t_opts_args *opt);
t_args_db               *get_arg(t_lst **alst_args, int argc);
t_opt_set_db            *get_opt_set_db(t_lst **alst_opt_set, char *to_find);

#endif
