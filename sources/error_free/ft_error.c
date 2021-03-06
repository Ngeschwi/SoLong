/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:08:21 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/10/05 19:11:43 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_error_map(t_data *data, char *str, int check)
{
	ft_putstr("Error\n");
	ft_putstr(str);
	free(data->path_map);
	free(data->map);
	if (check == 1)
		ft_free_map(data);
	return (ERROR);
}
