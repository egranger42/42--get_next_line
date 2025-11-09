/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egranger <egranger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:01:09 by egranger          #+#    #+#             */
/*   Updated: 2025/11/09 10:01:11 by egranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

t_gnl_vars	gnl_init(int fd, t_gnl_state *state)
{
	t_gnl_vars	vars;

	(void)fd;
	(void)state;
	vars.line = malloc(10);
	if (!vars.line)
	{
		vars.i = 0;
		vars.capacity = 0;
		return (vars);
	}
	vars.i = 0;
	vars.capacity = 10;
	return (vars);
}
