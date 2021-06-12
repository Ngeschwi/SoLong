/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 14:11:32 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/12 14:26:03 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	ft_check_carac_posi(t_parse *parse, t_map *map)
{
	if (parse->collect_c > 1 || parse->exit_e > 1
		|| parse->player_p > 1)
		return (ft_error_map(map, "Plus d'un caractere de position"));
	if (parse->collect_c == 0 || parse->exit_e == 0
		|| parse->player_p == 0)
		return (ft_error_map(map, "Il manque au moins un caractere de position\n"));
	return (NO_ERROR);
}

int	ft_other_carac(t_map *map, t_parse *parse)
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
		{
			if (map->map[i] == ' ')
				return (ft_error_map(map, "La map n'est pas un rectangle\n"));
			else
				return (ft_error_map(map, "Mauvais caractere dans la map\n"));
		}
		i++;
	}
	if (ft_check_carac_posi(parse, map) == ERROR)
		return (ERROR);
	return (NO_ERROR);
}

int	ft_check_is_close(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i] != '\n' && map->map[i])
	{
		if (map->map[i] != '1')
			return (ft_error_map(map, "La map n'est pas fermee\n"));
		i++;
	}
	i = ft_strlen(map->map) - 1;
	while (map->map[i] != '\n' && map->map[i])
	{
		if (map->map[i] != '1')
			return (ft_error_map(map, "La map n'est pas fermee\n"));
		i--;
	}
	return (NO_ERROR);
}
