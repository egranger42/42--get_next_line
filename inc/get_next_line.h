/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egranger <egranger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:01:36 by egranger          #+#    #+#             */
/*   Updated: 2025/11/09 10:01:38 by egranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_node
{
	char			*buffer;
	size_t			offset;
	size_t			size;
	size_t			capacity;
	struct s_node	*next;
}	t_node;

char	*get_next_line(int fd);
void	get_next_line_flush(int fd);

int		find_newline(t_node *start, size_t *line_len);
int		read_into_node(t_node *node, int fd);
char	*extract_line(t_node *start, size_t len);
void	consume_nodes(t_node **start);
int		extend_buffer(t_node **start);

t_node	*node_alloc(size_t capacity);
void	node_free(t_node *node);

#endif
