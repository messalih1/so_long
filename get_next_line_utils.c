/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messalih <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:42:20 by messalih          #+#    #+#             */
/*   Updated: 2022/02/12 20:44:43 by messalih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	size_t	c;
	char	*str;
	int		len;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	len = ft_strlen(s1);
	str = (char *)malloc((len + ft_strlen(s2)) * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	while (++i < len)
		str[i] = s1[i];
	while (c < ft_strlen(s2))
		str[i++] = s2[c++];
	str[i] = '\0';
	free(s1);
	return (str);
}

int	line_count(int fd, char *b)
{
	char	*str;
	int		x;

	fd = open(b, O_RDONLY);
	if (fd == -1)
		return (0);
	x = 0;
	str = get_next_line(fd);
	free(str);
	while (str)
	{
		str = get_next_line(fd);
		free(str);
		x++;
	}
	free(str);
	close(fd);
	return (x);
}
