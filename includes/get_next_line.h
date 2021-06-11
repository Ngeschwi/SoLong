/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@stutent.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:14:05 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/04/06 15:14:05 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/stat.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# define NO_NL -1

int			get_next_line(int fd, char **line);

#endif
