/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavelko <apavelko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:21:10 by apavelko          #+#    #+#             */
/*   Updated: 2017/11/02 15:18:47 by apavelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *ps;

	ps = s;
	while (n--)
		if (*ps++ == (unsigned char)c)
			return ((unsigned char*)--ps);
	return (NULL);
}
