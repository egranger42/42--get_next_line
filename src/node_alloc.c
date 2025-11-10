/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egranger <egranger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:00:00 by egranger          #+#    #+#             */
/*   Updated: 2025/11/10 10:00:00 by egranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

t_node	*node_alloc(size_t capacity)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->buffer = malloc(capacity);
	if (!node->buffer)
		return (free(node), NULL);
	node->capacity = capacity;
	node->offset = 0;
	node->size = 0;
	node->next = NULL;
	return (node);
}
