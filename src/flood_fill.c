/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:15:09 by gandre-d          #+#    #+#             */
/*   Updated: 2024/02/23 15:15:10 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	flood_fill(char	**mapp, int x, int y)
{
	if (mapp[y][x] == '1')
		return ;
	map()->temp_collectible += (mapp[y][x] == 'C');
	map()->temp_exit += (mapp[y][x] == 'E');
	map()->temp_position += (mapp[y][x] == 'P');
	mapp[y][x] = '1';
	flood_fill(mapp, x + 1, y);
	flood_fill(mapp, x - 1, y);
	flood_fill(mapp, x, y + 1);
	flood_fill(mapp, x, y - 1);
}

void	check_position_and_fill(char **mapp, int y)
{
	int		x;

	x = 0;
	while (mapp[y][x])
	{
		if (mapp[y][x] == 'P')
		{
			map()->starting_pos_x = x;
			map()->starting_pos_y = y;
			flood_fill(map()->temp_map,
				map()->starting_pos_x, map()->starting_pos_y);
			if (!(map()->collectible == map()->temp_collectible 
					&& map()->exit == map()->temp_exit
					&& map()->starting_pos == map()->temp_position))
			{
				free_map(map()->temp_map);
				free_map(map()->full_map);
				ft_error("No possible path");
			}
			return ;
		}
		x++;
	}
}

void	pre_flood_fill(char **mapp)
{
	int		y;

	y = 0;
	while (mapp[y])
	{
		check_position_and_fill(mapp, y);
		y++;
	}
	free_map(map()->temp_map);
}
