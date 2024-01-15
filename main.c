/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:12:02 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/15 15:58:19 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_change(t_data *t, int x, int y)
{
	t_point	po;

	ft_cordinate(t->ptr, &po.x, &po.y, 'P');
	if (t->ptr[y][x] != '1')
	{
		if (t->ptr[y][x] == 'C')
		{
			t->ptr[y][x] = t->ptr[po.y][po.x];
			t->ptr[po.y][po.x] = '0';
		}
		else if (t->ptr[y][x] == '0')
		{
			t->ptr[y][x] = t->ptr[po.y][po.x];
			t->ptr[po.y][po.x] = '0';
		}
		else if (t->ptr[y][x] == 'E')
		{
			if (check_countent(t->ptr, ft_strleen(t->ptr)) == -1)
				exit(0);
		}
	}
}

void	change_position(int keycode, t_data *t, t_point *s)
{
	if (keycode == 126)
		ft_change(t, s->x, s->y - 1);
	else if (keycode == 123)
		ft_change(t, s->x - 1, s->y);
	else if (keycode == 125)
		ft_change(t, s->x, s->y + 1);
	else if (keycode == 124)
		ft_change(t, s->x + 1, s->y);
	return ;
}

int	key_hook(int keycode, t_data *t)
{
	t_point	s;

	ft_cordinate(t->ptr, &s.x, &s.y, 'P');
	printf("the player move %d\n", keycode);
	change_position(keycode, t, &s);
	mlx_clear_window(t->mlx, t->mlx_win);
	ft_put_windows(t);
	mlx_loop(t->mlx);
	return (0);
}

int	main(void)
{
	t_data	t;

	t.ptr = ft_check_map();
	t.mlx = mlx_init();
	t.mlx_win = mlx_new_window(t.mlx, 48 * ft_strlen(t.ptr[0]), 48
			* ft_strleen(t.ptr), "So_long");
	t.x = 0;
	t.y = 0;
	t.exit = mlx_xpm_file_to_image(t.mlx, "textures/exit.xpm", &t.x, &t.y);
	t.col = mlx_xpm_file_to_image(t.mlx, "textures/col.xpm", &t.x, &t.y);
	t.free = mlx_xpm_file_to_image(t.mlx, "textures/free.xpm", &t.x, &t.y);
	t.wall = mlx_xpm_file_to_image(t.mlx, "textures/Wall.xpm", &t.x, &t.y);
	t.play = mlx_xpm_file_to_image(t.mlx, "textures/play.xpm", &t.x, &t.y);
	ft_put_windows(&t);
	mlx_key_hook(t.mlx_win, key_hook, &t);
	mlx_loop(t.mlx);
}
