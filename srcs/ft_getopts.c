/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 14:10:28 by arsciand          #+#    #+#             */
/*   Updated: 2021/04/09 16:06:03 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	return an unsigned long long (64 bits) containing all the options.
**	Specify allowed options like this : "Rlart"
**	+--------+---------+---------+------------------------------------------+
**	| a - z  |  A - Z  |  0 - 9  |             unallowed option             |
**	+--------+---------+---------+------------------------------------------+
**	| 0 - 25 | 26 - 51 | 52 - 61 | 63. return % 128 to get unallowed option |
**	+--------+---------+---------+------------------------------------------+
**	"-c" option = [00000000 00000100]
**	use (option & (1ULL << 3)) to catch
*/

uint64_t	ft_getopts(int argc, char **argv, char *allowed)
{
	uint64_t	ret;
	size_t		i;
	size_t		j;

	j = 0;
	ret = 0;
	while (++j < (size_t)argc && argv[j][0] == '-')
	{
		i = 0;
		while (argv[j][++i])
		{
			if (argv[j][0] != '-' || (argv[j][0] == '-'
						&& argv[j][1] == '-' && argv[j][2] == 0))
				return (ret);
			if (!ft_strchr(allowed, argv[j][i]))
				return ((uint64_t)argv[j][i] | 1ULL << 63);
			if (argv[j][i] >= 'a' && argv[j][i] <= 'z')
				ret = ret | (1ULL << (argv[j][i] - 'a'));
			if (argv[j][i] >= 'A' && argv[j][i] <= 'Z')
				ret = ret | (1ULL << ((argv[j][i] - 'A') + 26));
			if (argv[j][i] >= '0' && argv[j][i] <= '9')
				ret = ret | (1ULL << ((argv[j][i] - '0') + 52));
		}
	}
	return (ret);
}
