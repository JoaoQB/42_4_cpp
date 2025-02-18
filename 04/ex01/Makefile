# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/18 10:55:39 by jqueijo-          #+#    #+#              #
#    Updated: 2025/02/18 13:48:23 by jqueijo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animalBrain

SRC_DIR = ./srcs
OBJ_DIR = ./objs

SRCS = $(SRC_DIR)/main.cpp \
	$(SRC_DIR)/Animal.cpp \
	$(SRC_DIR)/Cat.cpp \
	$(SRC_DIR)/Dog.cpp \
	$(SRC_DIR)/WrongAnimal.cpp \
	$(SRC_DIR)/WrongCat.cpp \
	$(SRC_DIR)/Brain.cpp

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
