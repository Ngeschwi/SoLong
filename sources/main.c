/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@stutent.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:55:56 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/09 16:22:28 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	if (ft_parse_map(argc, argv) == ERROR)
		return (ERROR);
	return (0);
}


/*
mlx_init() : initialise la libX
mlx_new_windows() : gerer la fenetre
mlx_pixel_put() : dessiner dans la fenetre
mlx_new_image() : afficher une image dans la fenetre
mlx_loop() : creer une boucle pour receptionner les event des claviers et de la souris
*/