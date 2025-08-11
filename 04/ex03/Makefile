# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/08 12:46:46 by jqueijo-          #+#    #+#              #
#    Updated: 2025/08/08 12:57:27 by jqueijo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = amateria

SRC_DIR = ./srcs
OBJ_DIR = ./obj

SRCS = $(SRC_DIR)/AMateria.cpp \
		$(SRC_DIR)/main.cpp

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++98

OBJ = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -fr $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
