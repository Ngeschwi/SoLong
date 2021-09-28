/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 10:53:13 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/09/28 15:53:39 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_exit(int	key, t_data *mlx)
{
	// 53 -> esc
	// 13 -> w
	// 0 -> a
	// 1 -> s
	// 2 -> d

	if (key == 13)
		printf("test W\n");
	if (key == 0)
		printf("test A\n");
	if (key == 1)
		printf("test S\n");
	if (key == 2)
		printf("test D\n");
	if (key == 53)
	{
		printf("test quit\n");
		mlx_clear_window(mlx->mlx, mlx->mlx_win);
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		return (END);
	}
	return (0);
}

int	ft_init_map(t_data *mlx, t_map *map)
{
	int	taille;

	taille = 500;
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, 500, 500, "test");
	if (!mlx->mlx_win)
		return (ft_error_game(map, "La fenetre ne s'est pas affiche\n"));
	mlx->img_bg = mlx_xpm_file_to_image(mlx->mlx, mlx->path_bg, &taille, &taille);
	mlx_key_hook(mlx->mlx_win, ft_exit, mlx);
	mlx_loop(mlx->mlx);
	return (END);
}
