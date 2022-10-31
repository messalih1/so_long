/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:56:23 by messalih          #+#    #+#             */
/*   Updated: 2022/02/12 21:10:52 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <mlx.h>

void	values(t_game *v)
{
	v->moving = 1;
	v->path_b = "./black.XPM";
	v->img_b = mlx_xpm_file_to_image(v->mlx, v->path_b, &v->img_wi, &v->img_h);
	v->i = 0;
	v->x = 0;
	while (v->map[v->index][v->i] != '\n')
	{
		if (v->map[v->index][v->i] == 'P')
		{
			v->n1 = v->index;
			v->n2 = v->i;
			v->n3 = v->x;
			v->n4 = v->y;
			mlx_put_image_to_window(v->mlx, v->win, v->img_p, v->x, v->y);
		}
		v->x += PX;
		v->i++;
	}
	v->x = 0;
	v->y += PX;
	v->index++;
	v->i = 0;
}

void	character(t_game *c)
{
	c->path_e = "./out.XPM";
	c->img_e = mlx_xpm_file_to_image(c->mlx, c->path_e, &c->img_wi, &c->img_h);
	c->path_c = "./c.XPM";
	c->img_c = mlx_xpm_file_to_image(c->mlx, c->path_c, &c->img_wi, &c->img_h);
	while (c->l-- > 2)
	{
		while (c->map[c->index][c->i] != '\n')
		{
			if (c->map[c->index][c->i] == '1')
				mlx_put_image_to_window(c->mlx, c->win, c->img_w, c->x, c->y);
			else if (c->map[c->index][c->i] == 'C')
			{
				mlx_put_image_to_window(c->mlx, c->win, c->img_c, c->x, c->y);
				c->colec_count++;
			}
			else if (c->map[c->index][c->i] == 'E')
				mlx_put_image_to_window(c->mlx, c->win, c->img_e, c->x, c->y);
			c->x += PX;
			c->i++;
		}
		values(c);
	}
}

void	put_walls(t_game *w)
{
	w->path_w = "./wall.XPM";
	w->img_w = mlx_xpm_file_to_image(w->mlx, w->path_w, &w->img_wi, &w->img_h);
	while (w->map[0][w->i] != '\n')
	{
		mlx_put_image_to_window(w->mlx, w->win, w->img_w, w->x, 0);
		w->x += PX;
		w->i++;
	}
	w->i = 0;
	w->x = 0;
	w->y = (w->l - 1) * PX;
	w->index = w->l - 1;
	while (w->map[w->index][w->i] != '\n')
	{
		mlx_put_image_to_window(w->mlx, w->win, w->img_w, w->x, w->y);
		w->x += PX;
		w->i++;
	}
	w->index = 1;
	w->i = 0;
	w->x = 0;
	w->y = PX;
	character(w);
}

void	init_strc(t_game *i, t_map *g, char *ber)
{
	i->fd = open("map.ber", O_RDONLY);
	i->win_h = line_count(i->fd, ber);
	i->l = i->win_h;
	i->win_w = check_map(g, ber);
	i->win = mlx_new_window(i->mlx, i->win_w * PX, i->win_h * PX, "1");
	i->path_p = "./player.XPM";
	i->img_p = mlx_xpm_file_to_image(i->mlx, i->path_p, &i->img_wi, &i->img_h);
	i->map = malloc(sizeof(char *) * i->win_h);
	if (i->map == NULL)
	{
		printf("error");
		exit(0);
	}
	i->i = 0;
	i->x = 0;
	i->y = 0;
	i->index = 0;
	while (i->l--)
		i->map[i->index++] = get_next_line(i->fd);
	i->l = i->win_h;
	put_walls(i);
}

int	main(int argc, char *argv[])
{
	t_game	p;
	t_game	*ptr;
	t_map	m;
	t_map	*mm;

	mm = &m;
	ptr = &p;
	if (argc > 2)
	{
		printf("pass one arg");
		return (0);
	}
	if (check_map(&m, argv[1]) == 0 || check_ex(argv[1]) == 0)
	{
		printf("error");
		return (0);
	}
	call_fun(mm, argv[1]);
	ptr->mlx = mlx_init();
	init_strc(ptr, &m, argv[1]);
	mlx_key_hook(ptr->win, key_hook, ptr);
	mlx_hook(ptr->win, 17, 0, close_win, 0);
	mlx_loop(ptr->mlx);
}
