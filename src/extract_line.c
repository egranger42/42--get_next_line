/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egranger <egranger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:00:00 by egranger          #+#    #+#             */
/*   Updated: 2025/11/10 10:00:00 by egranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"
#include "../../inc/libft.h"

char	*extract_line(t_node *start, size_t len)
{
	char	*line;
	size_t	to_copy;
	size_t	pos;

	if (!start || len == 0)
		return (NULL);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	pos = 0;
	while (start && pos < len)
	{
		to_copy = (len - pos < start->size) ? len - pos : start->size;
		if (to_copy > 0)
			ft_memcpy(line + pos, start->buffer + start->offset, to_copy);
		start->offset += to_copy;
		start->size -= to_copy;
		pos += to_copy;
		start = start->next;
	}
	return (line[pos] = '\0', line);
}
