# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egranger <egranger@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/09 10:01:19 by egranger          #+#    #+#              #
#    Updated: 2025/11/09 10:01:21 by egranger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bin/libgnl.a
BIN_DIR = bin

SRC_DIR = src
OBJ_DIR = o
INC_DIR = inc

SRCS = $(SRC_DIR)/get_next_line.c \
	$(SRC_DIR)/get_next_line_flush.c \
	$(SRC_DIR)/find_newline.c \
	$(SRC_DIR)/read_into_node.c \
	$(SRC_DIR)/extract_line.c \
	$(SRC_DIR)/consume_nodes.c \
	$(SRC_DIR)/extend_buffer.c \
	$(SRC_DIR)/node_alloc.c \
	$(SRC_DIR)/node_free.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I../inc
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	mkdir -p $(BIN_DIR)
	$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
