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

static int	ft_check_carac_posi(t_data *data)
{
	if (data->exit_e > 1 || data->player_p > 1)
		return (ft_error_map(data, "Plus d'un caractere de position", 0));
	if (data->collect_c == 0 || data->exit_e == 0
		|| data->player_p == 0)
		return (ft_error_map(data, "Il manque un caractere de position\n", 0));
	if (data->nbr_line > 22)
		return (ft_error_map(data, "La map est trop large\n", 0));
	if (data->nbr_column > 42)
		return (ft_error_map(data, "La map est trop longue\n", 0));
	return (NO_ERROR);
}

static int	ft_other_carac(t_data *data)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (data->map[i])
	{
		if (data->map[i] == 'C')
			data->collect_c++;
		else if (data->map[i] == 'P')
		{
			data->player_p++;
			data->coord[X] = i - ((data->nbr_column + 1) * check);
			data->coord[Y] = check;
		}
		else if (data->map[i] == 'E')
			data->exit_e++;
		else if (data->map[i] != '1' && data->map[i] != '0'
			&& data->map[i] != '\n')
			return (ft_error_map(data, "Mauvais caractere dans la map\n", 0));
		i++;
		if (data->map[i] == '\n')
			check++;
	}
	return (NO_ERROR);
}

static int	ft_get_info_map(t_data *data)
{
	int	i;
	int	check;
	int	len;

	i = 0;
	check = 0;
	len = ft_strlen(data->map);
	while (i < len)
	{
		while (data->map[i] != '\n' && data->map[i])
		{
			data->nbr_column++;
			i++;
		}
		if (check != 0 && check != data->nbr_column)
			return (ft_error_map(data, "La map n'est pas un rectangle\n", 0));
		check = data->nbr_column;
		data->nbr_column = 0;
		data->nbr_line++;
		i++;
	}
	data->nbr_column = check;
	return (NO_ERROR);
}

static int	ft_get_map(t_data *data)
{
	char	*line;
	int		gnl;
	int		fd;

	fd = open(data->path_map, O_RDONLY);
	gnl = get_next_line(fd, &line);
	data->map = ft_strdup(line);
	free(line);
	if (ft_strlen(data->map) == 0)
		return (ft_error_map(data, "La map est vide\n", 0));
	if (ft_get_info_map(data) == ERROR)
		return (ERROR);
	if (ft_other_carac(data) == ERROR)
		return (ERROR);
	if (ft_check_carac_posi(data) == ERROR)
		return (ERROR);
	if (ft_check_is_close(data) == ERROR)
		return (ERROR);
	return (NO_ERROR);
}

int	ft_parse_map(t_data *data)
{
	if (ft_get_map(data) == ERROR)
		return (ERROR);
	data->img_c = malloc(sizeof(void*) * data->collect_c);
	data->img_w = malloc(sizeof(void*) * data->nbr_wall);
	return (NO_ERROR);
}
