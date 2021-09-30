/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:03:02 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/09/30 23:12:34 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_end(t_data *data)
{
	printf("Bravo vous avez reussi !\n");
	free(data->map);
	ft_free_map(data->map_line);
	ft_create_bg(data, 0x00000000);
}
