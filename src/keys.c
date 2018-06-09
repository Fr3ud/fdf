/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavelko <apavelko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:19:00 by apavelko          #+#    #+#             */
/*   Updated: 2018/03/02 17:19:00 by apavelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fdf.h"
#include "../minilibx_macos/mlx.h"

void	ft_change_color_key(int key, t_fdf *fdf)
{
	if (key == 18)
	{
		fdf->map->color1 = 0x00FA35A2;
		fdf->map->color2 = 0x0002D2A4;
	}
	else if (key == 19)
	{
		fdf->map->color1 = 0x009DF6E7;
		fdf->map->color2 = 0x00D19CFF;
	}
	else if (key == 20)
	{
		fdf->map->color1 = 0x00E55D82;
		fdf->map->color2 = 0x00409EDB;
	}
	else if (key == 49)
	{
		fdf->map->color1 = fdf->map->color1 ^ fdf->map->color2;
		fdf->map->color2 = fdf->map->color1 ^ fdf->map->color2;
		fdf->map->color1 = fdf->map->color1 ^ fdf->map->color2;
	}
}

void	ft_reset_key(t_fdf *fdf)
{
	fdf->map->color1 = 0x00FA35A2;
	fdf->map->color2 = 0x0002D2A4;
	fdf->cam->offset_x = WIDTH / 2;
	fdf->cam->offset_y = HEIGHT / 2;
	fdf->cam->x = 0;
	fdf->cam->y = 0;
	fdf->cam->z = 0;
	fdf->cam->scale = (HEIGHT + WIDTH) / 42;
}

void	ft_fx_key(int key, t_fdf *fdf)
{
	if (key == 53)
	{
		mlx_destroy_image(fdf->mlx, fdf->img);
		exit(1);
	}
	else if (key == 15)
		ft_reset_key(fdf);
	else if (key == 24)
		fdf->cam->scale *= 1.5;
	else if (key == 27)
		fdf->cam->scale /= 1.5;
	else if (key == 14)
		fdf->cam->z += 0.1;
	else if (key == 12)
		fdf->cam->z -= 0.1;
}

void	ft_rotate_key(int key, t_fdf *fdf)
{
	if (key == 124)
		fdf->cam->offset_x += 5;
	else if (key == 123)
		fdf->cam->offset_x -= 5;
	else if (key == 125)
		fdf->cam->offset_y += 5;
	else if (key == 126)
		fdf->cam->offset_y -= 5;
	else if (key == 2)
		fdf->cam->x += .05;
	else if (key == 0)
		fdf->cam->x -= .05;
	else if (key == 13)
		fdf->cam->y += .05;
	else if (key == 1)
		fdf->cam->y -= .05;
}

int		ft_deal_key(int key, t_fdf *fdf)
{
	ft_rotate_key(key, fdf);
	ft_fx_key(key, fdf);
	ft_change_color_key(key, fdf);
	ft_render(fdf);
	return (0);
}
