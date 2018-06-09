/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavelko <apavelko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:37:00 by apavelko          #+#    #+#             */
/*   Updated: 2017/11/11 16:10:55 by apavelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	size_t i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
			ft_putchar_fd(s[i++], fd);
		ft_putchar_fd('\n', fd);
	}
}
