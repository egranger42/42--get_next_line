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

static t_ht	*g_table = NULL;
static int	g_initialized = 0;

static uint64_t	hash_fd(const void *key)
{
	return ((uintptr_t)key * 2654435761UL);
}

static int	cmp_fd(const void *key1, const void *key2)
{
	return ((intptr_t)key1 != (intptr_t)key2);
}

static void	init_states(void)
{
	g_table = ht_create(16, hash_fd, cmp_fd);
	if (g_table)
		g_initialized = 1;
}

t_gnl_state	*gnl_get_state(int fd)
{
	t_gnl_state	*state;
	t_ht_status	status;

	if (fd < 0)
		return (NULL);
	if (!g_initialized)
		init_states();
	if (!g_table)
		return (NULL);
	status = ht_get(g_table, (void *)(uintptr_t)fd, (void **)&state);
	if (status == HT_SUCCESS)
		return (state);
	state = malloc(sizeof(t_gnl_state));
	if (!state)
		return (NULL);
	state->pos = 0;
	state->len = 0;
	state->fd = fd;
	if (ht_add(g_table, (void *)(uintptr_t)fd, state) != HT_SUCCESS)
	{
		free(state);
		return (NULL);
	}
	return (state);
}
