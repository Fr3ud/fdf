/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavelko <apavelko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:06:00 by apavelko          #+#    #+#             */
/*   Updated: 2018/03/02 17:06:00 by apavelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/fdf.h"
#include "../libft/libft.h"

void	ft_swap_doubles(double *x, double *y)
{
	double tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int		ft_dx_error(double y0, double y1, double dx, int *error)
{
	*error += fabs(y1 - y0) * 2;
	if (*error > dx)
	{
		*error -= dx * 2;
		return (y1 > y0 ? 1 : -1);
	}
	return (0);
}

int		ft_steep(t_vector *v0, t_vector *v1)
{
	int steep;

	steep = 0;
	if (fabs(v0->x - v1->x) < fabs(v0->y - v1->y))
	{
		ft_swap_doubles(&v0->x, &v0->y);
		ft_swap_doubles(&v1->x, &v1->y);
		steep = 1;
	}
	if (v0->x > v1->x)
	{
		ft_swap_doubles(&v0->x, &v1->x);
		ft_swap_doubles(&v0->y, &v1->y);
		ft_swap(&v0->color, &v1->color);
	}
	return (steep);
}

void	ft_draw_line(t_vector v0, t_vector v1, t_fdf *fdf)
{
	int		steep;
	int		error;
	double	dx;
	double	x;
	double	y;

	steep = ft_steep(&v0, &v1);
	error = 0;
	dx = v1.x - v0.x;
	x = v0.x;
	y = v0.y;
	while (x <= v1.x)
	{
		if (steep)
			ft_putpixel(fdf->img, (int)y, (int)x,
						ft_lerp(v0.color, v1.color, ft_lerp_p(x, v0.x, v1.x)));
		else
			ft_putpixel(fdf->img, (int)x, (int)y,
						ft_lerp(v0.color, v1.color, ft_lerp_p(x, v0.x, v1.x)));
		y += ft_dx_error(v0.y, v1.y, dx, &error);
		x++;
	}
}
