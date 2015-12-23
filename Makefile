NAME=alum1

SRC=main.c game.c input.c

OBJ= $(SRC:.c=.o)

LIB = libft/libft.a

INCLUDE=-I./ -I./libft

FLAGS=-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@make -C libft/ re
	@gcc -L./libft -lft $(OBJ) -o $(NAME)

$(OBJ):
	@gcc $(FLAGS) -c $(SRC) $(INCLUDE)

$(LIB):
	@make -C libft/

clean:
	@make -C libft/ clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all
