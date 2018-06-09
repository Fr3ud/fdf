/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavelko <apavelko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:35:00 by apavelko          #+#    #+#             */
/*   Updated: 2017/11/11 16:13:51 by apavelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*elem;

	if (!lst || !f)
		return (NULL);
	if (!(elem = (t_list *)malloc(sizeof(*elem))))
		return (NULL);
	elem = f(lst);
	elem->next = ft_lstmap(lst->next, f);
	return (elem);
}
