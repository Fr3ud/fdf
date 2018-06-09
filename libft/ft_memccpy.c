/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavelko <apavelko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:50:25 by apavelko          #+#    #+#             */
/*   Updated: 2017/11/04 16:17:47 by apavelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*dt;
	const unsigned char		*sc;

	dt = (unsigned char *)dst;
	sc = (unsigned char *)src;
	while (n--)
	{
		if (*sc == (unsigned char)c)
		{
			*dt++ = *sc++;
			return (dt);
		}
		*dt++ = *sc++;
	}
	return (NULL);
}
