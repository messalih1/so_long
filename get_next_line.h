/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:51:47 by messalih          #+#    #+#             */
/*   Updated: 2022/02/12 21:02:53 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# define PX 30

typedef struct game{
	int		fd;
	char	**map;
	void	*mlx;
	void	*win;
	void	*img_w;
	void	*img_e;
	void	*img_p;
	void	*img_c;
	void	*img_b;
	char	*path_p;
	char	*path_w;
	char	*path_b;
	char	*path_e;
	char	*path_c;
	int		win_h;
	int		win_w;
	int		x;
	int		y;
	int		img_h;
	int		img_wi;
	int		len;
	int		l;
	int		i;
	int		index;
	int		n1;
	int		n2;
	int		n3;
	int		n4;
	int		moving;
	int		colec_count;
}t_game;

typedef struct check_map{
	int		fd;
	char	**str;
	size_t	l;
	int		i;
	size_t	len;
	size_t	li;
	int		line_c;
	int		line_coun;
	size_t	first_line;
	int		x;
	size_t	t_line;
	int		e;
	int		p;
	int		c;
	size_t	r;
	size_t	line;
	int		z;
}t_map;

int		key_hook(int keycode, t_game *vars);
void	init_strc(t_game *init, t_map *g, char *ber);
void	character(t_game *put_c);
void	put_walls(t_game *w);
void	values(t_game *v);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		check_map(t_map *p, char *ber);
int		close_win(int keycode);
int		line_count(int fd, char *b);
void	call_fun(t_map *mm, char *arg);
void	free_map(t_game *f);
int		check_ex(char *argv);
#endif
