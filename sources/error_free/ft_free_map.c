/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 12:12:14 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/10/01 18:14:31 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_line[i])
	{
		free(data->map_line[i]);
		i++;
	}
	free(data->map_line);
}
