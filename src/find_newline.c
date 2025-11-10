/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_newline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egranger <egranger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:00:00 by egranger          #+#    #+#             */
/*   Updated: 2025/11/10 10:00:00 by egranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

int	find_newline(t_node *start, size_t *line_len)
{
	t_node	*curr;
	size_t	i;
	size_t	total;

	total = 0;
	curr = start;
	while (curr)
	{
		i = 0;
		while (i < curr->size)
		{
			if (curr->buffer[curr->offset + i] == '\n')
				return (*line_len = total + i + 1, 1);
			i++;
		}
		total += curr->size;
		curr = curr->next;
	}
	return (*line_len = total, 0);
}
