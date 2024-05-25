/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:04:26 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/05 15:36:36 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

int	ft_find_newline(t_gnl_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->str_buffer[i] && i < BUFFER_SIZE)
		{
			if (list->str_buffer[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}

t_gnl_list	*ft_find_last_node(t_gnl_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}

int	ft_line_len(t_gnl_list *list)
{
	int	len;
	int	i;

	if (list == NULL)
		return (0);
	len = 0;
	while (list != NULL)
	{
		i = 0;
		while (list->str_buffer[i] != '\0')
		{
			if (list->str_buffer[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

void	*ft_copy_line(t_gnl_list *list, char *nxt_str)
{
	int	i;
	int	n;

	n = 0;
	while (list != NULL)
	{
		i = 0;
		while (list->str_buffer[i] != '\0')
		{
			if (list->str_buffer[i] == '\n')
			{
				nxt_str[n++] = '\n';
				nxt_str[n] = '\0';
				return (nxt_str);
			}
			nxt_str[n++] = list->str_buffer[i++];
		}
		list = list->next;
	}
	nxt_str[n] = '\0';
	return (nxt_str);
}

void	ft_dealloc(t_gnl_list **list, t_gnl_list *clean_node, char *buffer)
{
	t_gnl_list	*tmp;

	while (*list != NULL)
	{
		tmp = (*list)->next;
		free ((*list)->str_buffer);
		(*list)->str_buffer = NULL;
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node->str_buffer[0] != '\0')
		*list = clean_node;
	else
	{
		free(clean_node);
		clean_node = NULL;
		free(buffer);
		buffer = NULL;
	}
}
