NAME = push_swap

LIB = libft.a

SRC = push_swap.c operations.c utils.c sort.c

OBJS := $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ make -C lib
	@ cp lib/$(LIB) .
	@ cc -Wall -Wextra -Werror $(OBJS) $(LIB) -o $(NAME)

.c.o:
	@ cc -Wall -Wextra -Werror -c $< -o $@

clean:
	@ rm -f $(OBJS)
	@ make clean -C lib

fclean: clean
	@ rm -f $(LIB)
	@ rm -f push_swap
	@ make fclean -C lib

re: fclean all

.PHONY: all clean fclean re
