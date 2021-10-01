/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 14:11:32 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/10/01 18:16:44 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	ft_get_map_line(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->map_line = malloc(sizeof(char *) * (data->nbr_line + 1));
	while (i < data->nbr_line)
	{
		j = 0;
		data->map_line[i] = malloc(sizeof(char) * (data->nbr_column + 1));
		while (j < data->nbr_column)
		{
			data->map_line[i][j] = data->map[i * (data->nbr_column + 1) + j];
			j++;
		}
		data->map_line[i][j] = '\0';
		i++;
	}
	data->map_line[i] = NULL;
}

static int	ft_check_is_close2(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (data->map[i] == '1')
			data->nbr_wall++;
		else if (data->map[i] == '\n')
		{
			if (data->map[i - 1] != '1' || data->map[i + 1] != '1')
				return (ft_error_map(data, "La map n'est pas fermee\n", 0));
		}
		i++;
	}
	return (NO_ERROR);
}

int	ft_check_is_close(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] != '\n' && data->map[i])
	{
		if (data->map[i] != '1')
			return (ft_error_map(data, "La map n'est pas fermee\n", 0));
		i++;
	}
	i = ft_strlen(data->map) - 1;
	while (data->map[i] != '\n' && data->map[i])
	{
		if (data->map[i] != '1')
			return (ft_error_map(data, "La map n'est pas fermee\n", 0));
		i--;
	}
	ft_get_map_line(data);
	if (ft_check_is_close2(data) == ERROR)
		return (ERROR);
	return (NO_ERROR);
}
