#include "../inc/get_next_line.h"

static t_node	**get_node_ptr(int fd)
{
	static t_node	*fd_buffers[256];
	if (fd >= 0 && fd < 256)
		return (&fd_buffers[fd]);
	return (NULL);
}

char	*get_next_line(int fd)
{
	t_node	**start;
	t_node	*last;
	size_t	len;
	char	*line;

	if (!(start = get_node_ptr(fd)))
		return (NULL);
	if (!*start && !(*start = node_alloc(BUFFER_SIZE)))
		return (NULL);
	while (!find_newline(*start, &len))
	{
		if (!extend_buffer(start))
			break ;
		last = *start;
		while (last->next)
			last = last->next;
		if (read_into_node(last, fd) <= 0)
			break ;
	}
	if (len == 0)
		return (consume_nodes(start), NULL);
	line = extract_line(*start, len);
	consume_nodes(start);
	return (line);
}
