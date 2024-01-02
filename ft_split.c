/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:29:47 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/02 18:56:05 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_separator(char s, char c)
{
	return (s == c);
}

 int	ft_count(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!is_separator(s[0], c))
	{
		count++;
		i++;
	}
	while (s[i])
	{
		if (is_separator(s[i], c) && s[i + 1] && is_separator(s[i + 1], c))
			return (-1);
		if (is_separator(s[i], c) && s[i + 1] && !is_separator(s[i + 1], c))
			count++;
		
		i++;
	}
	return (count);
}

static char	**ft_freee(int index, char **ptr)
{
	while (index >= 0)
	{
		free(ptr[index]);
		index--;
	}
	free(ptr);
	return (0);
}

static char	**ft_alloc(char **ptr, const char *s, char c, int e)
{
	int	i;
	int	j;
	int	f;

	i = 0;
	j = 0;
	while (s[i] && j != e)
	{
		while (is_separator(s[i], c) && s[i])
			i++;
		f = i;
		if (!s[f])
			break ;
		while (!is_separator(s[f], c) && s[f])
			f++;
		ptr[j] = malloc(sizeof(char) * (1 + f - i));
		if (!ptr[j])
			return (ft_freee(j - 1, ptr));
		f = 0;
		while (s[i] && !is_separator(s[i], c))
			ptr[j][f++] = s[i++];
		ptr[j][f] = 0;
		j++;
	}
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		count;

	if (!s || !*s)
	{
		ptr = malloc(sizeof(char *));
		if (!ptr)
			return (NULL);
		ptr[0] = 0;
		return (ptr);
	}
	count = ft_count(s, c);
	if (count <= 2)
		print_error("Error\n", ft_strdup(""));
	ptr = malloc(sizeof(char *) * (count + 1));
	if (!ptr)
		return (NULL);
	ptr[count] = 0;
	return (ft_alloc(ptr, s, c, count));
}

// int main()
// {
// 	char **str = ft_split("hicham\nbouzid\n\nde tenger\n", '\n');
// 	for (int i = 0; str[i]; i++)
// 		printf("%s\n", str[i]);
// }