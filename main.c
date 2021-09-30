/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:55:56 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/09/30 22:13:17 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	ft_init_map_struct(t_data *data)
{
	data->path_c = "img/collect.xpm";
	data->path_w = "img/wall.xpm";
	data->path_e = "img/exit.xpm";
	data->path_p = "img/player.xpm";
	data->img_p = NULL;
	data->collect_c = 0;
	data->exit_e = 0;
	data->player_p = 0;
	data->coord[X] = 0;
	data->coord[Y] = 0;
	data->map = NULL;
	data->map_line = NULL;
	data->nbr_line = 0;
	data->nbr_column = 0;
	data->count_move = 0;
}

int	main(void)
{
	t_data	data;

	ft_init_map_struct(&data);
	if (ft_parse_map(&data) == ERROR)
		return (ERROR);
	data.height = data.nbr_line * 60;
	data.lenght = data.nbr_column * 60;
	printf("Bon jeu\n");
	printf("Voici votre nombre de deplacements : %d\n", data.count_move);
	if (ft_init_map(&data) == ERROR)
		return (ERROR);
	return (0);
}
