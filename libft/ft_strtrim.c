/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavelko <apavelko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:31:00 by apavelko          #+#    #+#             */
/*   Updated: 2017/11/11 15:50:02 by apavelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i != size)
		while (s[size - 1] == ' ' || s[size - 1] == '\n' || s[size - 1] == '\t')
			size--;
	str = (char *)malloc(sizeof(*str) * (size - i + 1));
	if (str == NULL)
		return (NULL);
	while (i < size)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
