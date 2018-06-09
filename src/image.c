/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavelko <apavelko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:11:00 by apavelko          #+#    #+#             */
/*   Updated: 2018/03/02 18:40:03 by apavelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/fdf.h"
#include "../libft/libft.h"
#include "../minilibx_macos/mlx.h"

void	ft_clear_image(t_img *image)
{
	ft_bzero(image->ptr, WIDTH * HEIGHT * image->bpp);
}

void	ft_putpixel(t_img *img, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		*(int *)(img->ptr + ((x + y * WIDTH) * img->bpp)) = color;
}

t_img	*ft_new_image(t_fdf *fdf)
{
	t_img *image;

	if ((image = (t_img *)malloc(sizeof(t_img))) == NULL)
		return (NULL);
	image->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	image->ptr = mlx_get_data_addr(image->img, &image->bpp,
								&image->size_line, &image->endian);
	image->bpp /= 8;
	return (image);
}
