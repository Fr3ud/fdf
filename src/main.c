/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavelko <apavelko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:50:00 by apavelko          #+#    #+#             */
/*   Updated: 2018/03/02 17:51:16 by apavelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fdf.h"
#include "../libft/libft.h"
#include "../minilibx_macos/mlx.h"

t_fdf	*ft_fdf_init(char *map)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf *)malloc(sizeof(*fdf))) ||
		!(fdf->map = (t_map *)malloc(sizeof(t_map))) ||
		!(ft_count_x_and_y(fdf, map)) ||
		!(fdf->mlx = mlx_init()) ||
		!(fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "apavelko")) ||
		!(fdf->map->map = (int **)malloc(sizeof(int*) * fdf->map->map_y)) ||
		!(fdf->matrix = (t_vector**)malloc(sizeof(t_vector*) *
														fdf->map->map_y)) ||
		!(fdf->cam = (t_cam *)malloc(sizeof(t_cam))) ||
		!(fdf->img = ft_new_image(fdf)) ||
		!(ft_create_map(fdf, map)))
		return (NULL);
	fdf->map->color1 = 0x00FA35A2;
	fdf->map->color2 = 0x0002D2A4;
	fdf->cam->offset_x = WIDTH / 2;
	fdf->cam->offset_y = HEIGHT / 2;
	fdf->cam->x = 0;
	fdf->cam->y = 0;
	fdf->cam->z = 1;
	fdf->cam->scale = ft_scale(fdf);
	ft_find_depth(fdf);
	return (fdf);
}

int		main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		return (ft_bye("Usage: ./fdf <map>"));
	if ((fdf = ft_fdf_init(argv[1])) == NULL)
		return (0);
	if (!(ft_get_coord(fdf)))
		return (0);
	ft_render(fdf);
	mlx_hook(fdf->win, 2, 5, ft_deal_key, fdf);
	mlx_hook(fdf->win, 17, 1L << 17, ft_exit_x, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
