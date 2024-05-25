/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:48:49 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/05 15:50:42 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_gnl_list
{
	char				*str_buffer;
	struct s_gnl_list	*next;
}					t_gnl_list;

int			ft_line_len(t_gnl_list *list);
int			ft_find_newline(t_gnl_list *list);
char		*get_next_line(int fd);
char		*ft_get_line(t_gnl_list **list);
void		ft_tideup_list(t_gnl_list **list);
void		*ft_copy_line(t_gnl_list *list, char *nxt_str);
void		ft_add_node(t_gnl_list **list, char *buffer);
void		ft_create_list(t_gnl_list **list, int fd);
void		ft_dealloc(t_gnl_list **list, t_gnl_list *clean_node, char *buffer);
t_gnl_list	*ft_find_last_node(t_gnl_list *list);

#endif