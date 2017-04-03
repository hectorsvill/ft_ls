/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:51:32 by hvillasa          #+#    #+#             */
/*   Updated: 2016/12/24 20:58:11 by hvillasa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*get_fd(int fd)
{
	static t_list	*head;
	t_list			*temp;

	temp = head;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew("\0", 1);
	temp->content_size = fd;
	ft_lstadd(&head, temp);
	return (temp);
}

static void			merge(t_list *node, char const *buff, int size)
{
	char			*temp;

	if (!node->content)
	{
		node->content = ft_strndup(buff, size);
		return ;
	}
	temp = node->content;
	node->content = ft_strjoin(temp, buff);
	free((void*)buff);
}

static int			delim_sp(char *s)
{
	int				i;

	i = 0;
	while (s[i] != 0 && s[i] != '\n')
		i++;
	return (i);
}

int					get_next_line(const int fd, char **line)
{
	int				len;
	int				ret;
	char			*tmp;
	char			buf[BUFF_SIZE];
	t_list			*n;

	len = 0;
	ret = 0;
	IFTRUE((fd < 0 || line == NULL || read(fd, buf, 0) < 0), -1);
	n = get_fd(fd);
	while (!ft_strchr(n->content, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
		merge(n, ft_strndup(buf, ret), ret);
	if (ret < BUFF_SIZE && ft_strlen(n->content) == 0)
	{
		ft_strclr(*line);
		return (0);
	}
	tmp = n->content;
	len = delim_sp(tmp);
	*line = (tmp[len] == '\n') ? ft_strndup(tmp, len) : (ft_strdup(n->content));
	if ((ret == 0 && tmp[len] == 0))
		ft_strclr((char*)(n->content));
	n->content = (tmp[len] == '\n') ? (ft_strdup(n->content + (len + 1))) :
		(n->content + 0);
	return (1);
}
