/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:44:31 by gandre-d          #+#    #+#             */
/*   Updated: 2024/02/22 15:44:32 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_characters(void)
{
	if (map()->exit != 1)
		ft_error("Invalid exit numbers");
	if (map()->starting_pos != 1)
		ft_error("Invalid starting position numbers");
	if (map()->collectible < 1)
		ft_error("Invalid collectible numbers");
}

//verificar se a volta e tudo paredes
void	check_walls(char *str, int wall, int size_line)
{
	int		i;

	i = 0;
	if (wall == 1)
	{
		while (str[i] && str[i] != '\n')
		{
			if (str[i] != '1')
			{
				free(str);
				ft_error("Invalid walls\n");
			}
			i++;
		}
	}
	else
	{
		if (str[i] != '1' || str[size_line - 1] != '1')
		{
			free(str);
			ft_error("Invalid walls\n");
		}
	}
}

// verificar se mapa e um retangulo
void	check_map(int fd)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = get_next_line(fd);
	while (str && str[i] && str[i] != '\n')
		i++;
	while (str)
	{
		check_line_length(str, i);
		free(str);
		str = get_next_line(fd);
		j++;
	}
	map()->columns = i;
	map()->rows = j;
}

//verificar se os caracteres do mapa sao ok
void	map_characters(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == '0' || str[i] == '1' || str[i] == 'C' 
			|| str[i] == 'E' || str[i] == 'P')
		{
			if (str[i] == 'P')
				map()->starting_pos += 1;
			else if (str[i] == 'C')
				map()->collectible += 1;
			else if (str[i] == 'E')
				map()->exit += 1;
		}
		else
		{
			free(str);
			ft_error("Invalid character\n");
		}
		i++;
	}
}

// verificar se o mapa tem paredes a volta
void	check_map1(int fd)
{
	char	*str;
	int		size_line;

	str = get_next_line(fd);
	size_line = 0;
	while (str[size_line] && str[size_line] != '\n')
		size_line++;
	check_walls(str, 1, size_line);
	free(str);
	str = get_next_line(fd);
	while (str)
	{
		if (str[size_line] == '\0')
			check_walls(str, 1, size_line);
		else
			check_walls(str, 2, size_line);
		map_characters(str);
		free(str);
		str = get_next_line(fd);
	}
	check_characters();
}
