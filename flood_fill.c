/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:19:32 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/15 14:33:40 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **tab, t_point size, t_point begin, char c)
{
	if (begin.x < 1 || begin.y > size.y - 1 || begin.x > size.x - 1
		|| tab[begin.y][begin.x] == '-' || tab[begin.y][begin.x] == '1' ||
		tab[begin.y][begin.x] == c)
		return ;
	tab[begin.y][begin.x] = '-';
	fill(tab, size, (t_point){begin.x - 1, begin.y}, c);
	fill(tab, size, (t_point){begin.x + 1, begin.y}, c);
	fill(tab, size, (t_point){begin.x, begin.y + 1}, c);
	fill(tab, size, (t_point){begin.x, begin.y - 1}, c);
}

void	flood_fill(char **tab, t_point size, t_point begin, char c)
{
	fill(tab, size, begin, c);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**ft_valid(char **ptr, int len, char *buffer, char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (ptr[i][j])
		{
			if (ptr[i][j] == 'P' || ptr[i][j] == c || ptr[i][j] == 'C')
			{
				ft_free(len, ptr);
				free(buffer);
				ft_putstr("Error\n");
				exit(-1);
			}
			j++;
		}
		i++;
	}
	ft_free(len, ptr);
	return (ft_split(buffer, '\n'));
}
