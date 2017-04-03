
LIB = libft/libft.a

CC = gcc -Wall -Wextra -Werror

SRC = main.c

all: $(SRC)
	@make -C libft
	@$(CC) $(SRC) -Iinc $(LIB) 

clean:
	@make clean -C libft
	@rm a.out

fclean: clean
	@make fclean -C libft
