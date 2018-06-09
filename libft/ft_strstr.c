/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavelko <apavelko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:55:48 by apavelko          #+#    #+#             */
/*   Updated: 2017/11/04 16:13:38 by apavelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;
	size_t size;

	i = 0;
	j = 0;
	size = ft_strlen(needle);
	if (!size)
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		if (haystack[i + j] == needle[j])
		{
			if (j == size - 1)
				return ((char *)(haystack + i));
			j++;
		}
		else
		{
			j = 0;
			i++;
		}
	}
	return (NULL);
}
