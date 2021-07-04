/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:08:21 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/07/04 11:39:38 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_error_map(t_map *map, char *str, int	check)
{
	ft_putstr("Error\n");
	ft_putstr(str);
	free(map->map);
	if (check == 1)
	{
		ft_free_map(map->map_column);
		ft_free_map(map->map_line);
	}
	return (ERROR);
}

int	ft_error_game(t_map *map, char *str)
{
	ft_putstr("Error\n");
	ft_putstr(str);
	free(map->map);
	ft_free_map(map->map_column);
	ft_free_map(map->map_line);
	return (ERROR);
}