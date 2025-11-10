/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consume_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egranger <egranger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:00:00 by egranger          #+#    #+#             */
/*   Updated: 2025/11/10 10:00:00 by egranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

void	consume_nodes(t_node **start)
{
	t_node	*curr;

	if (!start || !*start)
		return ;
	curr = *start;
	while (curr && curr->size == 0)
	{
		*start = curr->next;
		node_free(curr);
		curr = *start;
	}
}
