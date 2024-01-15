/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:17:38 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/15 15:59:01 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *str)
{
	char	*ptr;
	int		len;

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

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

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

void	print_error(char *str, char *fre)
{
	ft_putstr(str);
	free(fre);
	exit(-1);
}

char	*get_read_all(int fd)
{
	char	*str;
	char	*buffer;
	int		count;

	count = 0;
	buffer = ft_strdup("");
	str = malloc(sizeof(char) * 2147483646);
	if (!str)
		return (NULL);
	while (1)
	{
		count = read(fd, str, 2147483646);
		buffer = ft_strjoin(buffer, str);
		if (count < 2147483646 || count == 0)
			break ;
	}
	free(str);
	return (buffer);
}

char	**ft_check_map(void)
{
	int		fd;
	char	*buffer;
	char	**ptr;
	t_point	size;
	t_point	begin;

	fd = open("./maps/maps.ber", O_RDONLY);
	if (fd < 0)
		return (0);
	buffer = get_read_all(fd);
	if (*buffer == 0)
		print_error("Error\n", buffer);
	ptr = ft_split(buffer, '\n');
	if (check_square(ptr, ft_count(buffer, '\n')) < 0 || check_countent(ptr,
			ft_count(buffer, '\n')) < 0)
		print_error("Error\n", buffer);
	size.x = ft_strlen(ptr[0]);
	size.y = ft_count(buffer, '\n');
	begin.y = ft_position(buffer, 'P') / size.x;
	ft_cordinate(ptr, &begin.x, &begin.y, 'P');
	flood_fill(ptr, size, begin, 'E');
	ptr = ft_valid(ptr, ft_count(buffer, '\n'), buffer, 0);
	flood_fill(ptr, size, begin, '1');
	ptr = ft_valid(ptr, ft_count(buffer, '\n'), buffer, 'E');
	return (free(buffer), ptr);
}
