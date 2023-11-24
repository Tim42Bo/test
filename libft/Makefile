# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 04:06:14 by tbornema          #+#    #+#              #
#    Updated: 2023/10/12 10:42:45 by tbornema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_FILES = ft_atoi.c			\
			ft_bzero.c			\
			ft_calloc.c			\
			ft_isalnum.c		\
			ft_isalpha.c		\
			ft_isascii.c		\
			ft_isdigit.c		\
			ft_isprint.c		\
			ft_itoa.c			\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_memcpy.c			\
			ft_memmove.c		\
			ft_memset.c			\
			ft_putchar_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
			ft_putstr_fd.c		\
			ft_split.c			\
			ft_strchr.c			\
			ft_strrchr.c		\
			ft_strdup.c			\
			ft_striteri.c		\
			ft_strjoin.c		\
			ft_strlcat.c		\
			ft_strlcpy.c		\
			ft_strlen.c			\
			ft_strmapi.c		\
			ft_strncmp.c		\
			ft_strnstr.c		\
			ft_strtrim.c		\
			ft_substr.c			\
			ft_tolower.c		\
			ft_toupper.c		\
			%%.c				\
			%c.c				\
			%d%i.c				\
			%f.c				\
			%f2.c				\
			%p.c				\
			%s.c				\
			%u.c				\
			%x%X.c				\
			ft_hexutils.c		\
			ft_int_to_ascii.c	\
			ft_printf.c			\
			ft_strrev.c			\
			ft_uiint_len.c		\
			ft_uint_to_ascii.c	\
			ft_ulltoa.c			\
			handle.c			\
			putils.c			\
			specifier_skip.c	\
			specifier.c			\
			unknown.c			\
			strncpy.c			\
			ft_numlen.c			\
			safestr.c			\
			countarray.c		\
			safecharstr.c		\
			ft_absolute.c		\
			ft_getmaxint.c		\
			ft_getlowint.c		\
			ft_straddc.c		\

NAME = libft.a

OBJ_DIR = obj/
OBJ = $(OBJ_FILES:.c=.o)
OBJ_PRE = $(addprefix $(OBJ_DIR), $(OBJ))

CC = cc
#CFLAGS = -Wall -Wextra -Werror



$(OBJ_DIR)%.o: %.c libft.h
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling: $<"
	@cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_PRE)
	@ar r $(NAME) $(OBJ_PRE)
	@echo "Libft Done!"

all: $(NAME)

clean:
	rm -f $(OBJ_DIR)/$(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
