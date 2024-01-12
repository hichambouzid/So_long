/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:18:49 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/12 21:29:44 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_image(char c, void *mlx, int *x, int *y)
{
	if (c == 'E')
		return (mlx_xpm_file_to_image(mlx, "./exit.xpm", x, y));
	if (c == '1')
		return (mlx_xpm_file_to_image(mlx, "./Wall.xpm", x, y));
	if (c == 'C')
		return (mlx_xpm_file_to_image(mlx, "./col.xpm", x, y));
	if (c == '0')
		return (mlx_xpm_file_to_image(mlx, "./free.xpm", x, y));
	if (c == 'P')
		return (mlx_xpm_file_to_image(mlx, "./play.xpm", x, y));
	return (mlx_xpm_file_to_image(mlx, "./col.xpm", x, y));
}

void	ft_put_windows(void)
{
	t_data	rt;
	char	**ptr;
	int		e;
	int		n;
	t_point	f;

	ptr = ft_check_map();
	rt.mlx = mlx_init();
	rt.mlx_win = mlx_new_window(rt.mlx, 48 * ft_strlen(ptr[0]), 48
			* ft_strleen(ptr), "So_long");
	n = 0;
	f.y = -1;
	while (ptr[++f.y])
	{
		f.x = -1;
		e = 0;
		while (ptr[f.y][++f.x])
		{
			mlx_put_image_to_window(rt.mlx, rt.mlx_win, ft_image(ptr[f.y][f.x],
					rt.mlx, &rt.x, &rt.y), e, n);
			e += 48;
		}
		n += 48;
	}
	mlx_loop(rt.mlx);
}
