/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:50:23 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/06/11 16:13:41 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include "../minilibX/mlx.h"

typedef struct s_parse
{
	int		collect_c;
	int		exit_e;
	int		player_p;
}				t_parse;

typedef struct s_map
{
	char	*map;
	int		line;
	int		column;
}				t_map;

# define ERROR 1
# define NO_ERROR 0

int		ft_parse_map(int argc, char **argv, t_map *map);

int		ft_strlen(const char *str);
char	*ft_strdup(const char *str);

#endif