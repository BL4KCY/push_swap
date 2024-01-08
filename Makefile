# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 10:21:19 by melfersi          #+#    #+#              #
#    Updated: 2024/01/07 14:28:57 by melfersi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melfersi <melfersi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 12:49:34 by melfersi          #+#    #+#              #
#    Updated: 2023/12/15 11:08:54 by melfersi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

#diractories
INCLUDES = libft/includes

SRC = main.c

OBJ = $(SRC:.c=.o)
OBJ_DIR = obj

$(NAME):$(OBJ)
	@$(MAKE) -C libft libft.a > /dev/null
	$(CC) $(CFLAGS) -I$(INCLUDES) $(OBJ_DIR)/$^ libft/libft.a -o $@
%.o:%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $^ -o obj/$@

clean:
	$(RM) $(OBJ_DIR)
	@$(MAKE) -C libft clean > /dev/null

fclean:clean
	$(RM) $(NAME)
	@$(MAKE) -C libft fclean > /dev/null

all:$(NAME)

re:fclean all
