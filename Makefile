# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alban <alban@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/21 17:25:48 by pcalime           #+#    #+#              #
#    Updated: 2016/04/19 11:40:49 by atrang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c ft_draw_line.c ft_parse.c ft_ratio.c ft_draw_fdf.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc $(OBJ) -o $(NAME) -lft -L ./libft -framework OpenGl -lmlx -framework AppKit

%.o:%.c
	gcc -c $< -o $@ -Iincludes
clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all
