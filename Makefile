NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft
LIBFT = -L$(LIBFT_DIR) -lft

INCLUDES = -Iincludes -I$(LIBFT_DIR)/includes

OBJ_DIR = objets

SRCS = $(wildcard srcs/*.c)
OBJS = $(SRCS:srcs/%.c=$(OBJ_DIR)/%.o)


PINK = \033[38;5;213m
BLUE = \033[38;5;75m
RESET = \033[0m

BOLD := \033[1m


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(BOLD)$(PINK)🎉 Compile with success !!! 🎉$(RESET)"

$(OBJ_DIR):
	@(mkdir -p $(OBJ_DIR))

$(OBJ_DIR)/%.o: srcs/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: bonus/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_DIR)/libft.a:
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR)
	@echo "🧹 Clean Over ! 🧹"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR)
	@echo "🧼 All Clean Over !!! 🧼"

re: fclean all

.PHONY: all clean fclean re
