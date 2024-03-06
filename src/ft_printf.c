/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:29:26 by gandre-d          #+#    #+#             */
/*   Updated: 2024/03/02 19:29:27 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_letter(t_win *win, int y, int x)
{
	if (map()->full_map[y][x] == 'P')
		mlx_put_image_to_window(win->mlx, win->win,
			win->imgp, x * I, y * I);
	else if (map()->full_map[y][x] == 'C')
		mlx_put_image_to_window(win->mlx, win->win,
			win->imgc, x * I, y * I);
	else if (map()->full_map[y][x] == 'E')
		mlx_put_image_to_window(win->mlx, win->win,
			win->imge, x * I, y * I);
}

void	ft_params_d_i(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2", 2);
		write(1, "147483648", 9);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_params_d_i(-n);
	}
	else if (n > 9)
	{
		ft_params_d_i(n / 10);
		ft_params_d_i(n % 10);
	}
	else
	{
		c = n + 48;
		write(1, &c, 1);
	}
}

void	check_line_length(char *str, int expected_length)
{
	int		temp;

	temp = 0;
	while (str[temp] && str[temp] != '\n')
		temp++;
	if (temp != expected_length)
	{
		free(str);
		ft_error("Invalid map\n");
	}
}
