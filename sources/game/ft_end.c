/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:03:02 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/10/07 15:13:15 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_destroy_all_img(t_data *data)
{
	int	i;

	i = 0;
	mlx_destroy_image(data->mlx, data->img_p);
	mlx_destroy_image(data->mlx, data->img_e);
	mlx_destroy_image(data->mlx, data->img_bg);
	while (i < data->collect_c)
	{
		mlx_destroy_image(data->mlx, data->img_c[i]);
		i++;
	}
	i = 0;
	while (i < data->nbr_wall)
	{
		mlx_destroy_image(data->mlx, data->img_w[i]);
		i++;
	}
}

int	ft_end(t_data *data)
{
	free(data->map);
	ft_free_map(data);
	free(data->img_c);
	free(data->img_w);
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(EXIT_SUCCESS);
	return (0);
}
