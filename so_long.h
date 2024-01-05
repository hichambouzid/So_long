/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:28:39 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/05 13:01:42 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	print_error(char *str, char *fre);
void	ft_putstr(char *str);
char	**ft_split(char const *s, char c);
int		ft_count(char const *s, char c);
int		ft_free(int index, char **ptr);
int		ft_strcmp(char *s1, char *s2);
int		is_separator(char s, char c);
int		check_square(char **ptr, int len);
int		check_countent(char **ptr, int len);

#endif
