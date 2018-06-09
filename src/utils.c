/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavelko <apavelko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:58:00 by apavelko          #+#    #+#             */
/*   Updated: 2018/03/02 16:58:00 by apavelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fdf.h"

int		ft_exit_x(void)
{
	exit(1);
	return (0);
}

double	ft_scale(t_fdf *fdf)
{
	int		x;
	int		y;
	double	scale;

	x = WIDTH > HEIGHT ? HEIGHT : WIDTH;
	y = fdf->map->map_x > fdf->map->map_y ? fdf->map->map_x : fdf->map->map_y;
	scale = x / y * 0.8;
	return (scale);
}
