/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavelko <apavelko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:30:28 by apavelko          #+#    #+#             */
/*   Updated: 2017/11/04 16:27:11 by apavelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t k;
	size_t size;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	k = 0;
	size = dstsize - i - 1;
	if (dstsize <= i)
		j += dstsize;
	else
	{
		j += i;
		while (src[k] != '\0' && k < size)
		{
			dst[i] = src[k];
			i++;
			k++;
		}
		dst[i] = '\0';
	}
	return (j);
}
