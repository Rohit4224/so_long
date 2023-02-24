/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_m.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:42:38 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/02/24 19:19:09 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <fcntl.h>
#include <unistd.h>

int	file_linecount(char *file)
{
	int		linecount;
	int		fd;
	int		readcount;
	char	c;

	fd = open(file, O_RDONLY);
	if (fd == 0)
		return (-1);
	linecount = 1;
	while (TRUE)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	close (fd);
	return (linecount);
}

char	**alloc_columns(char *file)
{
	char	**map;
	int		line_count;

	line_count = file_linecount(file);
	if (line_count <= 0)
		return (null_error("Error, File may not exist"));
	map = malloc(sizeof(char *) * line_count + 1);
	if (map == NULL)
		return (null_error("malloc error"));
	return (map);
}

char	**read_m(char *file)
{
	char	**map;
	int		fd;
	int		i;

	map = alloc_columns(file);
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &map[i]) != '\0')
	{
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
