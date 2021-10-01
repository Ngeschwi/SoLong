/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 21:34:40 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/10/01 18:22:12 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	ft_put_all_img(t_data *data, char *path, void **img, int i, int j)
{
	int	l;
	int	h;

	l = 50;
	h = 50;
	*img = mlx_xpm_file_to_image(data->mlx, path, &l, &h);
	mlx_put_image_to_window(data->mlx, data->mlx_win, *img,
		60 * i, 60 * j);
}

static void	ft_put_img_collect(t_data *data, int i, int j)
{
	int	l;
	int	h;

	l = 50;
	h = 50;
	data->img_c[data->check_c] = mlx_xpm_file_to_image(data->mlx,
		data->path_c, &l, &h);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->img_c[data->check_c], 60 * i, 60 * j);
	data->check_c++;
}

static void	ft_put_img_wall(t_data *data, int i, int j)
{
	int	l;
	int	h;

	l = 50;
	h = 50;
	data->img_w[data->check_w] = mlx_xpm_file_to_image(data->mlx,
		data->path_w, &l, &h);
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->img_w[data->check_w], 60 * i, 60 * j);
	data->check_w++;
}

void	ft_create_map(t_data *data, int when)
{
	int	i;
	int	j;

	j = 0;
	data->check_w = 0;
	data->check_c = 0;
	if (when == 0)
		ft_destroy_all_img(data);
	while (j < data->nbr_line)
	{
		i = 0;
		while (i < data->nbr_column)
		{
			if (data->map_line[j][i] == '1')
				ft_put_img_wall(data, i, j);
			else if (data->map_line[j][i] == 'C')
				ft_put_img_collect(data, i, j);
			else if (data->map_line[j][i] == 'E')
				ft_put_all_img(data, data->path_e, &data->img_e, i, j);
			else if (data->map_line[j][i] == 'P')
				ft_put_all_img(data, data->path_p, &data->img_p, i, j);
			i++;
		}
		j++;
	}
}

void	ft_create_bg(t_data *data, int color)
{
	int		i;
	int		j;
	char	*dst;

	j = 0;
	data->img_bg = mlx_new_image(data->mlx, data->lenght, data->height);
	data->a = mlx_get_data_addr(data->img_bg, &data->pb, &data->lb, &data->en);
	while (j < data->height)
	{
		i = 0;
		while (i < data->lenght)
		{
			dst = data->a + (j * data->lb + i * (data->pb / 8));
			*(unsigned int *)dst = color;
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_bg, 0, 0);
}
