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
	$(SRC_DIR)/gnl_end.c \
	$(SRC_DIR)/gnl_get_state.c \
	$(SRC_DIR)/gnl_init.c \
	$(SRC_DIR)/gnl_read.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I../inc -I../42--hash/inc
AR = ar rcs
HT_LIB = ../42--hash/libht.a
HT_DIR = ../42--hash

all: $(NAME)

$(NAME): $(OBJS) $(HT_LIB)
	mkdir -p $(BIN_DIR)
	mkdir -p $(OBJ_DIR)/ht_temp
	cd $(OBJ_DIR)/ht_temp && ar x $(HT_LIB)
	$(AR) $(NAME) $(OBJS) $(OBJ_DIR)/ht_temp/*.o
	rm -rf $(OBJ_DIR)/ht_temp

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
