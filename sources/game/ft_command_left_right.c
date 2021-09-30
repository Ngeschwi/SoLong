/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_left_right.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:32:36 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/09/30 22:09:47 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	ft_move_player_lr(t_data *data, int where, int i)
{
	data->map_line[data->coord[Y]][data->coord[X]] = '0';
	if (where == LEFT)
		i++;
	else
		i--;
	data->map_line[data->coord[Y]][i] = 'P';
	data->coord[X] = i;
	ft_create_map(data);
}

static void	ft_exit(t_data *data, int where, int i)
{
	if (data->collect_c != 0)
		ft_move_player_lr(data, where, i);
	else
		printf("sortie\n");
}

int	ft_left_right(t_data *data, int where)
{
	int	i;

	i = data->coord[X];
	data->count_move++;
	while (data->map_line[data->coord[Y]][i] != '1')
	{
		if (data->map_line[data->coord[Y]][i] == 'C')
		{
			data->collect_c--;
			data->map_line[data->coord[Y]][i] = '0';
		}
		else if (data->map_line[data->coord[Y]][i] == 'E')
		{
			ft_exit(data, where, i);
			return (0);
		}
		if (where == LEFT)
			i--;
		else
			i++;
	}
	ft_move_player_lr(data, where, i);
	return (0);
}
