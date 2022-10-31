/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:28:17 by messalih          #+#    #+#             */
/*   Updated: 2022/02/12 20:41:40 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	check_e_d(t_map *m)
{
	if (m->e > 1 || m->e == 0
		|| m->p == 0 || m->p > 1)
	{
		return (0);
	}
	if (m->c == 0)
	{
		return (0);
	}
	else
		return (m->first_line);
}

static	int	check_last_line(char *str, t_map *m)
{
	int	x;

	x = 0;
	m->z = 1;
	m->line = m->len;
	while (m->line-- > 1)
	{
		if (str[m->z] != '1' && str[m->z] != '0'
			&& str[m->z] != 'E' && str[m->z] != 'P'
			&& str[m->z] != 'C')
			return (0);
		m->z++;
	}
	if (m->line_c == 0)
	{
		while (str[x])
		{
			if (str[x] != '1')
				return (0);
			x++;
		}
	}
	return (1);
}

static	int	init_vars(t_map *in, char *ber)
{
	in->i = 0;
	in->line_c = line_count(in->fd, ber) - 1;
	in->line_coun = in->line_c + 1;
	in->fd = open(ber, O_RDONLY);
	if (in->fd == -1)
		return (0);
	in->str = malloc(sizeof(char *) * in->line_c + 1);
	if (in->str == NULL)
		return (0);
	in->str[in->i] = get_next_line(in->fd);
	in->first_line = ft_strlen(in->str[in->i]) - 1;
	in->len = in->first_line - 1;
	in->x = 0;
	while (in->str[in->i][in->x] != '\n')
	{
		if (in->str[in->i][in->x] != '1' || in->str[in->i][in->x] == '\0')
			return (0);
		in->x++;
	}
	in->e = 0;
	in->p = 0;
	in->c = 0;
	return (1);
}

static int	check_midle_line(char *str, t_map *m)
{
	m->r = ft_strlen(str) - 1;
	m->z = 1;
	if (str[0] != '1' || str[m->len] != '1')
		return (0);
	if (m->line_c != 0)
	{
		if (m->first_line != m->r)
			return (0);
	}
	else if (m->line_c == 0)
	{
		m->r += 1;
		if (m->first_line != m->r)
			return (0);
	}
	if (check_last_line(str, m) == 0)
		return (0);
	return (1);
}

int	check_map(t_map *p, char *ber)
{
	if (init_vars(p, ber) == 0)
		return (0);
	while (p->line_c--)
	{
		p->li = p->len;
		p->x = 1;
		p->str[++p->i] = get_next_line(p->fd);
		if (check_midle_line(p->str[p->i], p) == 0)
			return (0);
		while (p->li-- > 1)
		{
			if (p->str[p->i][p->x] == 'E')
				p->e++;
			if (p->str[p->i][p->x] == 'P')
				p->p++;
			if (p->str[p->i][p->x] == 'C')
				p->c++;
			p->x++;
		}
	}
	return (check_e_d(p));
}
