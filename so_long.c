/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:18:49 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/15 12:28:43 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_image(char c, t_data *image)
{
	if (c == 'E')
		return (image->exit);
	if (c == '1')
		return (image->wall);
	if (c == 'C')
		return (image->col);
	if (c == '0')
		return (image->free);
	return (image->play);
}

void	ft_put_windows(t_data *t)
{
	int		e;
	int		n;
	t_point	f;

	n = 0;
	f.y = -1;
	while (t->ptr[++f.y])
	{
		f.x = -1;
		e = 0;
		while (t->ptr[f.y][++f.x])
		{
			mlx_put_image_to_window(t->mlx, t->mlx_win,
				ft_image(t->ptr[f.y][f.x], t), e, n);
			e += 48;
		}
		n += 48;
	}
}
