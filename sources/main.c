/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:55:56 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/12 11:58:22 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "get_next_line.h"

static void	ft_init_map(t_map *map)
{
	map->map = NULL;
	map->line = 0;
	map->column = 0;
}

int	main(int argc, char **argv)
{
	t_map	map;
	void	*mlx;

	ft_init_map(&map);
	if (ft_parse_map(argc, argv, &map) == ERROR)
		return (ERROR);
	return (0);
}
