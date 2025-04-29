/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:27:40 by ndelhota          #+#    #+#             */
/*   Updated: 2024/10/28 18:33:17 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*ft_fill(char *new_remain, int fd);
char	*get_next_line(int fd);
char	*read_l(int fd);
char	*ft_join(char *s1, char *s2);
int		ft_strlen(char *s);
int		ft_strchr(char *s, char seek);
char	*ft_substr(char *s, int start, int len);
char	*ft_memcpy(char *dest, char *src, int n);
char	*ft_readjust_remain(char *s, int start);
char	*ft_last(char *remain);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
#endif 
