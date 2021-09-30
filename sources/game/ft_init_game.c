/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 10:53:13 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/09/30 22:00:31 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_check_key(int key, t_data *data)
{
	if (key == 13)
		ft_up_down(data, UP);
	else if (key == 1)
		ft_up_down(data, DOWN);
	else if (key == 0)
		ft_left_right(data, LEFT);
	else if (key == 2)
		ft_left_right(data, RIGHT);
	else if (key == 53)
	{
		mlx_clear_window(data->mlx, data->mlx_win);
		mlx_destroy_window(data->mlx, data->mlx_win);
		return (END);
	}
	else
		return (1);
	printf("Nombre de mouvements : %d\n", data->count_move);
	printf("%s\n", data->map_line[0]);
	printf("%s\n", data->map_line[1]);
	printf("%s\n", data->map_line[2]);
	printf("%s\n", data->map_line[3]);
	printf("%s\n", data->map_line[4]);
	return (0);
}

static void	ft_create_bg(t_data *data)
{
	int	i;
	int	j;
	int	color;

	j = 0;
	color = 0x00096A09;
	while (j < data->height)
	{
		i = 0;
		while (i < data->lenght)
		{
			mlx_pixel_put(data->mlx, data->mlx_win, i, j, color);
			i++;
		}
		j++;
	}
}

int	ft_init_map(t_data *data)
{
	char	*t;

	t = "Solong";
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->lenght, data->height, t);
	if (!data->mlx_win)
		return (ft_error_game(data, "La fenetre ne s'est pas affiche\n"));
	ft_create_bg(data);
	ft_create_map(data);
	mlx_key_hook(data->mlx_win, ft_check_key, data);
	mlx_loop(data->mlx);
	return (END);
}
