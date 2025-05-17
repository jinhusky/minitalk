NAME = get_next_line.a

SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Wextra -Werror

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	cc  -o $@ -c $? $(CFLAG) 

all: $(NAME)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: clean fclean re make 
	


