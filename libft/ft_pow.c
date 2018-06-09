/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavelko <apavelko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:58:00 by apavelko          #+#    #+#             */
/*   Updated: 2017/11/11 17:05:19 by apavelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int x, int n)
{
	int result;
	int i;

	result = 1;
	i = 0;
	while (i < n)
	{
		result *= x;
		i++;
	}
	return (result);
}
