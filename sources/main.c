/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:55:56 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/28 12:20:01 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "get_next_line.h"

static void	ft_init_parse(t_parse *parse)
{
	parse->collect_c = 0;
	parse->exit_e = 0;
	parse->player_p = 0;
}

static void	ft_init_map(t_map *map)
{
	map->map = NULL;
	map->map_column = NULL;
	map->map_line = NULL;
	map->line = 0;
	map->column = 0;
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_parse parse;
	void	*mlx;

	ft_init_map(&map);
	ft_init_parse(&parse);
	if (ft_parse_map(argc, argv, &map, &parse) == ERROR)
		return (ERROR);
	return (0);
}
