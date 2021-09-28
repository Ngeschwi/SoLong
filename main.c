/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:55:56 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/09/28 16:00:13 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	ft_init_data_struct(t_data *mlx)
{
	mlx->path_bg = "img/bg.xpm";
}

static void	ft_init_parse_struct(t_parse *parse)
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
	map->nbr_line = 0;
	map->nbr_column = 0;
}

int	main(void)
{
	t_map	map;
	t_parse parse;
	t_data	mlx;

	ft_init_map_struct(&map);
	ft_init_parse_struct(&parse);
	ft_init_data_struct(&mlx);
	if (ft_parse_map(&map, &parse) == ERROR)
		return (ERROR);
	if (ft_init_map(&mlx, &map) == ERROR)
		return (ERROR);
	return (0);
}
