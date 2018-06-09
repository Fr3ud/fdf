/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavelko <apavelko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:53:00 by apavelko          #+#    #+#             */
/*   Updated: 2018/03/05 20:13:29 by apavelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_hex_to_int(char *hex)
{
	int		result;
	char	tmp;

	result = 0;
	while (*hex)
	{
		tmp = *hex++;
		if (tmp >= '0' && tmp <= '9')
			tmp -= '0';
		else if (tmp >= 'A' && tmp <= 'F')
			tmp = tmp - 'A' + 10;
		else if (tmp >= 'a' && tmp <= 'f')
			tmp = tmp - 'a' + 10;
		result = (result << 4) | tmp;
	}
	return (result);
}
