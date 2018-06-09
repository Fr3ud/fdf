/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavelko <apavelko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:38:00 by apavelko          #+#    #+#             */
/*   Updated: 2018/03/02 17:38:00 by apavelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../includes/fdf.h"
#include "../libft/libft.h"

void	ft_find_depth(t_fdf *fdf)
{
	size_t i;
	size_t j;

	fdf->map->depth_max = MIN_INT;
	fdf->map->depth_min = MAX_INT;
	i = 0;
	while (i < fdf->map->map_y)
	{
		j = 0;
		while (j < fdf->map->map_x)
		{
			if (fdf->map->map[i][j] > fdf->map->depth_max)
				fdf->map->depth_max = fdf->map->map[i][j];
			if (fdf->map->map[i][j] < fdf->map->depth_min)
				fdf->map->depth_min = fdf->map->map[i][j];
			j++;
		}
		i++;
	}
}

int		*ft_parse_map(t_fdf *fdf, char **tab)
{
	int *x;
	int *ptr_x;

	x = (int *)malloc(sizeof(*x) * fdf->map->map_x);
	ptr_x = x;
	while (*tab)
		*ptr_x++ = ft_atoi(*tab++);
	return (x);
}

void	ft_free_tab(char **tab)
{
	char **ptr;

	ptr = tab;
	while (*ptr)
		free(*ptr++);
	free(tab);
}

int		ft_create_map(t_fdf *fdf, char *map)
{
	int		fd;
	char	**tab;
	char	*line;
	size_t	i;

	i = 0;
	if ((fd = open(map, O_RDONLY)) < 0)
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		tab = ft_strsplit(line, ' ');
		fdf->map->map[i] = ft_parse_map(fdf, tab);
		ft_free_tab(tab);
		free(line);
		i++;
	}
	close(fd);
	return (1);
}

int		ft_count_x_and_y(t_fdf *fdf, char *map)
{
	int		fd;
	char	*line;
	char	**tab;

	fdf->map->map_x = 0;
	fdf->map->map_y = 0;
	if ((fd = open(map, O_RDONLY)) < 0)
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		if (!fdf->map->map_x)
		{
			tab = ft_strsplit(line, ' ');
			while (tab[fdf->map->map_x])
				fdf->map->map_x++;
		}
		fdf->map->map_y++;
		free(line);
	}
	if (!fdf->map->map_x)
		return (ft_bye("Map error :("));
	ft_free_tab(tab);
	close(fd);
	return (1);
}
