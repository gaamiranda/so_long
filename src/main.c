/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:48:25 by gandre-d          #+#    #+#             */
/*   Updated: 2024/02/22 15:48:26 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	create_temp_map(void)
{
	int		i;

	i = 0;
	map()->temp_map = (char **)malloc(sizeof(char *) * (map()->rows + 1));
	if (!map()->temp_map)
	{
		free_map(map()->full_map);
		ft_error("mem allocation failed, malloc 2");
	}
	while (map()->full_map[i])
	{
		map()->temp_map[i] = ft_strdup1(map()->full_map[i]);
		if (!map()->temp_map[i]) 
		{
			free_map(map()->full_map);
			free_map(map()->temp_map);
			ft_error("mem allocation failed, strdup");
		}
		i++;
	}
	map()->temp_map[i] = NULL;
}

void	map_init(int fd)
{
	int		i;
	char	*str;

	i = 0;
	map()->full_map = (char **)malloc((map()->rows + 1) * sizeof(char *));
	if (!map()->full_map)
		ft_error("mem allocation failed, malloc 1");
	str = get_next_line(fd);
	while (str) 
	{
		map()->full_map[i++] = str;
		str = get_next_line(fd);
	}
	map()->full_map[i] = NULL;
	create_temp_map();
}

void	check_args(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc < 2)
		ft_error("too few arguments\n");
	if (argc > 2)
		ft_error("too many arguments\n");
	while (argv[1][i])
		i++;
	i -= 4;
	if (ft_strcmp(&argv[1][i], ".ber"))
		ft_error("wrong map file \n");
}

int	main(int argc, char *argv[])
{
	int		fd;
	int		columns;

	check_args(argc, argv);
	columns = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "error trying to open file\n", 26);
		exit(0);
	}
	check_map(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	check_map1(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map_init(fd);
	close(fd);
	pre_flood_fill(map()->temp_map);
	init_mlx();
	return (0);
}
