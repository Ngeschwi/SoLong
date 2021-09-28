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

static int	ft_check_carac_posi(t_parse *parse, t_map *map)
{
	if (parse->collect_c > 1 || parse->exit_e > 1
		|| parse->player_p > 1)
		return (ft_error_map(map, "Plus d'un caractere de position", 0));
	if (parse->collect_c == 0 || parse->exit_e == 0
		|| parse->player_p == 0)
		return (ft_error_map(map, "Il manque un caractere de position\n", 0));
	return (NO_ERROR);
}

static int	ft_other_carac(t_map *map, t_parse *parse)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (map->map[i] == 'C')
			parse->collect_c++;
		else if (map->map[i] == 'P')
			parse->player_p++;
		else if (map->map[i] == 'E')
			parse->exit_e++;
		else if (map->map[i] != '1' && map->map[i] != '0'
			&& map->map[i] != '\n')
			return (ft_error_map(map, "Mauvais caractere dans la map\n", 0));
		i++;
	}
	if (ft_check_carac_posi(parse, map) == ERROR)
		return (ERROR);
	return (NO_ERROR);
}

static int	ft_get_info_map(t_map *map)
{
	int	i;
	int	check;
	int	len;

	i = 0;
	check = 0;
	len = ft_strlen(map->map);
	while (i < len)
	{
		while (map->map[i] != '\n' && map->map[i])
		{
			map->nbr_column++;
			i++;
		}
		if (check != 0 && check != map->nbr_column)
			return (ft_error_map(map, "La map n'est pas un rectangle\n", 0));
		check = map->nbr_column;
		map->nbr_column = 0;
		map->nbr_line++;
		i++;
	}
	map->nbr_column = check;
	return (NO_ERROR);
}

static int	ft_get_map(t_map *map, t_parse *parse)
{
	char	*line;
	int		gnl;
	int		fd;

	fd = open("map/map1.ber", O_RDONLY);
	gnl = get_next_line(fd, &line);
	map->map = ft_strdup(line);
	free(line);
	if (ft_get_info_map(map) == ERROR)
		return (ERROR);
	if (ft_other_carac(map, parse) == ERROR)
		return (ERROR);
	if (ft_check_is_close(map) == ERROR)
		return (ERROR);
	printf("%s\n", map->map);
	printf("line : %d et colunm : %d\n", map->nbr_line, map->nbr_column);
	return (NO_ERROR);
}

int	ft_parse_map(t_map *map, t_parse *parse)
{
	if (ft_get_map(map, parse) == ERROR)
		return (ERROR);
	return (NO_ERROR);
}
