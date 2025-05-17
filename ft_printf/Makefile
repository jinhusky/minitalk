NAME = libftprintf.a
LIBFT_PATH = includes/libft/
CC_FLAGS = -Wall -Wextra -Werror -I./includes/

SOURCE = src/ft_printf.c src/ft_putnbr.c src/ft_putstr.c src/ft_putptr.c
OBJECTS = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) 
	ar rc $(NAME) $(OBJECTS) 

%.o: %.c
	cc $(CC_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

