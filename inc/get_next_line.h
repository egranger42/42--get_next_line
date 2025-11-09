/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egranger <egranger@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:01:36 by egranger          #+#    #+#             */
/*   Updated: 2025/11/09 10:01:38 by egranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define GNL_BUFFER_SIZE 4096

typedef struct s_gnl_state
{
	char	buffer[GNL_BUFFER_SIZE];
	int		pos;
	int		len;
	int		fd;
}	t_gnl_state;

typedef struct s_gnl_vars
{
	char	*line;
	int		i;
	int		capacity;
}	t_gnl_vars;

t_gnl_state	*gnl_get_state(int fd);
t_gnl_vars	gnl_init(int fd, t_gnl_state *state);
int			gnl_read(int fd, t_gnl_state *state, t_gnl_vars *vars);
int			gnl_end(t_gnl_state *state, t_gnl_vars *vars);
char		*get_next_line(int fd);


#endif
