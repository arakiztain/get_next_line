/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakiztain <arakiztain@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:54:07 by arakiztain        #+#    #+#             */
/*   Updated: 2025/11/10 13:25:35 by arakiztain       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_list	*get_or_create_node(int fd, t_list **head)
{
	t_list	*current;
	t_list	*new_node;

	current = *head;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->fd = fd;
	new_node->content = NULL;
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}

static void	clean_node(int fd, t_list **head)
{
	t_list	*current;
	t_list	*prev;

	current = *head;
	prev = NULL;
	while (current)
	{
		if (current->fd == fd)
		{
			if (prev == NULL)
				*head = current->next;
			else
				prev->next = current->next;
			if (current->content)
				free(current->content);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

static int	read_to_node(int fd, t_list *node)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!(buffer))
		return (-1);
	bytes_read = 1;
	while (!is_line(node->content) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (-1);
		}
		buffer[bytes_read] = '\0';
		node->content = str_join(node->content, buffer);
	}
	free(buffer);
	return (1);
}

char	*get_next_line(int fd)
{
	static t_list	*list_head;
	t_list			*node;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = get_or_create_node(fd, &list_head);
	if (!node)
		return (NULL);
	if (read_to_node(fd, node) < 0)
		return (clean_node(fd, &list_head), NULL);
	line = extract_line(node->content);
	node->content = save_remainder(node->content);
	if (!node->content && !line)
		clean_node(fd, &list_head);
	return (line);
}

/* char	*get_next_line(int fd)
{
	static t_list	*list_head = NULL;
	t_list			*node;
	char			*buffer;
	char			*line;
	int				bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node = get_or_create_node(fd, &list_head);
	if (!node)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (clean_node(fd, &list_head), NULL);
	bytes_read = 1;
	while (!is_line(node->content) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), clean_node(fd, &list_head), NULL);
		buffer[bytes_read] = '\0';
		node->content = str_join(node->content, buffer);
	}
	free(buffer);
	line = extract_line(node->content);
	node->content = save_remainder(node->content);
	if (!node->content && !line)
		clean_node(fd, &list_head);
	return (line);
} */
