/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavelko <apavelko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:21:00 by apavelko          #+#    #+#             */
/*   Updated: 2017/11/11 15:52:20 by apavelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	words;
	char	**arr;
	char	*parr;

	if (!s)
		return (NULL);
	i = 0;
	words = ft_w_count(s, c);
	if (!(arr = (char **)malloc(sizeof(*arr) * (words + 1))))
		return (NULL);
	while (i < words)
	{
		while (*s == c)
			s++;
		if (!(arr[i] = (char *)malloc(sizeof(**arr) * (ft_c_count(s, c) + 1))))
			return (NULL);
		parr = arr[i];
		while (*s != c && *s != '\0')
			*parr++ = *s++;
		*parr = '\0';
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
