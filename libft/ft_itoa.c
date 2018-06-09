/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavelko <apavelko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:19:00 by apavelko          #+#    #+#             */
/*   Updated: 2017/11/11 16:18:34 by apavelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	size_t			f;
	size_t			len;
	long long int	ln;
	char			*str;

	ln = n;
	f = 0;
	len = ft_numlen(ln);
	if (ln < 0)
	{
		f++;
		len++;
		ln *= -1;
	}
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len > f)
	{
		str[--len] = ln % 10 + '0';
		ln /= 10;
	}
	if (f)
		str[0] = '-';
	return (str);
}
