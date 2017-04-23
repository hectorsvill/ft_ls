# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvillasa <hvillasa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/18 18:04:21 by hvillasa          #+#    #+#              #
#    Updated: 2017/04/23 10:20:03 by n                ###   ########.fr        #
#                                                                              #
# **************************************************************************** #




NAME = ft_ls

LIB = libft/libft.a

CC = gcc -Wall -Wextra -Werror

SRC = 	main.c \
		ftls_list.c \
		mergesort_files.c \
		mergesort_dirs.c \
		addto_spec_list.c \
		valid_flags.c \
		recursiveprint.c \
		ls-l.c	\

all: $(NAME) $(SRC)

$(NAME): $(SRC)
	#@make -C libft
	@$(CC) $(SRC) -g libft/libft.a $(LIB) -o $(NAME)

re: $(NAME) $(SRC)

clean:
	#@make clean -C libft

fclean: clean
	#@make fclean -C libft
	@rm $(NAME)
