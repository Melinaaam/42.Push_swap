NAME = push_swap
BONUS = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft
LIBFT = -L$(LIBFT_DIR) -lft

INCLUDES = -Iincludes -I$(LIBFT_DIR)/includes

OBJ_DIR = objets

SRCS = $(wildcard srcs/*.c)
OBJS = $(SRCS:srcs/%.c=$(OBJ_DIR)/%.o)

BONUS_SRCS = $(wildcard bonus/*.c)
BONUS_OBJS = $(BONUS_SRCS:bonus/%.c=$(OBJ_DIR)/%.o)

PINK = \033[38;5;213m
GREEN = \033[38;5;82m
RESET = \033[0m

BOLD := \033[1m


all: $(NAME)
	@echo "$(BOLD)$(PINK)🎉 Compile with success !!! 🎉$(RESET)"

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(BONUS) : $(BONUS_OBJS) $(LIBFT_DIR)/libft.a
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS)
	@echo "$(BOLD)$(GREEN)🎉 Compile $(BONUS) with success !!! 🎉$(RESET)"

$(OBJ_DIR):
	@(mkdir -p $(OBJ_DIR))

$(OBJ_DIR)/%.o: srcs/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: bonus/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_DIR)/libft.a:
	@make -C $(LIBFT_DIR) --no-print-directory

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@echo "🧹 Clean Over ! 🧹"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "🧼 All Clean Over !!! 🧼"

re: fclean all

.PHONY: all clean fclean re
