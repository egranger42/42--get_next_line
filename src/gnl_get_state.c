/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_get_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egranger <egranger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:01:05 by egranger          #+#    #+#             */
/*   Updated: 2025/11/09 10:01:08 by egranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

#define MAX_FDS 512

static t_gnl_state	g_states[MAX_FDS];
static int			g_initialized = 0;

static void	init_states(void)
{
	int	i;

	i = 0;
	while (i < MAX_FDS)
	{
		g_states[i].pos = 0;
		g_states[i].len = 0;
		g_states[i].fd = -1;
		i++;
	}
	g_initialized = 1;
}

t_gnl_state	*gnl_get_state(int fd)
{
	int	index;

	if (fd < 0)
		return (NULL);
	if (!g_initialized)
		init_states();
	index = fd % MAX_FDS;
	if (g_states[index].fd != fd)
	{
		g_states[index].pos = 0;
		g_states[index].len = 0;
		g_states[index].fd = fd;
	}
	return (&g_states[index]);
}
