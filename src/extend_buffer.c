/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egranger <egranger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:00:00 by egranger          #+#    #+#             */
/*   Updated: 2025/11/10 10:00:00 by egranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

#define MAX_BUFFER 536870912

int	extend_buffer(t_node **start_ptr)
{
	t_node	*last;

	last = *start_ptr;
	while (last->next)
		last = last->next;
	if (last->offset + last->size >= last->capacity)
	{
		if (last->capacity >= MAX_BUFFER)
			return (0);
		last->next = node_alloc(last->capacity * 2);
		return (last->next != NULL);
	}
	return (1);
}
