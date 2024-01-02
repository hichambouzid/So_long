#ifndef SO_LOGNG_H
#define SO_LOGNG_H
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>

int ft_strlen(char *str);
char *ft_strdup(char *str);
char *ft_strjoin(char *s1, char *s2);
void print_error(char *str, char *fre);
void ft_putstr(char *str);
char	**ft_split(char const *s, char c);
int	ft_count(char const *s, char c);
int	ft_free(int index, char **ptr);
int ft_strcmp(char *s1, char *s2);
int	is_separator(char s, char c);
int check_square(char **ptr, int len);

#endif