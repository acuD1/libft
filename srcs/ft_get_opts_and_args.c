/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_opts_and_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:10:28 by arsciand          #+#    #+#             */
/*   Updated: 2021/04/30 15:30:31 by arsciand         ###   ########.fr       */
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
**
**
*/

static void          usage(void)
{
    fprintf(stderr, "%s%s%s%s%s%s",
        "\nUsage: ft_get_ops_args(): ",
        "struct s_opts_conf must be properly configured.\n\n",
        "typedef struct\t\ts_opts_conf\n{\n",
        "\tconst char\t*allowed_opt;\t\t('-')\t\t| Minimal configuration !\n",
        "\tconst char\t*allowed_opt_arg;\t('-' + arg)\n"
        "\tconst char\t**allowed_opt_tab;\t('--')\n",
        "\tconst char\t**allowed_opt_tab_arg;\t('--' + arg)\n}\t\t\tt_opts_conf;\n\n");
}

void                debug_opts_args(t_opts_args *opts_args)
{
    if (!opts_args)
    {
        printf("WARNING : opt no allocated\n");
        return ;
    }
    printf("%s\n\n%s\n\t\t%s\n%s\n",
        ">> OPTS_ARGS DEBUG",
        "=>  invalid: ", opts_args->invalid, "=>  args:");
    if (opts_args->args && ft_tablen((const char **)opts_args->args))
    {
        for (size_t i = 0; opts_args->args[i]; i++)
            printf("\t\t- [%zu] | %s\n", i, opts_args->args[i]);
    }
    else
        printf("\t\t(null)\n");
    printf("=>  opt_set:\n");
    if (opts_args->opt_set)
    {
        t_lst   *tmp    = opts_args->opt_set;
        size_t  i       = 0;

        while (tmp)
        {
            printf(
                "\t\t- [%zu] | current -> %s\n\t\t      | arg \t-> %s\n",
                i++, ((t_opt_set_db *)tmp->content)->current,
                ((t_opt_set_db *)tmp->content)->arg);
            tmp = tmp->next;
        }
    }
    else
        printf("\t\t(null)\n");
}

char                *get_opt_set_arg(t_lst **alst_opt_set, char *to_find)
{
    t_lst   *opt_set    = *alst_opt_set;
    t_lst   *tmp        = NULL;
    char    *arg        = NULL;

    if (!opt_set)
        return (NULL);
    if (!(tmp = ft_lstfind(opt_set,
        ((t_opt_set_db *)opt_set->content)->current,
        to_find, (int (*)(void*, void*))ft_strequ)))
        return (NULL);
    if (!(arg = ((t_opt_set_db *)tmp->content)->arg))
        return (NULL);
    return (arg);
}

void                free_opts_args(t_opts_args *opts_args)
{
    if (!opts_args)
        return ;
    while (opts_args->opt_set)
    {
        t_lst   *tmp = NULL;

        ft_strdel(&((t_opt_set_db*)(opts_args->opt_set->content))->current);
        ft_strdel(&((t_opt_set_db*)(opts_args->opt_set->content))->arg);
        free(opts_args->opt_set->content);
        tmp = opts_args->opt_set;
        opts_args->opt_set = opts_args->opt_set->next;
        free(tmp);
    }
    ft_strdel(&opts_args->invalid);
    ft_tabdel(&opts_args->args);
    free(opts_args);
    opts_args = NULL;
}

static t_opt_set_db *fetch_set_opt(
                        t_opt_set_db *opt_set_db, char *current, char *arg)
{
    if (!(opt_set_db->current = ft_strdup(current)))
        return (NULL);
    if (!arg)
        opt_set_db->arg = NULL;
    else if (!(opt_set_db->arg = ft_strdup(arg)))
        return (NULL);
    return (opt_set_db);
}

t_opts_args         *ft_get_opts_and_args(
                        int argc, char **argv, t_opts_conf *opts_conf)
{
    t_opts_args *opts_args              = NULL;
    size_t      n_arg                   = 0;
    char        *args[BUFF_SIZE + 1];

    if (!opts_conf || !opts_conf->allowed_opt)
    {
        usage();
        return (NULL);
    }
    ft_memset(args, 0, BUFF_SIZE);
    if (!(opts_args = ft_memalloc(sizeof(t_opts_args))))
        return (NULL);
    for (size_t i = 1; i < (size_t)argc; i++)
    {
        t_opt_set_db    opt_set_db;
        size_t          j                           = 1;
        size_t          z                           = 0;
        char            buffer[BUFF_SIZE];
        uint8_t         allowed_found               = FALSE;
        uint8_t         allowed_opt_tab_arg_found   = FALSE;


        ft_memset(&opt_set_db, 0, sizeof(t_opt_set_db));
        ft_memset(buffer, 0, sizeof(char));

        /* '--' handling */
        if (argv[i][0] == '-' && argv[i][1] == '-' && !argv[i][2])
        {
            i++;
            while (argv[i])
                if (!(args[n_arg++] = ft_strdup(argv[i++])))
                    return (NULL);
            break;
        }

        /* Default '-' 'option' patern */
        if ((argv[i][0] == '-' && argv[i][1] != '-')
            || (!opts_conf->allowed_opt_tab
            && argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2]))
        {
            while (argv[i][j])
            {
                if (!ft_strchr(opts_conf->allowed_opt, argv[i][j]))
                {
                    opts_args->all = (uint64_t)argv[i][j] | 1ULL << 63;
                    for (size_t l = 0; args[l]; l++)
                        ft_strdel(&args[l]);
                    return (opts_args);
                }
                if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
                    opts_args->all = opts_args->all | (1ULL << (argv[i][j] - 'a'));
                if (argv[i][j] >= 'A' && argv[i][j] <= 'Z')
                    opts_args->all = opts_args->all | (1ULL << ((argv[i][j] - 'A') + 26));
                if (argv[i][j] >= '0' && argv[i][j] <= '9')
                    opts_args->all = opts_args->all | (1ULL << ((argv[i][j] - '0') + 52));
                j++;
            }
            if (argv[i + 1] && argv[i + 1][0] != '-')
            {
                j--;
                if (opts_conf->allowed_opt_arg && ft_strchr(opts_conf->allowed_opt_arg, argv[i][j]))
                {
                    buffer[0] = argv[i][j];
                    buffer[1] = '\0';
                    if (!(ft_lstappend(&opts_args->opt_set,
                        ft_lstnew(
                            fetch_set_opt(&opt_set_db, buffer, argv[i + 1]),
                                sizeof(t_opt_set_db)))))
                        return (NULL);
                }
                else
                    if (!(args[n_arg++] = ft_strdup(argv[i + 1])))
                        return (NULL);
                i++;
            }
        }

        /* '--' 'option' patern */
        else if (argv[i][0] == '-' && argv[i][1] == '-' && opts_conf->allowed_opt_tab)
        {
            j = 2;
            while (argv[i][j])
                buffer[z++] = argv[i][j++];
            buffer[z] = '\0';
            for (size_t y = 0; opts_conf->allowed_opt_tab[y]; y++)
            {

                /* search for allowed string options (--) */
                if (ft_strequ(buffer, opts_conf->allowed_opt_tab[y]))
                {
                    /* search if arg requiered */
                    if (opts_conf->allowed_opt_tab_arg)
                        for (size_t w = 0; opts_conf->allowed_opt_tab_arg[w]; w++)
                            if (ft_strequ(opts_conf->allowed_opt_tab_arg[y], buffer))
                                allowed_opt_tab_arg_found = TRUE;

                    if (!(ft_lstappend(&opts_args->opt_set,
                        ft_lstnew(
                            fetch_set_opt(&opt_set_db, buffer,
                                (argv[i + 1] && argv[i + 1][0] != '-'
                                && allowed_opt_tab_arg_found == TRUE)
                                ? argv[i + 1] : NULL), sizeof(t_opt_set_db)))))
                        return (NULL);

                    if (argv[i + 1] && argv[i + 1][0] != '-'
                        && allowed_opt_tab_arg_found == TRUE)
                        i++;
                    allowed_found = TRUE;
                    break ;
                }
            }
            if (allowed_found == FALSE)
            {
                opts_args->all =  1ULL << 63;
                opts_args->invalid = ft_strdup(buffer);
                return (opts_args);
            }
        }
        else
            if (!(args[n_arg++] = ft_strdup(argv[i])))
                return (NULL);
    }
    if (!(opts_args->args = ft_tabcopy(opts_args->args, (const char **)args)))
        return (NULL);
    for (size_t l = 0; args[l]; l++)
        ft_strdel(&args[l]);
    return (opts_args);
}
