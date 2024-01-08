# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/01 10:12:32 by melfersi          #+#    #+#              #
#    Updated: 2024/01/08 11:34:23 by melfersi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#______command and their flags______#
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar -crs
INCLUDES = includes

#______diractories______#
OBJ_DIR = obj
#BDIR_OB = bns_obj
SRC_DIR  = src
#BNS_DIR = bonus
INCLUDES = includes
LIB_INCLUDES = libft/includes

#______file names______#
FIlES = main.c operation.c

#BONUS_FIlES = <file name> ...

#atterns subs
SOURCES = $(FIlES:%.c=$(SRC_DIR)/%.c)

#BONUS_SOURCES = $(BONUS_FIlES:ft_%.c=$(BNS_DIR)/ft_%.c)

OBJECTS = $(SOURCES:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

#BONUS_OBJECTS = $(BONUS_SOURCES:$(BNS_DIR)%.c=$(BDIR_OB)%.o)

# static library name
NAME = push_swap
LIB = libft

#______________Rules______________#

$(NAME):$(OBJECTS) $(LIB)/libft.a
	$(CC) $^ -I$(INCLUDES) -I$(LIB_INCLUDES) -o $@

re: fclean all

all: $(NAME) bonus

# impicit rule for mandatory
$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -I$(INCLUDES) -I$(LIB_INCLUDES) -o $@

$(LIB)/%.a:
	$(MAKE) -C $(LIB)

# impicit rule for bonus
# $(BDIR_OB)/%.o:$(BNS_DIR)/%.c
# 	@mkdir -p $(BDIR_OB)
# 	$(CC) $(CFLAGS) -c $< -I$(INCLUDES) -o $@
# 	$(AR) $(NAME) $@

#______cleaning______#
clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIB) fclean
#	$(RM) $(BDIR_OB)

fclean: clean
	$(RM) $(NAME)

.PHONY: clean
