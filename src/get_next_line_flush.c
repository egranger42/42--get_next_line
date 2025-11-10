#include "../inc/get_next_line.h"

static t_node	**get_node_ptr(int fd)
{
	static t_node	*fd_buffers[256];
	if (fd >= 0 && fd < 256)
		return (&fd_buffers[fd]);
	return (NULL);
}

static void	free_buffer_chain(t_node **head)
{
	t_node	*curr;
	t_node	*next;

	if (!head || !*head)
		return ;
	curr = *head;
	while (curr)
	{
		next = curr->next;
		node_free(curr);
		curr = next;
	}
	*head = NULL;
}

void	get_next_line_flush(int fd)
{
	t_node	**node_ptr;
	int		i;

	if (fd == -1)
	{
		i = 0;
		while (i < 256)
		{
			node_ptr = get_node_ptr(i);
			if (node_ptr)
				free_buffer_chain(node_ptr);
			i++;
		}
	}
	else
	{
		node_ptr = get_node_ptr(fd);
		if (node_ptr)
			free_buffer_chain(node_ptr);
	}
}
