NAME = push_swap.a

SRC = push_swap.c operations.c utils.c

OBJS := $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ make -C lib
	@ cp lib/libft.a .
	@ mv libft.a $(NAME)
	@ ar -rcs $(NAME) $(OBJS)

.c.o:
	@ cc -Wall -Wextra -Werror -c $< -o $@

clean:
	@ rm -f $(OBJS)
	@ make clean -C lib

fclean: clean
	@ rm -f $(NAME)
	@ make fclean -C lib

re: fclean all

.PHONY: all clean fclean re
