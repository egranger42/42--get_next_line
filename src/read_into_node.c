/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_into_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egranger <egranger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:00:00 by egranger          #+#    #+#             */
/*   Updated: 2025/11/10 10:00:00 by egranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

int	read_into_node(t_node *node, int fd)
{
	ssize_t	bytes;
	size_t	write_pos;

	if (!node)
		return (-1);
	write_pos = node->offset + node->size;
	if (write_pos >= node->capacity)
		return (-1);
	bytes = read(fd, node->buffer + write_pos, node->capacity - write_pos);
	if (bytes > 0)
		node->size += bytes;
	return ((int)bytes);
}
