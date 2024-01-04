/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:22:45 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/04 16:30:17 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free(int index, char **ptr)
{
	while (index >= 0)
	{
		free(ptr[index]);
		index--;
	}
	free(ptr);
	return (0);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	check_square(char **ptr, int len)
{
	int		i;

	i = 0;
	while (is_separator(ptr[0][i], '1') && is_separator(ptr[len - 1][i], '1')
		&& ptr[len - 1][i] && ptr[0][i])
		i++;
	if (i != ft_strlen(ptr[0]) || i != ft_strlen(ptr[len - 1]))
		return (ft_free(len, ptr));
	if (ft_strcmp(ptr[0], ptr[len - 1]) != 0)
		return (ft_free(len, ptr));
	i = 1;
	while (ptr[i] && i >= len - 2)
	{
		if (ft_strlen(ptr[i]) == len && ptr[i][0] == '1'
			&& ptr[i][ft_strlen(ptr[i]) - 1] == '1')
			i++;
		else
			return (ft_free(len, ptr));
	}
	return (i);
}
