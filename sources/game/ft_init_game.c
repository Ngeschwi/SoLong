/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 10:53:13 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/10/01 17:52:26 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_check_key(int key, t_data *data)
{
	if (key == 53)
		ft_end(data);
	else if (key == 13)
		ft_up_down(data, UP);
	else if (key == 1)
		ft_up_down(data, DOWN);
	else if (key == 0)
		ft_left_right(data, LEFT);
	else if (key == 2)
		ft_left_right(data, RIGHT);
	else
		return (1);
	return (0);
}

int	ft_init_map(t_data *data)
{
	char	*t;

	t = "Solong";
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->lenght, data->height, t);
	if (!data->mlx_win)
		return (ft_error_map(data, "La fenetre ne s'est pas affiche\n", 1));
	ft_create_bg(data, 0x00096A09);
	ft_create_map(data, 1);
	mlx_key_hook(data->mlx_win, ft_check_key, data);
	mlx_loop(data->mlx);
	return (END);
}
