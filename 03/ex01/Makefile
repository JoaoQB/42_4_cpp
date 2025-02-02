# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 13:42:01 by jqueijo-          #+#    #+#              #
#    Updated: 2025/02/01 20:05:07 by jqueijo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = clapTrap

SRC_DIR = ./srcs
OBJ_DIR = ./objs

SRCS = $(SRC_DIR)/main.cpp \
	$(SRC_DIR)/ClapTrap.cpp \
	$(SRC_DIR)/ScavTrap.cpp

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.cpp=.o)))
DEPS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.cpp=.d)))

CCXX = c++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98
OBJ_CFLAGS = $(CXXFLAGS) -MMD
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CCXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CCXX) $(OBJ_CFLAGS) -c $< -o $@

-include $(DEPS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
