/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 20:27:40 by sashin            #+#    #+#             */
/*   Updated: 2021/07/07 11:50:11 by sashin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

int	gnl_input_line(char **line, char **stack, char *pt)
{
	char			*temp;

	if (ft_strchr(*stack, '\n') != NULL)
	{
		*pt = '\0';
		*line = ft_strdup(*stack);
		temp = ft_strdup((char *)(pt + 1));
		free(*stack);
		*stack = temp;
	}
	else
	{
		*line = ft_strdup(*stack);
		free(*stack);
		*stack = NULL;
		return (0);
	}
	return (1);
}

void	gnl_strjoin_free(char **stack, char *buf)
{
	char			*temp;

	temp = ft_strjoin(*stack, buf);
	free(*stack);
	*stack = temp;
}

void	get_data(char *pt, int fd, char *buf, char **stack)
{
	int	rd_size;

	rd_size = 0;
	while (1)
	{
		pt = ft_strchr(stack[fd], '\n');
		if (pt != NULL)
			break ;
		rd_size = read(fd, buf, BUFFER_SIZE);
		if (rd_size <= 0)
			break ;
		buf[rd_size] = '\0';
		gnl_strjoin_free(&stack[fd], buf);
	}
}

int	get_next_line(int fd, char **line)
{
	static char		*stack[1024];
	char			*buf;
	char			*pt;
	int				rd_size;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || line == NULL || BUFFER_SIZE < 1 || !buf)
		return (-1);
	if (stack[fd] == NULL)
	{
		rd_size = read(fd, buf, BUFFER_SIZE);
		if (rd_size == -1)
			return (-1);
		buf[rd_size] = '\0';
		stack[fd] = ft_strdup(buf);
	}
	get_data(pt, fd, buf, stack);
	free(buf);
	return (gnl_input_line(line, &stack[fd], pt));
}
