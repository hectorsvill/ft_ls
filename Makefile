
NAME = ft_ls

LIB = libft/libft.a

CC = gcc -Wall -Wextra -Werror

SRC = 	main.c \
		merge_sort.c \

all: $(NAME) $(SRC)

$(NAME): $(SRC)
	#@make -C libft
	@$(CC) $(SRC) libft/libft.a $(LIB) -o $(NAME)

clean:
	#@make clean -C libft

fclean: clean
	#@make fclean -C libft
	@rm $(NAME)
