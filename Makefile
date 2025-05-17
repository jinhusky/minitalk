# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/17 21:27:29 by kationg           #+#    #+#              #
#    Updated: 2025/05/17 22:23:38 by kationg          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SRC = 

INCLUDES = -Iincludes/ -Ilibft/

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

# -I includes path for the compiler to find header file
# $^ represent all dependencies while $< only the first dependency

$(NAME) : $(OBJ)
	@cc $(CFLAGS) $(INCLUDES) $^ -o $@

%.o:%.c
	@cc $(CFLAGS) $(INCLUDES) $^ -c $< -o $@

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
