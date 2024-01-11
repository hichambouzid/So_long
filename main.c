/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:12:02 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/11 23:52:38 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include<mlx.h>
int main()
{
	void *mlx;
	void *img;
	void *mlx_win;
	char *ptrr = "./Wall.xpm";
	int x = 0, y = 0;
	int i;
	int j;
	char **ptr;
	int f;

	i = 0;
	int n;
	n = 0;
	char **pt = ft_check_map();
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 48 * ft_strlen(pt[0]), 48 * 7, "So_long");
	img = mlx_xpm_file_to_image(mlx, ptrr, &x, &y);
	// mlx_put_image_to_window(mlx, mlx_win,img, 0, 0);
	x = 0;
	y = 0;
	while (pt[i])
	{
		j = 0;
		f = 0;
		while (pt[i][j])
		{
			if (pt[i][j] == '1')
				mlx_put_image_to_window(mlx, mlx_win,img, x + f, y + n);
			f += 48;
			j++;
		}
		n += 48;
		i++;
	}
	mlx_loop(mlx);
}
