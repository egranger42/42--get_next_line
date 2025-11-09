/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egranger <egranger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:01:15 by egranger          #+#    #+#             */
/*   Updated: 2025/11/09 10:01:17 by egranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

int	gnl_read(int fd, t_gnl_state *state, t_gnl_vars *vars)
{
	if (state->pos >= state->len)
	{
		state->len = read(fd, state->buffer, GNL_BUFFER_SIZE);
		state->pos = 0;
		if (state->len <= 0)
		{
			if (vars->i > 0)
			{
				vars->line[vars->i] = '\0';
				return (2);
			}
			free(vars->line);
			return (-1);
		}
	}
	return (1);
}
