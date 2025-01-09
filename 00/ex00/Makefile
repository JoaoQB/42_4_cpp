# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/06 13:42:01 by jqueijo-          #+#    #+#              #
#    Updated: 2025/01/09 16:16:57 by jqueijo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRC = ./srcs/megaphone.cpp

OBJ = $(SRC:%.cpp=%.o)

CCXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

all: $(NAME)

$(NAME): $(OBJ)
	$(CCXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
