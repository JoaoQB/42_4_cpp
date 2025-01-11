# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/11 11:42:41 by jqueijo-          #+#    #+#              #
#    Updated: 2025/01/11 11:53:37 by jqueijo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = hiBrain

SRC = ./main.cpp

OBJ = $(SRC:%.cpp=%.o)

CCXX = c++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CCXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

