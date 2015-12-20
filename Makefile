NAME=alum1

SRC=main.c game.c input.c

OBJ= $(SRC:.c=.o)

LIB = libft/libft.a

INCLUDE=-I./ -I./libft

FLAGS=-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	gcc -L./libft -lft $(OBJ) -o $(NAME)

$(OBJ):
	gcc $(FLAGS) -c $(SRC) $(INCLUDE) -g

$(LIB):
	make -C libft/

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
