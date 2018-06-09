/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavelko <apavelko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 17:02:00 by apavelko          #+#    #+#             */
/*   Updated: 2018/03/02 17:02:00 by apavelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_lerp_c(int x0, int x1, double p)
{
	if (x0 == x1)
		return (x0);
	return (x0 + (x1 - x0) * p);
}

double	ft_lerp_p(double x, double x0, double x1)
{
	if (x == x0)
		return (0.);
	if (x == x1)
		return (1.);
	return ((x - x0) / (x1 - x0));
}

int		ft_lerp(int color1, int color2, double p)
{
	int r;
	int g;
	int b;

	if (color1 == color2)
		return (color1);
	r = ft_lerp_c((color1 >> 16) & 0xFF, (color2 >> 16) & 0xFF, p);
	g = ft_lerp_c((color1 >> 8) & 0xFF, (color2 >> 8) & 0xFF, p);
	b = ft_lerp_c(color1 & 0xFF, color2 & 0xFF, p);
	return (r << 16 | g << 8 | b);
}
