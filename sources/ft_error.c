/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:08:21 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/12 14:02:09 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_error_map(t_map *map, char *str)
{
	ft_putstr("Error\n");
	ft_putstr(str);
	free(map->map);
	return (ERROR);
}
