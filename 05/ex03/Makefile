# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jqueijo- <jqueijo-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 15:55:26 by jqueijo-          #+#    #+#              #
#    Updated: 2025/04/23 15:55:46 by jqueijo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = intern

SRC_DIR = ./srcs
OBJ_DIR = ./objs

SRCS = $(SRC_DIR)/main.cpp \
	$(SRC_DIR)/Bureaucrat.cpp \
	$(SRC_DIR)/AForm.cpp \
	$(SRC_DIR)/ShrubberyCreationForm.cpp \
	$(SRC_DIR)/RobotomyRequestForm.cpp \
	$(SRC_DIR)/PresidentialPardonForm.cpp \
	$(SRC_DIR)/Intern.cpp

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
