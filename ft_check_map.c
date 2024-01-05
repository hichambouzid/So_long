<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 11:27:56 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/05 11:55:18 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
	str = malloc(sizeof(char) * 300);
	if (!str)
		return (NULL);
	while (1)
	{
		count = read(fd, str, 300);
		buffer = ft_strjoin(buffer, str);
		if (count < 300 || count == 0)
			break ;
	}
	free(str);
	return (buffer);
}

int	main(void)
{
	int			fd;
	char		*buffer;
	char		**ptr;

	fd = open("maps", O_RDONLY);
	if (fd < 0)
		return (0);
	buffer = get_read_all(fd);
	if (*buffer == 0)
		print_error("Error\n", buffer);
	ptr = ft_split(buffer, '\n');
	if (check_square(ptr, ft_count(buffer, '\n')) <= 0)
		print_error("Error\n", buffer);
}
=======
>>>>>>> eb7ecc4d538989fdc79a293274fe5ee1e7b33bd0
