
NAME = ft_ls

LIB = libft/libft.a

CC = gcc -Wall -Wextra -Werror

SRC = main.c

all: $(NAME) 

$(NAME): $(SRC) 
	@make -C libft
	@$(CC) $(SRC) -Iinc $(LIB) -o $(NAME) 

clean:
	@make clean -C libft
	@rm a.out

fclean: clean
	@make fclean -C libft
