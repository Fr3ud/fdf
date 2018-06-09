/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavelko <apavelko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:16:00 by apavelko          #+#    #+#             */
/*   Updated: 2018/03/02 18:41:57 by apavelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fdf.h"
#include "../libft/libft.h"
#include "../minilibx_macos/mlx.h"

void	ft_info_keys(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 10, 10, 0x0000FF00,
								"MOVE:   UP DOWN LEFT RIGHT");
	mlx_string_put(fdf->mlx, fdf->win, 10, 50, 0x0000FF00,
										"COLOR:  1 2 3 SPACE");
	mlx_string_put(fdf->mlx, fdf->win, 10, 30, 0x0000FF00,
												"ROTATE: WASD");
	mlx_string_put(fdf->mlx, fdf->win, 10, 70, 0x0000FF00, "RESET:  R");
	mlx_string_put(fdf->mlx, fdf->win, 10, 90, 0x0000FF00, "ZOOM:   + -");
}

void	ft_info_coord(t_fdf *fdf)
{
	char *x;
	char *y;
	char *z;
	char *rx;
	char *ry;

	x = ft_itoa(((int)fdf->cam->offset_x - WIDTH / 2));
	y = ft_itoa(((int)fdf->cam->offset_y - HEIGHT / 2));
	rx = ft_itoa(((int)(fdf->cam->x * 20)));
	ry = ft_itoa(((int)(fdf->cam->y * 20)));
	z = ft_itoa(((int)(fdf->cam->z * 10)));
	mlx_string_put(fdf->mlx, fdf->win, WIDTH - 240, 10, 0x0000FF00,
												"X:      Y:      Z:");
	mlx_string_put(fdf->mlx, fdf->win, WIDTH - 210, 10, 0x0000FF00, x);
	free(x);
	mlx_string_put(fdf->mlx, fdf->win, WIDTH - 130, 10, 0x0000FF00, y);
	free(y);
	mlx_string_put(fdf->mlx, fdf->win, WIDTH - 50, 10, 0x0000FF00, z);
	free(z);
	mlx_string_put(fdf->mlx, fdf->win, WIDTH - 170, 30, 0x0000FF00,
														"rX:     rY:");
	mlx_string_put(fdf->mlx, fdf->win, WIDTH - 130, 30, 0x0000FF00, rx);
	free(rx);
	mlx_string_put(fdf->mlx, fdf->win, WIDTH - 50, 30, 0x0000FF00, ry);
	free(ry);
}

void	ft_info(t_fdf *fdf)
{
	ft_info_keys(fdf);
	ft_info_coord(fdf);
}
