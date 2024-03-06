/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gandre-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:59:51 by gandre-d          #+#    #+#             */
/*   Updated: 2024/02/22 15:59:52 by gandre-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_nlcheck(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i++] == '\n')
		{
			str[i] = '\0';
			break ;
		}
	}
	return (str);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_help(char *str, char *buf)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = (char *)malloc(ft_strlen(str) + ft_strlen(buf) + 1);
	if (!ptr)
		return (NULL);
	while (str && str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	free(str);
	while (buf[j])
		ptr[i++] = buf[j++];
	ptr[i] = '\0';
	return (ft_nlcheck(ptr));
}

int	ft_bufclear(char *buf)
{
	int		i;
	int		j;
	int		nl;

	i = 0;
	j = 0;
	nl = 0;
	while (buf[i])
	{
		if (nl == 1)
			buf[j++] = buf[i];
		if (buf[i] == '\n')
			nl = 1;
		buf[i] = '\0';
		i++;
	}
	return (nl);
}
