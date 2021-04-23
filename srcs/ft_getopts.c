/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:10:28 by arsciand          #+#    #+#             */
/*   Updated: 2021/04/23 15:52:02 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	+--------+---------+---------+------------------------------------------+
**	| a - z  |  A - Z  |  0 - 9  |             unallowed option             |
**	+--------+---------+---------+------------------------------------------+
**	| 0 - 25 | 26 - 51 | 52 - 61 | 63. return % 128 to get unallowed option |
**	+--------+---------+---------+------------------------------------------+
**	"-c" option = [00000000 00000100]
**	use (option & (1ULL << 3)) to catch
*/

void    free_opt(t_opt *opt)
{
    while (opt->opt_set)
    {
        t_lst   *tmp = NULL;

        ft_strdel(&((t_opt_set_db*)(opt->opt_set->content))->current);
        ft_strdel(&((t_opt_set_db*)(opt->opt_set->content))->arg);
        free(opt->opt_set->content);
        tmp = opt->opt_set;
        opt->opt_set = opt->opt_set->next;
        free(tmp);
    }
    ft_strdel(&opt->invalid);
    free(opt);
}

static t_opt_set_db
        *fetch_set_opt(t_opt_set_db *opt_set_db, char *current, char *arg)
{
    if (!(opt_set_db->current = ft_strdup(current)))
        return (NULL);
    if (!arg)
        opt_set_db->arg = NULL;
    else if (!(opt_set_db->arg = ft_strdup(arg)))
    {
        return (NULL);
    }
    return (opt_set_db);
}

t_opt   *ft_getopts(
            int argc, char **argv, const char *allowed, const char **allowed_ar)
{
    t_opt   *opt = NULL;

    if (!(opt = ft_memalloc(sizeof(t_opt))))
        return (NULL);
    for (size_t i = 1; i < (size_t)argc; ++i)
    {
        uint8_t         allowed_found       = FALSE;
        size_t          j                   = 1;
        size_t          z                   = 0;
        char            buffer[BUFF_SIZE];
        t_opt_set_db    opt_set_db;

        ft_memset(&opt_set_db, 0, sizeof(t_opt_set_db));
        ft_memset(buffer, 0, sizeof(char));
        if (argv[i][0] != '-'
            || (argv[i][0] == '-' && !argv[i][1])
            || (argv[i][0] == '-' && argv[i][1] == '-' && !argv[i][2]))
            break ;

        /* Default '-' 'option' patern */
        if (argv[i][0] == '-' && argv[i][1] != '-')
        {
            while (argv[i][j])
            {
                if (!ft_strchr(allowed, argv[i][j]))
                {
                    opt->all = (uint64_t)argv[i][j] | 1ULL << 63;
                    opt->opt_set = NULL;
                    return (opt);
                }
                if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
                    opt->all = opt->all | (1ULL << (argv[i][j] - 'a'));
                if (argv[i][j] >= 'A' && argv[i][j] <= 'Z')
                    opt->all = opt->all | (1ULL << ((argv[i][j] - 'A') + 26));
                if (argv[i][j] >= '0' && argv[i][j] <= '9')
                    opt->all = opt->all | (1ULL << ((argv[i][j] - '0') + 52));
                j++;
            }
            if (argv[i + 1] && argv[i + 1][0] != '-')
            {
                buffer[0] = argv[i][--j];
                buffer[1] = '\0';
                if (!(ft_lstappend(&opt->opt_set,
                    ft_lstnew(
                        fetch_set_opt(&opt_set_db, buffer, argv[i + 1]),
                            sizeof(t_opt_set_db)))))
                    return (NULL);
                i++;
            }
        }

        /* '--' 'option' patern */
        else if (argv[i][0] == '-' && argv[i][1] == '-')
        {
            j = 2;
            while (argv[i][j]) {
                buffer[z++] = argv[i][j++];
            }
            buffer[z] = '\0';
            for (size_t y = 0; allowed_ar[y]; y++)
            {
                if (ft_strequ(buffer, allowed_ar[y]))
                {
                    if (!(ft_lstappend(&opt->opt_set,
                        ft_lstnew(
                            fetch_set_opt(&opt_set_db, buffer,
                                (argv[i + 1] && argv[i + 1][0] != '-')
                                ? argv[i + 1] : NULL), sizeof(t_opt_set_db)))))
                    {
                        return (NULL);
                    }
                    if (argv[i + 1] && argv[i + 1][0] != '-')
                        i++;
                    allowed_found = TRUE;
                    break ;
                }
            }
            if (allowed_found == FALSE)
            {
                opt->all =  1ULL << 63;
                opt->invalid = ft_strdup(buffer);
                opt->opt_set = NULL;
                return (opt);
            }
        }
    }
    return (opt);
}
