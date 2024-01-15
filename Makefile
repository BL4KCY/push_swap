#______command and their flags______#
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar -crs
INCLUDES = includes

#______directories______#
OBJ_DIR = obj
SRC_DIR = src
INCLUDES = includes
LIB_INCLUDES = libft/includes

#______file names______#
FILES = init_nodes.c main.c operation.c sort_utils.c sort.c stacks_init.c utils.c
#operation.c actions.c stacks_init.c

#______patterns and substitutions______#
SOURCES = $(FILES:%.c=$(SRC_DIR)/%.c)
OBJECTS = $(SOURCES:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

#______static library name______#
NAME = push_swap
LIB = libft

#______________Rules______________#

$(NAME): $(OBJECTS) $(LIB)/libft.a
	$(CC) $^ -I$(INCLUDES) -I$(LIB_INCLUDES) -o $@

re: fclean all

all: $(NAME)

# impicit rule for mandatory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -I$(INCLUDES) -I$(LIB_INCLUDES) -o $@

$(LIB)/%.a:
	@echo "\033[1;32mCompiling libft\033[0m"
	@$(MAKE) all -C $(LIB)
	@echo "\033[1;32mLibft compiled\033[0m"


#______cleaning______#
clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIB) fclean

fclean: clean
	$(RM) $(NAME)

.PHONY: clean

