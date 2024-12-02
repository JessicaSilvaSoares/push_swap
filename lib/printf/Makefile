NAME = printf.a

SRC = ft_printf.c print_char.c print_str.c print_pointer.c print_nbr.c print_unsigned.c \
	print_hex.c print_uns_long_hex.c

OBJS := $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ ar -rcs $(NAME) $(OBJS)

.c.o:
	@ cc -Wall -Wextra -Werror -c $< -o $@

clean:
	@ rm -f $(OBJS)

fclean: clean
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re