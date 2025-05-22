# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kationg <kationg@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/17 21:27:29 by kationg           #+#    #+#              #
#    Updated: 2025/05/23 02:35:50 by kationg          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(CLIENT) $(SERVER)

CLIENT = client

SERVER = server

CLIENT_FILE = client.c

SERVER_FILE = server.c

INCLUDES = -Iincludes/ -Ilibft/

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)
# -I includes path for the compiler to find header file
# $^ represent all dependencies while $< only the first dependency

$(CLIENT) : $(CLIENT_FILE)
	make -C libft all
	@cc $(CFLAGS) $(INCLUDES) $^ libft/libft.a -o $@

$(SERVER) : $(SERVER_FILE)
	@cc $(CFLAGS) $(INCLUDES) $^ libft/libft.a -o $@

clean : 
	make -C libft clean

fclean : clean
	make -C libft fclean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all bonus clean fclean re
