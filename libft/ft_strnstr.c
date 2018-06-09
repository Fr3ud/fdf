/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavelko <apavelko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:59:49 by apavelko          #+#    #+#             */
/*   Updated: 2017/11/04 16:35:06 by apavelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t size;

	i = 0;
	j = 0;
	size = ft_strlen(needle);
	if (!size)
		return ((char *)haystack);
	while (haystack[i] != '\0' && (i + j) < len)
	{
		if (haystack[i + j] == needle[j])
		{
			if (j == size - 1)
				return ((char *)(haystack + i));
			j++;
		}
		else
		{
			i++;
			j = 0;
		}
	}
	return (NULL);
}
