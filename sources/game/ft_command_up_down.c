/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_up_down.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:31:25 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/10/04 15:37:45 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	ft_move_player_ud(t_data *data, int where, int i)
{
	data->map_line[data->coord[Y]][data->coord[X]] = '0';
	if (where == UP)
		i++;
	else
		i--;
	data->map_line[i][data->coord[X]] = 'P';
	data->coord[Y] = i;
	ft_create_bg(data, 0x00096A09);
	ft_create_map(data, 0);
	printf("Nombre de deplacements : %d\n", data->count_move);
}

static void	ft_exit(t_data *data, int where, int i)
{
	ft_move_player_ud(data, where, i);
	if (data->collect_c == 0)
	{
		printf("Bravo vous avez reussi !\n");
		ft_end(data);
	}
}

int	ft_up_down(t_data *data, int where)
{
	int	i;

	i = data->coord[Y];
	data->count_move++;
	while (data->map_line[i][data->coord[X]] != '1')
	{
		if (data->map_line[i][data->coord[X]] == 'C')
		{
			data->collect_c--;
			data->map_line[i][data->coord[X]] = '0';
		}
		else if (data->map_line[i][data->coord[X]] == 'E')
		{
			ft_exit(data, where, i);
			return (END);
		}
		if (where == UP)
			i--;
		else
			i++;
	}
	ft_move_player_ud(data, where, i);
	return (0);
}
