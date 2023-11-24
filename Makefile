# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbornema <tbornema@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/24 09:33:17 by tbornema          #+#    #+#              #
#    Updated: 2023/11/24 12:43:39 by tbornema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
SRC_DIR = src
OBJ_DIR = obj
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
RM	= rm -f
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -g
MLXFLAGS = -L./minilibx-linux -lmlx -lXext -lX11
INCS	= -I ./libft -I ./minilibx-linux
LIBFT	= -Llibft -lft
VALGRIND = valgrind --leak-check=full --track-origins=yes

${OBJ_DIR}/%.o: $(SRC_DIR)/%.c include/fractol.h | $(OBJ_DIR)
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

${NAME}: runlibft $(OBJ)
	@${CC} ${OBJ} ${CFLAGS} ${LIBFT} ${MLXFLAGS} -o $@
	@echo "Compiling Done!"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

ignore: runlibft $(OBJ)
	${CC} $(OBJ) $(CFLAGS) ${LIBFT} -o ${NAME}

all: ${NAME}

clean:
	${RM} $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@make -C libft fclean

re: fclean all

runlibft:
	@${MAKE} -C libft -e

run:
	./$(NAME) ${GEN}

runmem:
	@${VALGRIND} ./$(NAME) 

norm:
	norminette -R CheckForbiddenSourceHeader ${SRC_FILES}
	norminette -R CheckDefine ${INCS}

.PHONY: all re clean fclean