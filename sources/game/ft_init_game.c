/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 10:53:13 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/09/30 23:12:24 by ngeschwi         ###   ########.fr       */
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
	return (0);
}

void	ft_create_bg(t_data *data, int color)
{
	int		i;
	int		j;
	char	*dst;

	j = 0;
	data->img_bg = mlx_new_image(data->mlx, data->lenght, data->height);
	data->addr = mlx_get_data_addr(data->img_bg, &data->pi_bi, &data->li_by, &data->endian);
	while (j < data->height)
	{
		i = 0;
		while (i < data->lenght)
		{
			dst = data->addr + (j * data->li_by + i * (data->pi_bi / 8));
			*(unsigned int*)dst = color;
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_bg, 0, 0);
}

int	ft_init_map(t_data *data)
{
	char	*t;

	t = "Solong";
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->lenght, data->height, t);
	if (!data->mlx_win)
		return (ft_error_game(data, "La fenetre ne s'est pas affiche\n"));
	ft_create_bg(data, 0x00096A09);
	ft_create_map(data);
	mlx_key_hook(data->mlx_win, ft_check_key, data);
	mlx_loop(data->mlx);
	return (END);
}
