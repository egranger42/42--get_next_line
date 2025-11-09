/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egranger <egranger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:01:01 by egranger          #+#    #+#             */
/*   Updated: 2025/11/09 10:01:04 by egranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

int	gnl_end(t_gnl_state *state, t_gnl_vars *vars)
{
	char	*temp;

	if (vars->i + 1 >= vars->capacity)
	{
		vars->capacity *= 2;
		temp = realloc(vars->line, vars->capacity);
		if (!temp)
		{
			free(vars->line);
			return (-1);
		}
		vars->line = temp;
	}
	vars->line[vars->i++] = state->buffer[state->pos++];
	if (vars->line[vars->i - 1] == '\n')
	{
		vars->line[vars->i] = '\0';
		return (1);
	}
	return (0);
}
