/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavelko <apavelko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:52:00 by apavelko          #+#    #+#             */
/*   Updated: 2018/03/02 16:52:00 by apavelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include <string.h>

# define WIDTH 700
# define HEIGHT 700

typedef struct	s_map
{
	int 		**map;
	size_t 		map_x;
	size_t 		map_y;
	int 		color1;
	int 		color2;
	double 		depth_max;
	double 		depth_min;
}				t_map;

typedef struct 	s_cam
{
	double x;
	double y;
	double z;
	double offset_x;
	double offset_y;
	double scale;
}				t_cam;

typedef struct	s_img
{
	void *img;
	char *ptr;
	int bpp;
	int size_line;
	int endian;
}				t_img;

typedef struct	s_vector
{
	double x;
	double y;
	double z;
	int color;
}				t_vector;

typedef struct 	s_fdf
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_vector	**matrix;
	t_cam		*cam;
	t_img		*img;
}				t_fdf;

t_vector	ft_magic(t_vector v, t_fdf *fdf);
void		ft_render(t_fdf *fdf);
void		ft_get_new_coord(t_fdf *fdf);
int			ft_get_coord(t_fdf *fdf);
void	ft_find_depth(t_fdf *fdf);
int		*ft_parse_map(t_fdf *fdf, char **tab);
void	ft_free_tab(char **tab);
int		ft_create_map(t_fdf *fdf, char *map);
int		ft_count_x_and_y(t_fdf *fdf, char *map);
t_img	*ft_new_image(t_fdf *fdf);
void	ft_putpixel(t_img *img, int x, int y, int color);
void	ft_clear_image(t_img *image);
void	ft_draw_line(t_vector v0, t_vector v1, t_fdf *fdf);
int		ft_steep(t_vector *v0, t_vector *v1);
int		ft_dx_error(double y0, double y1, double dx, int *error);
void	ft_swap_doubles(double *x, double *y);
double	ft_lerp_p(double x, double x0, double x1);
int		ft_lerp_c(int x0, int x1, double p);
int		ft_lerp(int color1, int color2, double p);
int		ft_deal_key(int key, t_fdf *fdf);
void	ft_rotate_key(int key, t_fdf *fdf);
void	ft_fx_key(int key, t_fdf *fdf);
void	ft_reset_key(t_fdf *fdf);
void	ft_change_color_key(int key, t_fdf *fdf);
void	ft_info_coord(t_fdf *fdf);
void	ft_info_keys(t_fdf *fdf);
void	ft_info(t_fdf *fdf);
double	ft_scale(t_fdf *fdf);
int 	ft_exit_x(void);

#endif
