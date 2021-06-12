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

static int	ft_get_info_map(t_map *map, t_parse *parse)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (map->map[i])
	{
		while (map->map[i] != '\n' && map->map[i])
		{
			map->column++;
			i++;
		}
		if (check != 0)
			if (check != map->column)
				return (ft_error_map(map, "La map n'est pas un rectangle\n"));
		check = map->column;
		map->column = 0;
		map->line++;
		i++;
	}
	map->column = check;
	return (NO_ERROR);
}

static int	ft_get_map(char **argv, t_map *map, t_parse *parse)
{
	char	*line;
	int		gnl;
	int		fd;

	fd = open("map/map1.ber", O_RDONLY);
	gnl = get_next_line(fd, &line);
	map->map = ft_strdup(line);
	if (ft_get_info_map(map, parse) == ERROR)
		return (ERROR);
	if (ft_other_carac(map, parse) == ERROR)
		return (ERROR);
	if (ft_check_is_close(map) == ERROR)
		return (ERROR);
	printf("%s\n", map->map);
	free(line);
	return (NO_ERROR);
}

int	ft_parse_map(int argc, char **argv, t_map *map)
{
	t_parse	parse;

	if (ft_get_map(argv, map, &parse) == ERROR)
		return (ERROR);
	return (NO_ERROR);
}
