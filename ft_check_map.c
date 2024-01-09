/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:17:38 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/09 19:28:14 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <unistd.h>
// #include <mlx.h>
#include <fcntl.h>
#include <math.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(char *str)
{
	char *ptr;
	int len;

	len = ft_strlen(str);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	len = 0;
	while (str[len])
	{
		ptr[len] = str[len];
		len++;
	}
	ptr[len] = 0;
	return (ptr);
}

char *ft_strjoin(char *s1, char *s2)
{
	int i;
	int j;
	char *str;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	free(s1);
	return (str);
}
void print_error(char *str, char *fre)
{
	ft_putstr(str);
	free(fre);
	exit(-1);
}

char *get_read_all(int fd)
{
	char *str;
	char *buffer;
	int count;

	count = 0;
	buffer = ft_strdup("");
	str = malloc(sizeof(char) * 300);
	if (!str)
		return (NULL);
	while (1)
	{
		count = read(fd, str, 300);
		buffer = ft_strjoin(buffer, str);
		if (count < 300 || count == 0)
			break;
	}
	free(str);
	return (buffer);
}

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// void	draw_c(t_data *data)
// {
// 	for (int i = 0; i < 1080; i++)
// 	{
// 		for (int j = 0; j < 1080; j++)
// 		{
// 			if (sqrt(pow(data->x - i, 2)+pow(data->y - j, 2)) <= 50)
// 				mlx_pixel_put(data->mlx, data->mlx_win, i, j, 0xffffff);
// 		}
// 	}
// }

// int	key_hook(int keycode, t_data *data)
// {
// 	printf("key is ->> %d\n", keycode);
// 	if (keycode == 124)
// 	{
// 		mlx_clear_window(data->mlx, data->mlx_win);
// 		// data->x += 50;
// 		// draw_c(data);
// 	}
// 	return (0);
// }

int main()
{
	int fd;
	char *buffer;
	char **ptr;
	t_point size;
	t_point begin;

	fd = open("maps", O_RDONLY);
	if (fd < 0)
		return (0);
	buffer = get_read_all(fd);

	// t_data *data = malloc(sizeof(t_data));

	// data->mlx = mlx_init();
	// data->mlx_win = mlx_new_window(data->mlx, 1080, 1080, "Hello world!");
	// data->x=500;
	// data->y=500;

	// draw_c(data);
	// mlx_key_hook(data->mlx_win, key_hook, &data);
	// mlx_loop(data->mlx);

	if (*buffer == 0)
		print_error("Error\n", buffer);
	ptr = ft_split(buffer, '\n');
	if (check_square(ptr, ft_count(buffer, '\n')) < 0 || check_countent(ptr, ft_count(buffer, '\n')) < 0)
		print_error("Error\n", buffer);
	size.x = ft_strlen(ptr[0]) - 1;
	size.y = ft_count(buffer, '\n') - 1;
	begin.x = ft_position(ptr[ft_position(buffer, 'P') / size.x], 'P');
	begin.y = ft_position(buffer, 'P') / size.x;
	// printf("position x:%d\n", begin.x);
	// printf("position y:%d\n", begin.y);
	// printf("wide -->%d\n", size.x);
	// printf("lenght -->%d\n", size.y);
	flood_fill(ptr, size, begin);
	// for (int i = 0;  ptr[i]; i++)
	// 	printf("%s\n", ptr[i]);
}
