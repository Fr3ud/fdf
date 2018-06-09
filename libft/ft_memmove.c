/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavelko <apavelko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:56:20 by apavelko          #+#    #+#             */
/*   Updated: 2017/11/04 16:19:54 by apavelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dt;
	char	*sc;
	size_t	i;

	dt = (char *)dest;
	sc = (char *)src;
	i = 0;
	if (sc < dt)
	{
		while (n--)
			dt[n] = sc[n];
	}
	else
	{
		while (i < n)
		{
			dt[i] = sc[i];
			i++;
		}
	}
	return (dest);
}
