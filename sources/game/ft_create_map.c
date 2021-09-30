/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 21:34:40 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/09/30 22:19:12 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_create_map(t_data *data)
{
	int	l;
	int	h;
	int	i;
	int	j;

	j = 0;
	l = 50;
	h = 50;
	while (data->map_line[j])
	{
		i = 0;
		while (data->map_line[j][i])
		{
			if (data->map_line[j][i] == '1')
			{
				data->img_w = mlx_xpm_file_to_image(data->mlx, data->path_w, &l, &h);
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_w, 60 * i, 60 * j);
			}
			else if (data->map_line[j][i] == 'C')
			{
				data->img_c = mlx_xpm_file_to_image(data->mlx, data->path_c, &l, &h);
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_c, 60 * i, 60 * j);
			}
			else if (data->map_line[j][i] == 'E')
			{
				data->img_e = mlx_xpm_file_to_image(data->mlx, data->path_e, &l, &h);
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_e, 60 * i, 60 * j);
			}
			else if (data->map_line[j][i] == 'P')
			{
				if (data->img_p != NULL)
					mlx_destroy_image(data->mlx, data->img_p);
				data->img_p = mlx_xpm_file_to_image(data->mlx, data->path_p, &l, &h);
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_p, 60 * i, 60 * j);
			}
			i++;
		}
		j++;
	}
}
