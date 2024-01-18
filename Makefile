#______command and their flags______#
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar -crs
INCLUDES = includes

#______directories______#
OBJ_DIR = obj
SRC_DIR = src
BNS_OBJ_DIR = obj_bonus
BNS_DIR = bonus
INCLUDES = includes
LIB_INCLUDES = libft/includes

#______mandatory files______#
FILES = init_nodes.c main.c operation.c sort_utils.c sort.c stacks_init.c utils.c

#_____bonus files______#
FILES_BONUS =  main.c operation.c stacks_init.c  utils.c cases.c

#operation.c actions.c stacks_init.c

#______patterns and substitutions______#
SOURCES = $(FILES:%.c=$(SRC_DIR)/%.c)
OBJECTS = $(SOURCES:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

SOURCES_BONUS = $(FILES_BONUS:%.c=$(BNS_DIR)/%.c)
OBJECTS_BONUS = $(SOURCES_BONUS:$(BNS_OBJ_DIR)%.c=$(OBJ_DIR)%.o)

#______static library name______#
NAME = push_swap
LIB = libft

#______________Rules______________#

$(NAME): $(OBJECTS) $(LIB)/libft.a
	$(CC) $^ -I$(INCLUDES) -I$(LIB_INCLUDES) -o $@

bonus: $(OBJECTS_BONUS) $(LIB)/libft.a
	$(CC) $^ -I$(INCLUDES) -I$(LIB_INCLUDES) -o checker

re: fclean all

all: $(NAME)

# impicit rule for mandatory
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -I$(INCLUDES) -I$(LIB_INCLUDES) -o $@

# impicit rule for bonus
$(BNS_OBJ_DIR)/%.o: $(BNS_DIR)/%.c
	@mkdir -p $(BNS_OBJ_DIR)
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

