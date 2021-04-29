/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:37:54 by arsciand          #+#    #+#             */
/*   Updated: 2021/04/26 17:26:14 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

# define LOG_DEBUG(msg)     log_msg(DEBUG,  (const char *)(msg))
# define LOG_WARN(msg)      log_msg(WARN,   (const char *)(msg))
# define LOG_INFO(msg)      log_msg(INFO,   (const char *)(msg))
# define LOG_ERROR(msg)     log_msg(ERROR,  (const char *)(msg))
# define LOG_FATAL(msg)     log_msg(FATAL,  (const char *)(msg))
# define LOG_RESET(msg)     log_msg(RESET,  (const char *)(msg))

typedef enum {
    DEBUG = 0,
    WARN,
    INFO,
    ERROR,
    FATAL,
    RESET
} e_loglevel;

void                        log_msg(e_loglevel level,  const char *s);

#endif
