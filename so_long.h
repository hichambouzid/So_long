/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:28:39 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/12 21:30:29 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct data
{
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
}			t_data;

typedef struct ss_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_dataa;

typedef struct s_image
{
	char	*wall;
	char	*exit;
	char	*free;
	char	*col;
}			t_image;

// texture->exit = mlx_xpm_file_to_image(mlx, "./exit.xpm", x, y)
void		ft_put_windows(void);
void		*ft_image(char c, void *mlx, int *x, int *y);
int			ft_strleen(char **ptr);
int			ft_strlen(char *str);
char		*ft_strdup(char *str);
char		*ft_strjoin(char *s1, char *s2);
void		print_error(char *str, char *to_free);
void		ft_putstr(char *str);
char		**ft_split(char const *s, char c);
int			ft_count(char const *s, char c);
int			ft_free(int index, char **ptr);
int			ft_strcmp(char *s1, char *s2);
int			is_separator(char s, char c);
int			check_square(char **ptr, int len);
int			check_countent(char **ptr, int len);
void		flood_fill(char **tab, t_point size, t_point begin);
int			ft_position(char *buffer, int c);
char		**ft_valid(char **ptr, int len, char *buffer);
char		**ft_check_map(void);
int			ft_cordinate(char **ptr, int *x, int *y, char p);

#endif
