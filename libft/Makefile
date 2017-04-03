# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvillasa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/08 10:28:09 by hvillasa          #+#    #+#              #
#    Updated: 2017/03/09 16:03:56 by hvillasa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME	= libft.a
CC		= gcc
FLAGS	= -Wall -Wextra -Werror

SRC		= 	src/ft_printf.c \
			src/ft_print.c \
			src/ft_flagc.c \
	  		src/ft_flags.c \
			src/ft_flagls.c \
	  		src/ft_flagi.c \
	  		src/ft_flagi_ut.c \
	  		src/ft_flagu.c \
	  		src/ft_whitesp.c \
	  		src/ft_setAssets.c \
			src/ft_getasset.c \
			libft/ft_strlen.c \
			libft/ft_strdup.c \
			libft/ft_strcpy.c \
			libft/ft_strncpy.c \
			libft/ft_putchar.c \
			libft/ft_putnbr.c \
			libft/ft_putstr.c \
			libft/ft_tolower.c \
			libft/ft_toupper.c \
			libft/ft_isprint.c \
			libft/ft_isascii.c \
			libft/ft_isupper.c \
			libft/ft_islower.c \
			libft/ft_isalpha.c \
			libft/ft_isdigit.c \
			libft/ft_isalnum.c \
			libft/ft_memset.c \
			libft/ft_bzero.c \
			libft/ft_memcpy.c \
			libft/ft_memccpy.c \
			libft/ft_memmove.c \
			libft/ft_memchr.c \
			libft/ft_memcmp.c \
			libft/ft_strcat.c \
			libft/ft_strncat.c \
			libft/ft_strlcat.c \
			libft/ft_strchr.c \
			libft/ft_strrchr.c \
			libft/ft_strcmp.c \
			libft/ft_strncmp.c \
			libft/ft_atoi.c \
			libft/ft_isspace.c \
			libft/ft_strstr.c \
			libft/ft_strequ.c \
			libft/ft_strnequ.c \
			libft/ft_putendl.c \
			libft/ft_putchar_fd.c \
			libft/ft_putstr_fd.c \
			libft/ft_putendl_fd.c \
			libft/ft_putnbr_fd.c \
			libft/ft_strnew.c \
			libft/ft_strclr.c \
			libft/ft_strdel.c \
			libft/ft_strjoin.c \
			libft/ft_memdel.c \
			libft/ft_memalloc.c \
			libft/ft_striter.c \
			libft/ft_striteri.c \
			libft/ft_strmap.c \
			libft/ft_strmapi.c \
			libft/ft_strnstr.c \
			libft/ft_strtrim.c \
			libft/ft_itoa.c \
			libft/ft_strsub.c \
			libft/ft_strsplit.c \
			libft/ft_lstnew.c \
			libft/ft_lstdelone.c \
			libft/ft_lstdel.c \
			libft/ft_lstadd.c \
			libft/ft_lstiter.c \
			libft/ft_lstmap.c \
			libft/ft_swap.c \
			libft/ft_strndup.c \
			libft/ft_putnstr.c \
			libft/ft_intmax_ttoa.c \
			libft/ft_intmax_tlen.c \
			libft/ft_uintmax_ttoa.c \
			libft/ft_itoa_base.c \
			libft/ft_wctomb.c \
			libft/ft_strtouper.c \

OBJ	= 	ft_printf.o \
		ft_print.o \
		ft_flagc.o \
	 	ft_flags.o \
		ft_flagls.o \
	 	ft_flagi.o \
	 	ft_flagi_ut.o \
	 	ft_flagu.o \
	 	ft_whitesp.o \
	 	ft_setAssets.o \
		ft_getasset.o \
		ft_strlen.o \
		ft_strdup.o \
		ft_strcpy.o \
		ft_strncpy.o \
		ft_putchar.o \
		ft_putnbr.o \
		ft_putstr.o \
		ft_tolower.o \
		ft_toupper.o \
		ft_isprint.o \
		ft_isascii.o \
		ft_isupper.o \
		ft_islower.o \
		ft_isalpha.o \
		ft_isdigit.o \
		ft_isalnum.o \
		ft_memset.o \
		ft_bzero.o \
		ft_memcpy.o \
		ft_memccpy.o \
		ft_memmove.o \
		ft_memchr.o \
		ft_memcmp.o \
		ft_strcat.o \
		ft_strncat.o \
		ft_strlcat.o \
		ft_strchr.o \
		ft_strrchr.o \
		ft_strcmp.o \
		ft_strncmp.o \
		ft_atoi.o \
		ft_isspace.o \
		ft_strstr.o \
		ft_strequ.o \
		ft_strnequ.o \
		ft_putendl.o \
		ft_putchar_fd.o \
		ft_putstr_fd.o \
		ft_putendl_fd.o \
		ft_putnbr_fd.o \
		ft_strnew.o \
		ft_strclr.o \
		ft_strdel.o \
		ft_strjoin.o \
		ft_memdel.o \
		ft_memalloc.o \
		ft_striter.o \
		ft_striteri.o \
		ft_strmap.o \
		ft_strmapi.o \
		ft_strnstr.o \
		ft_strtrim.o \
		ft_itoa.o \
		ft_strsub.o \
		ft_strsplit.o \
		ft_lstnew.o \
		ft_lstdelone.o \
		ft_lstdel.o \
		ft_lstadd.o \
		ft_lstiter.o \
		ft_lstmap.o \
		ft_swap.o \
		ft_strndup.o \
		ft_putnstr.o \
		ft_intmax_ttoa.o \
		ft_intmax_tlen.o \
		ft_uintmax_ttoa.o \
		ft_itoa_base.o \
		ft_wctomb.o \
		ft_strtouper.o \

all: $(NAME)

$(NAME): $(SRC)
	@make -C libft/ fclean && make -C libft/
	@$(CC) -c $(FLAGS) $(SRC) -Iinc/
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "libft.a"

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)


re: fclean all
