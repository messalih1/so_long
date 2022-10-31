/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:46:43 by messalih          #+#    #+#             */
/*   Updated: 2022/02/12 20:51:05 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <mlx.h>

void	free_map(t_game *f)
{
	int	i;

	i = f->win_h;
	while (i--)
	{
		free(f->map[i]);
	}
	free(f->map);
}

int	close_win(int keycode)
{
	(void)keycode;
	exit(0);
	return (0);
}

int	check_ex(char *argv)
{
	size_t	len;
	int		i;
	char	*b;

	i = 0;
	len = ft_strlen(argv) - 4;
	b = ".ber";
	while (argv[len])
	{
		if (b[i] != argv[len])
		{
			printf("ERROR");
			return (0);
		}
		i++;
		len++;
	}
	return (1);
}

void	call_fun(t_map *mm, char *arg)
{
	int	x;

	x = line_count(mm->fd, arg);
	while (x--)
		free(mm->str[x]);
	free(mm->str);
}
