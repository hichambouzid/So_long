/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:19:32 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/11 16:56:55 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **tab, t_point size, t_point begin, char to_fill)
{
	if (begin.x < 1 || begin.y > size.y - 1 || begin.x > size.x - 1
		|| tab[begin.y][begin.x] == to_fill || tab[begin.y][begin.x] == '1')
		return ;
	tab[begin.y][begin.x] = to_fill;
	fill(tab, size, (t_point){begin.x - 1, begin.y}, to_fill);
	fill(tab, size, (t_point){begin.x + 1, begin.y}, to_fill);
	fill(tab, size, (t_point){begin.x, begin.y + 1}, to_fill);
	fill(tab, size, (t_point){begin.x, begin.y - 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, '-');
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**ft_valid(char **ptr, int len, char *buffer)
{
	int		i;
	int		j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (ptr[i][j])
		{
			if (ptr[i][j] == 'P' || ptr[i][j] == 'E' || ptr[i][j] == 'C')
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
