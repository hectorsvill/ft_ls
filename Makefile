
NAME = ft_ls

LIB = libft/libft.a

CC = gcc -Wall -Wextra -Werror

SRC = ft_ls.c

all: $(NAME) $(SRC)

$(NAME): $(SRC)
	@make -C libft
	@$(CC) $(SRC) -Iinc $(LIB) -o $(NAME)

clean:
	@make clean -C libft

fclean: clean
	@make fclean -C libft
	@rm $(NAME)
