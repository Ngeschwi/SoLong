/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 14:11:32 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/28 12:10:33 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	ft_get_map_line(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->map_line = malloc(sizeof(char *) * (map->line + 1));
	while (i < map->line)
	{
		j = 0;
		map->map_line[i] = malloc(sizeof(char) * (map->column) + 1);
		while (j < map->column)
		{
			map->map_line[i][j] = map->map[i * (map->column + 1) + j];
			j++;
		}
		map->map_line[i][j] = '\0';
		i++;
	}
}

static void	ft_get_map_column(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->map_column = malloc(sizeof(char *) * (map->column + 1));
	while (i < map->column)
	{
		j = 0;
		map->map_column[i] = malloc(sizeof(char) * (map->line + 1));
		while (j < map->line)
		{
			map->map_column[i][j] = map->map[i + j * (map->column + 1)];
			j++;
		}
		map->map_column[i][j] = '\0';
		i++;
	}
}

static int	ft_check_is_close2(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map_column[i][j])
	{
		if (map->map_column[i][j] != '1')
			return (ft_error_map(map, "La map n'est pas fermee\n", 1));
		j++;
	}
	j= 0;
	i = map->column - 1;
	while (map->map_column[i][j])
	{
		if (map->map_column[i][j] != '1')
			return (ft_error_map(map, "La map n'est pas fermee\n", 1));
		j++;
	}
	return (NO_ERROR);
}

int	ft_check_is_close(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i] != '\n' && map->map[i])
	{
		if (map->map[i] != '1')
			return (ft_error_map(map, "La map n'est pas fermee\n", 0));
		i++;
	}
	i = ft_strlen(map->map) - 1;
	while (map->map[i] != '\n' && map->map[i])
	{
		if (map->map[i] != '1')
			return (ft_error_map(map, "La map n'est pas fermee\n", 0));
		i--;
	}
	ft_get_map_line(map);
	ft_get_map_column(map);
	if (ft_check_is_close2(map) == ERROR)
		return (ERROR);
	return (NO_ERROR);
}
