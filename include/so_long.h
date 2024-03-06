/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:57:42 by gandre-d          #+#    #+#             */
/*   Updated: 2024/02/22 15:57:43 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include "../mlx_linux/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include "../gnl/get_next_line.h"
# include <stdbool.h>

# define KEY_ESC 65307
# define ICON_SIZE 40
# define I 40
# define KEY_A 97
# define KEY_W 119
# define KEY_S 115
# define KEY_D 100

typedef struct s_map{
	int		exit;
	int		collectible;
	int		starting_pos;
	int		columns;
	int		rows;
	char	**full_map;
	char	**temp_map;
	int		starting_pos_x;
	int		starting_pos_y;
	int		temp_collectible;
	int		temp_exit;
	int		temp_position;
}	t_map;

typedef struct s_win{
	void	*mlx;
	void	*win;
	void	*img0;
	void	*img1;
	void	*imgc;
	void	*imge;
	void	*imgp;
	char	*path0;
	char	*path1;
	char	*pathc;
	char	*pathe;
	char	*pathp;
	int		width;
	int		height;
	int		collected;
}	t_win;

void	check_map(int fd);
void	check_map1(int fd);
void	ft_error(char *str);
void	check_walls(char *str, int wall, int size_line);
t_map	*map(void);
t_win	*win(void);
void	map_characters(char *str);
void	check_characters(void);
void	create_temp_map(void);
void	free_map(char **map);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup1(const char *s1);
void	pre_flood_fill(char	**map);
void	flood_fill(char	**mapp, int x, int y);
void	init_mlx(void);
void	put_letter(t_win *win, int y, int x);
void	ft_params_d_i(int n);
void	check_line_length(char *str, int expected_length);

#endif
