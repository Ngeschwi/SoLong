/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@stutent.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:00:45 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/09 16:00:45 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "get_next_line.h"

static int  ft_get_map(char **argv)
{
    char    *line = NULL;
    int     gnl;
    int     fd;

    fd = open("map/map1.ber", O_RDONLY);
    gnl = get_next_line(fd, &line);
    while (gnl > 0)
    {
        printf("%s\n", line);
        free(line);
        gnl = get_next_line(fd, &line);
    }
    printf("%s\n", line);
    free(line);
    return (NO_ERROR);
}

int ft_parse_map(int argc, char **argv)
{
    t_parse parse;

    if (ft_get_map(argv) == ERROR)
        return (ERROR);
    return (NO_ERROR);
}
