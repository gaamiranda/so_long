/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:52:36 by gandre-d          #+#    #+#             */
/*   Updated: 2024/02/22 15:52:38 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static int	ft_strlen(const char *s1)
{
	int		i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

char	*ft_strdup1(const char *s1)
{
	int		i;
	char	*ptr;
	int		size;

	i = 0;
	size = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * size + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
