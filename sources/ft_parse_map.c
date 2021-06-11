/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:52:35 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/11 14:52:35 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "get_next_line.h"

static void	ft_get_info_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		while (map->map[i] != '\n' && map->map[i])
		{
			map->column++;
			i++;
		}
		map->line++;
		i++;
	}
}

static int	ft_get_map(char **argv, t_map *map)
{
	char	*line;
	int		gnl;
	int		fd;

	fd = open("map/map1.ber", O_RDONLY);
	gnl = get_next_line(fd, &line);
	map->map = ft_strdup(line);
	ft_get_info_map(map);
	printf("%s", map->map);
	free(line);
	return (NO_ERROR);
}

int	ft_parse_map(int argc, char **argv, t_map *map)
{
	t_parse	parse;

	if (ft_get_map(argv, map) == ERROR)
		return (ERROR);
	return (NO_ERROR);
}
