# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emuckens <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/20 17:52:27 by emuckens          #+#    #+#              #
#    Updated: 2018/05/21 17:23:54 by emuckens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = $(addprefix srcs/, main.c init_and_free.c getmap.c plot.c image.c matrices_trans.c matrices_scale.c matrices_rot.c matrices_center.c apply_transformation.c color.c menu_txt.c deal_key.c window.c default.c getpoints.c setextremes.c errors.c)

BIN = $(SRC:.c=.o)

HEAD = includes/fdf.h
HEADDIR = includes

LIBFT = libft/libft.a
LIBFTDIR = libft/
MLXDIR = /usr/local

FLAGS = -Wall -Werror -Wextra
FSANI = -g -fsanitize=address
FRAMEWORKS = -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all:
	@make -j -s -C $(LIBFTDIR)
	@make -s $(NAME)


$(NAME): $(BIN) $(HEAD) $(LIBFT) Makefile
	@echo "building $(NAME)..."
	@gcc $(FLAGS) -o $(NAME) $(BIN) -lmlx -L $(MLXDIR)/lib -lft -L $(LIBFTDIR) $(FRAMEWORKS)
	@echo "$(NAME) READY ! Enjoy :)"

$(LIBFT):
	@make -j -s -C $(LIBFTDIR)

%.o: %.c
	@echo "$(NAME) : generating $@"
	@gcc -I $(HEADDIR) -I $(LIBFTDIR)/includes $(FLAGS) -o $@ -c $^

clean:
	@echo "cleaning $(NAME) binaries..."
	@rm -f $(BIN)
	@make clean -C $(LIBFTDIR)
	@echo "Binaries removed from all folders."

fclean: clean
	@echo "cleaning $(NAME) executable..."
	@rm -f $(NAME)
	@echo "cleaning $(LIBFT) executable..."
	@rm -f $(LIBFT)
	@echo "All directories now clean."

re:
	@make fclean
	@make all


##	@echo "check if need to rebuild $(LIBFT)"
##	@make -C $(LIBFTDIR)

