/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:27:13 by messalih          #+#    #+#             */
/*   Updated: 2022/02/12 20:27:16 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <mlx.h>

void	mov_rihgt( t_game *r)
{
	if (r->map[r->n1][r->n2 + 1] == '1')
		return ;
	else if (r->map[r->n1][r->n2 + 1] == 'E' && r->colec_count != 0)
		return ;
	else
	{
		mlx_put_image_to_window(r->mlx, r->win, r->img_b, r->n3, r->n4);
		mlx_put_image_to_window(r->mlx, r->win, r->img_p, r->n3 += PX, r->n4);
	}
	r->map[r->n1][r->n2] = '0';
	r->n2 += 1;
	if (r->map[r->n1][r->n2] == 'C')
	{
		mlx_put_image_to_window(r->mlx, r->win, r->img_b, r->n3, r->n4);
		mlx_put_image_to_window(r->mlx, r->win, r->img_p, r->n3, r->n4);
		r->colec_count--;
	}
	if (r->map[r->n1][r->n2] == 'E' && r->colec_count == 0)
	{
		free_map(r);
		exit(0);
	}
	printf("%d\n", r->moving++);
}

void	mov_left( t_game *r)
{
	if (r->map[r->n1][r->n2 - 1] == '1')
		return ;
	else if (r->map[r->n1][r->n2 - 1] == 'E' && r->colec_count != 0)
		return ;
	else
	{
		mlx_put_image_to_window(r->mlx, r->win, r->img_b, r->n3, r->n4);
		mlx_put_image_to_window(r->mlx, r->win, r->img_p, r->n3 -= PX, r->n4);
	}
	r->map[r->n1][r->n2] = '0';
	r->n2 -= 1;
	if (r->map[r->n1][r->n2] == 'C')
	{
		mlx_put_image_to_window(r->mlx, r->win, r->img_b, r->n3, r->n4);
		mlx_put_image_to_window(r->mlx, r->win, r->img_p, r->n3, r->n4);
		r->colec_count--;
	}
	if (r->map[r->n1][r->n2] == 'E' && r->colec_count == 0)
	{
		free_map(r);
		exit(0);
	}
	printf("%d\n", r->moving++);
}

void	mov_down( t_game *r)
{
	if (r->map[r->n1 + 1][r->n2] == '1')
		return ;
	else if (r->map[r->n1 + 1][r->n2] == 'E' && r->colec_count != 0)
		return ;
	else
	{
		mlx_put_image_to_window(r->mlx, r->win, r->img_b, r->n3, r->n4);
		mlx_put_image_to_window(r->mlx, r->win, r->img_p, r->n3, r->n4 += PX);
	}
	r->map[r->n1][r->n2] = '0';
	r->n1 += 1;
	if (r->map[r->n1][r->n2] == 'C')
	{
		mlx_put_image_to_window(r->mlx, r->win, r->img_b, r->n3, r->n4);
		mlx_put_image_to_window(r->mlx, r->win, r->img_p, r->n3, r->n4);
		r->colec_count--;
	}
	if (r->map[r->n1][r->n2] == 'E' && r->colec_count == 0)
	{
		free_map(r);
		exit(0);
	}
	printf("%d\n", r->moving++);
}

void	mov_up( t_game *r)
{
	if (r->map[r->n1 - 1][r->n2] == '1')
		return ;
	else if (r->map[r->n1 - 1][r->n2] == 'E' && r->colec_count != 0)
		return ;
	else
	{
		mlx_put_image_to_window(r->mlx, r->win, r->img_b, r->n3, r->n4);
		mlx_put_image_to_window(r->mlx, r->win, r->img_p, r->n3, r->n4 -= PX);
	}
	r->map[r->n1][r->n2] = '0';
	r->n1 -= 1;
	if (r->map[r->n1][r->n2] == 'C')
	{
		mlx_put_image_to_window(r->mlx, r->win, r->img_b, r->n3, r->n4);
		mlx_put_image_to_window(r->mlx, r->win, r->img_p, r->n3, r->n4);
		r->colec_count--;
	}
	if (r->map[r->n1][r->n2] == 'E' && r->colec_count == 0)
	{
		free_map(r);
		exit(0);
	}
	printf("%d\n", r->moving++);
}

int	key_hook(int keycode, t_game *vars)
{
	if (keycode == 53)
	{
		free_map(vars);
		exit(0);
	}
	else if (keycode == 2)
		mov_rihgt(vars);
	else if (keycode == 0)
		mov_left(vars);
	else if (keycode == 1)
		mov_down(vars);
	else if (keycode == 13)
		mov_up(vars);
	return (0);
}
