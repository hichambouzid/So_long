/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:19:32 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/09 19:06:18 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void fill(char **tab, t_point size, t_point begin, char to_fill)
{
	if (begin.x < 1 || begin.y > size.y - 1 || begin.x > size.x - 1 ||
		tab[begin.y][begin.x] == to_fill || tab[begin.y][begin.x] == '1')
		return ;
		tab[begin.y][begin.x] = to_fill;
		fill(tab, size, (t_point){begin.x - 1, begin.y}, to_fill);
		fill(tab, size, (t_point){begin.x + 1, begin.y}, to_fill);
		fill(tab, size, (t_point){begin.x, begin.y + 1}, to_fill);
		fill(tab, size, (t_point){begin.x, begin.y - 1}, to_fill);
	
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, '-');	
}