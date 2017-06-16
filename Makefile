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

PF_SRCS = ./srcs/ft_printf
LIB_SRCS = ./srcs/libft
FTLS_SRCS = ./srcs
HEADER = -I ./inc

LIBFT =		ft_strlen.o \
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
			get_next_line.o \
			ft_strndup.o \
			ft_putnstr.o \
			ft_intmax_ttoa.o \
			ft_intmax_tlen.o \
			ft_itoa_base.o \
			ft_uintmax_ttoa.o \
			ft_wctomb.o \
			ft_strtouper.o \
			ft_lstfree.o \
			ft_lstprint.o \
			ft_abs.o \

FT_PRINTF =	ft_flagc.o \
			ft_flagi.o \
			ft_flagi_ut.o \
			ft_flagls.o \
			ft_flags.o \
			ft_flagu.o \
			ft_getasset.o \
			ft_print.o \
			ft_printf.o \
			ft_setAssets.o \
			ft_whitesp.o \

CC = gcc -Wall -Wextra -Werror

FT_LS =	main.o \

COMPILED = $(LIBFT) $(FT_PRINTF) $(FT_LS)

all: $(NAME)

$(NAME): $(COMPILED)
	@$(CC) -o $(NAME) $(COMPILED)
	@echo "Made" $(NAME)

$(LIBFT): %.o: $(LIB_SRCS)/%.c
	@$(CC) -c $(HEADER) $< -o $@

$(FT_PRINTF): %.o: $(PF_SRCS)/%.c
	@$(CC) -c $(HEADER) $< -o $@

$(FT_LS): %.o: $(FTLS_SRCS)/%.c
	@$(CC) -c $(HEADER) $< -o $@

re: fclean all

clean:
	@/bin/rm -rf $(COMPILED)
	@echo "Cleaned" $(NAME)

fclean: clean
	@rm $(NAME)
	@echo "Fcleaned" $(NAME)
