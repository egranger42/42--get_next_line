/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egranger <egranger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:00:51 by egranger          #+#    #+#             */
/*   Updated: 2025/11/09 10:00:59 by egranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

char *get_next_line(int fd)
{
	t_gnl_state	*state;
	t_gnl_vars	vars;
	int			status;

	state = gnl_get_state(fd);
	if (!state)
		return (NULL);
	vars = gnl_init(fd, state);
	if (!vars.line)
		return (NULL);
	while (1)
	{
		status = gnl_read(fd, state, &vars);
		if (status == 2)
			return (vars.line);
		if (status == -1)
			return (NULL);
		status = gnl_end(state, &vars);
		if (status == 1)
			return (vars.line);
		if (status == -1)
			return (NULL);
	}
}
