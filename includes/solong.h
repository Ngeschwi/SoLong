/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <nathan.geschwind@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:50:23 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/09/30 23:12:19 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include "../minilibX/mlx.h"

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	char	*path_c;
	void	**img_c;
	char	*path_w;
	void	**img_w;
	char	*path_e;
	void	*img_e;
	char	*path_p;
	void	*img_p;
	void	*img_bg;
	int		pi_bi;
	int		li_by;
	int		endian;
	char	*addr;
	int		lenght;
	int		height;
	int		collect_c;
	int		exit_e;
	int		player_p;
	int		coord[2];
	char	*map;
	char	**map_line;
	int		nbr_line;
	int		nbr_column;
	int		nbr_wall;
	int		count_move;
}t_data;

# define ERROR 1
# define NO_ERROR 0
# define END 0
# define X 0
# define Y 1
# define UP 0
# define DOWN 1
# define LEFT 0
# define RIGHT 1

int		ft_parse_map(t_data *data);
int		ft_check_is_close(t_data *data);
int		ft_error_map(t_data *data, char *str, int check);
int		ft_error_game(t_data *data, char *str);
void	ft_free_map(char **map);

int		ft_init_map(t_data *data);
void	ft_create_bg(t_data *data, int color);
void	ft_create_map(t_data *data);
int		ft_up_down(t_data *data, int where);
int		ft_left_right(t_data *data, int where);
void	ft_end(t_data *data);

int		ft_strlen(const char *str);
void	ft_putstr(char *str);
char	*ft_strdup(const char *str);

#endif