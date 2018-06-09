/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavelko <apavelko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:30:00 by apavelko          #+#    #+#             */
/*   Updated: 2018/03/02 17:37:11 by apavelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "../includes/fdf.h"
#include "../minilibx_macos/mlx.h"

t_vector	ft_magic(t_vector v, t_fdf *fdf)
{
	double x;

	v.x -= (double)(fdf->map->map_x - 1) / 2.;
	v.y -= (double)(fdf->map->map_y - 1) / 2.;
	v.z -= (double)(fdf->map->depth_min + fdf->map->depth_max) / 2.;
	x = v.x;
	v.z *= fdf->cam->z;
	v.x = cos(fdf->cam->x) * x + sin(fdf->cam->x) * v.z;
	v.z = -sin(fdf->cam->x) * x + cos(fdf->cam->x) * v.z;
	v.y = cos(fdf->cam->y) * v.y - sin(fdf->cam->y) * v.z;
	v.x *= fdf->cam->scale;
	v.y *= fdf->cam->scale;
	v.x += fdf->cam->offset_x;
	v.y += fdf->cam->offset_y;
	return (v);
}

void		ft_get_new_coord(t_fdf *fdf)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < fdf->map->map_y)
	{
		j = 0;
		while (j < fdf->map->map_x)
		{
			fdf->matrix[i][j].x = j;
			fdf->matrix[i][j].y = i;
			fdf->matrix[i][j].z = fdf->map->map[i][j];
			fdf->matrix[i][j].color = ft_lerp(fdf->map->color1,
								fdf->map->color2, ft_lerp_p(fdf->matrix[i][j].z,
									fdf->map->depth_min, fdf->map->depth_max));
			j++;
		}
		i++;
	}
}

int			ft_get_coord(t_fdf *fdf)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < fdf->map->map_y)
	{
		if ((fdf->matrix[i] = (t_vector *)malloc(sizeof(t_vector) *
												fdf->map->map_x)) == NULL)
			return (0);
		j = 0;
		while (j < fdf->map->map_x)
		{
			fdf->matrix[i][j].x = j;
			fdf->matrix[i][j].y = i;
			fdf->matrix[i][j].z = fdf->map->map[i][j];
			fdf->matrix[i][j].color = ft_lerp(fdf->map->color1,
								fdf->map->color2, ft_lerp_p(fdf->matrix[i][j].z,
									fdf->map->depth_min, fdf->map->depth_max));
			j++;
		}
		i++;
	}
	return (1);
}

void		ft_render(t_fdf *fdf)
{
	size_t i;
	size_t j;

	ft_clear_image(fdf->img);
	ft_get_new_coord(fdf);
	i = 0;
	while (i < fdf->map->map_y)
	{
		j = 0;
		while (j < fdf->map->map_x)
		{
			if ((j + 1) < fdf->map->map_x)
				ft_draw_line(ft_magic(fdf->matrix[i][j], fdf),
							ft_magic(fdf->matrix[i][j + 1], fdf), fdf);
			if ((i + 1) < fdf->map->map_y)
				ft_draw_line(ft_magic(fdf->matrix[i][j], fdf),
							ft_magic(fdf->matrix[i + 1][j], fdf), fdf);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->img, 0, 0);
	ft_info(fdf);
}
