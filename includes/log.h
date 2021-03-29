/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 14:37:54 by arsciand          #+#    #+#             */
/*   Updated: 2021/03/12 15:16:26 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

typedef enum {
    DEBUG = 0,
    WARN,
    INFO,
    ERROR ,
    FATAL
} LogLevel_T ;

void log_msg(LogLevel_T level ,  const unsigned char* sLogMessage);

# define LOG_DEBUG(msg) log_msg(DEBUG, (const unsigned char*)(msg))
# define LOG_WARN(msg)  log_msg(WARN, (const unsigned char*)(msg))
# define LOG_INFO(msg)  log_msg(INFO, (const unsigned char*)(msg))
# define LOG_ERROR(msg) log_msg(ERROR, (const unsigned char*)(msg))
# define LOG_FATAL(msg) log_msg(FATAL, (const unsigned char*)(msg))

#endif
