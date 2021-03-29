/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:04:25 by arsciand          #+#    #+#             */
/*   Updated: 2021/03/12 15:26:55 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"
#include <stdio.h>
#include <unistd.h>

void log_msg(LogLevel_T level ,  const unsigned char* sLogMessage) {
    const char *level_colors[] = {
        "\x1b[36m",
        "\x1b[33m",
        "\x1b[32m",
        "\x1b[35m",
        "\x1b[31m"
    };

    dprintf(STDOUT_FILENO, "%s%s\n", level_colors[level], sLogMessage);
}

