# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/17 21:27:29 by kationg           #+#    #+#              #
#    Updated: 2025/05/20 13:11:46 by kationg          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SRC = client.c, server.c

INCLUDES = -Iincludes/ -Ilibft/

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

# -I includes path for the compiler to find header file
# $^ represent all dependencies while $< only the first dependency

$(NAME) : $(OBJ)
	@cc $(CFLAGS) $(INCLUDES) $^ libft/libft.a -o $@

%.o:%.c
	@cc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
