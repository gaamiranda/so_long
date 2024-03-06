/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:27:38 by gandre-d          #+#    #+#             */
/*   Updated: 2024/03/02 15:27:40 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	destroy(t_win *win)
{
	mlx_destroy_image(win->mlx, win->img0);
	mlx_destroy_image(win->mlx, win->img1);
	mlx_destroy_image(win->mlx, win->imgp);
	mlx_destroy_image(win->mlx, win->imgc);
	mlx_destroy_image(win->mlx, win->imge);
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
	free_map(map()->full_map);
	exit(0);
	return (0);
}

void	check_if_collected(int keycode, int start_x, int start_y, t_win *win)
{
	static int	number_movements;

	if (keycode == KEY_A || keycode == KEY_D 
		|| keycode == KEY_W || keycode == KEY_S)
	{
		if (start_x != map()->starting_pos_x 
			|| start_y != map()->starting_pos_y)
		{
			number_movements += 1;
			ft_params_d_i(number_movements);
			write(1, "\n", 1);
		}
	}
	if (map()->full_map[map()->starting_pos_y][map()->starting_pos_x] == 'C')
	{
		win->collected += 1;
		map()->full_map[map()->starting_pos_y][map()->starting_pos_x] = '0';
	}
	if ((win->collected == map()->collectible) 
		&& map()->full_map[map()->starting_pos_y][map()->starting_pos_x] == 'E')
	{
		write(1, "WIN", 24);
		destroy(win);
	}
}

int	key_hook(int keycode, t_win *win)
{
	int		x;
	int		y;

	y = map()->starting_pos_y;
	x = map()->starting_pos_x;
	if (map()->full_map[y][x] != 'E')
		mlx_put_image_to_window(win->mlx, win->win,
			win->img0, x * ICON_SIZE, y * ICON_SIZE);
	if (keycode == KEY_ESC)
		destroy(win);
	if (keycode == KEY_A && map()->full_map[y][x - 1] != '1')
		map()->starting_pos_x -= 1;
	else if (keycode == KEY_D && map()->full_map[y][x + 1] != '1')
		map()->starting_pos_x += 1;
	else if (keycode == KEY_W && map()->full_map[y - 1][x] != '1')
		map()->starting_pos_y -= 1;
	else if (keycode == KEY_S && map()->full_map[y + 1][x] != '1')
		map()->starting_pos_y += 1;
	if (map()->full_map[map()->starting_pos_y][map()->starting_pos_x] != 'E')
		mlx_put_image_to_window(win->mlx, win->win, win->imgp,
			map()->starting_pos_x * ICON_SIZE, map()->starting_pos_y * I);
	check_if_collected(keycode, x, y, win);
	return (0);
}

void	draw_bg(t_win *win)
{
	int		x;
	int		y;

	y = 0;
	while (map()->full_map[y])
	{
		x = 0;
		while (map()->full_map[y][x])
		{
			if (map()->full_map[y][x] == '1')
				mlx_put_image_to_window(win->mlx,
					win->win, win->img1, x * I, y * I);
			else
				mlx_put_image_to_window(win->mlx,
					win->win, win->img0, x * I, y * I);
			put_letter(win, y, x);
			x++;
		}
		y++;
	}
}

void	init_mlx(void)
{
	static t_win	win;

	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx,
			map()->columns * I, map()->rows * I, "so_long");
	mlx_key_hook(win.win, key_hook, &win);
	mlx_hook(win.win, 17, 0L, destroy, &win);
	win.path0 = "./textures/0/portugal.xpm";
	win.path1 = "./textures/1/mozambique.xpm";
	win.pathp = "./textures/P/sala.xpm";
	win.pathc = "./textures/C/baca.xpm";
	win.pathe = "./textures/E/aantiga.xpm";
	win.img0 = mlx_xpm_file_to_image(win.mlx, win.path0,
			&win.width, &win.height);
	win.img1 = mlx_xpm_file_to_image(win.mlx, win.path1,
			&win.width, &win.height);
	win.imgp = mlx_xpm_file_to_image(win.mlx, win.pathp,
			&win.width, &win.height);
	win.imgc = mlx_xpm_file_to_image(win.mlx, win.pathc,
			&win.width, &win.height);
	win.imge = mlx_xpm_file_to_image(win.mlx, win.pathe,
			&win.width, &win.height);
	draw_bg(&win);
	mlx_loop(win.mlx);
}
