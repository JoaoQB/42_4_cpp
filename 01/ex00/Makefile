# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 13:42:01 by jqueijo-          #+#    #+#              #
#    Updated: 2025/01/10 13:48:17 by jqueijo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

SRC_DIR = ./srcs
OBJ_DIR = ./objs

SRCS = $(SRC_DIR)/main.cpp \
	$(SRC_DIR)/Zombie.cpp \
	$(SRC_DIR)/newZombie.cpp \
	$(SRC_DIR)/randomChump.cpp

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.cpp=.o)))
DEPS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.cpp=.d)))

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
OBJ_CFLAGS = $(CFLAGS) -MMD
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(OBJ_CFLAGS) -c $< -o $@

-include $(DEPS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
