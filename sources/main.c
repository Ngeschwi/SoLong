/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:55:56 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/07/04 10:57:30 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	ft_init_parse(t_parse *parse)
{
	parse->collect_c = 0;
	parse->exit_e = 0;
	parse->player_p = 0;
}

static void	ft_init_map_struct(t_map *map)
{
	map->map = NULL;
	map->map_column = NULL;
	map->map_line = NULL;
	map->line = 0;
	map->column = 0;
}

int	main(void)
{
	t_map	map;
	t_parse parse;
	t_data	mlx;

	ft_init_map_struct(&map);
	ft_init_parse(&parse);
	if (ft_parse_map(&map, &parse) == ERROR)
		return (ERROR);
	ft_init_map(&mlx, &map);
	return (0);
}
