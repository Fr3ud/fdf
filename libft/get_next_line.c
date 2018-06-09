/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavelko <apavelko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:38:00 by apavelko          #+#    #+#             */
/*   Updated: 2017/12/21 13:38:00 by apavelko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

t_list	*get_elem(int fd, t_list **head)
{
	t_list *ptr;

	ptr = *head;
	while (ptr && (int)ptr->content_size != fd)
		ptr = ptr->next;
	return (ptr);
}

int		get_more(int fd, char *buf, t_list **head)
{
	t_list	*ptr;
	char	*str;

	if ((ptr = get_elem(fd, head)) == NULL)
	{
		ptr = ft_lstnew(buf, ft_strlen(buf) + 1);
		ptr->content_size = fd;
		ft_lstadd(head, ptr);
	}
	else
	{
		str = ft_strjoin(ptr->content, buf);
		free(ptr->content);
		ptr->content = str;
	}
	if (ft_strchr(ptr->content, '\n'))
		return (1);
	return (0);
}

char	*get_line(int fd, t_list **head)
{
	t_list	*ptr;
	char	*point;
	char	*tmp;
	char	*str;
	int		len;

	if (!(ptr = get_elem(fd, head)) || !ptr->content)
		return (NULL);
	tmp = ptr->content;
	if ((point = ft_strchr(ptr->content, '\n')))
	{
		len = point - (char*)ptr->content;
		str = ft_strnew(len);
		ft_strncpy(str, ptr->content, len);
		ptr->content = *(++point) ? ft_strdup(point) : NULL;
	}
	else
	{
		if (!(str = ft_strdup(ptr->content)))
			return (NULL);
		ptr->content = NULL;
		ptr->content_size = 0;
	}
	free(tmp);
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*head;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (ret < 0 || fd < 0 || !line)
			return (-1);
		buf[ret] = '\0';
		if (get_more(fd, buf, &head))
		{
			*line = get_line(fd, &head);
			return (1);
		}
	}
	if ((*line = get_line(fd, &head)))
		return (1);
	return (0);
}
