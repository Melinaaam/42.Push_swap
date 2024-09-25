NAME = push_swap
BONUS = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft
LIBFT = -L$(LIBFT_DIR) -lft

INCLUDES = -Iincludes -I$(LIBFT_DIR)/includes

OBJ_DIR = objets

# Fichiers sources et objets
SRCS = $(wildcard srcs/*.c)
OBJS = $(SRCS:srcs/%.c=$(OBJ_DIR)/%.o)

BONUS_SRCS = $(wildcard bonus/*.c)
BONUS_OBJS = $(BONUS_SRCS:bonus/%.c=$(OBJ_DIR)/%.o)

# Couleurs
PINK = \033[38;5;213m
GREEN = \033[38;5;82m
RESET = \033[0m

# Texte en gras
BOLD := \033[1m

# Règle par défaut
all: $(NAME)
	@echo "$(BOLD)$(PINK)🎉 Compile with success !!! 🎉$(RESET)"


# Construction de l'exécutable
$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Règle pour la partie bonus
$(BONUS) : $(BONUS_OBJS) $(LIBFT_DIR)/libft.a
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS)
	@echo "$(BOLD)$(GREEN)🎉 Compile $(BONUS) with success !!! 🎉$(RESET)"

# Création du répertoire pour les objets si nécessaire
$(OBJ_DIR):
	@(mkdir -p $(OBJ_DIR))

# Compilation des fichiers source en fichiers objets
$(OBJ_DIR)/%.o: srcs/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilation des fichiers bonus en fichiers objets
$(OBJ_DIR)/%.o: bonus/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Construction de la bibliothèque libft
$(LIBFT_DIR)/libft.a:
	@make -C $(LIBFT_DIR) --no-print-directory

# Nettoyage des fichiers objets
clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@echo "🧹 Clean Over ! 🧹"

# Nettoyage complet (fichiers objets + exécutable)
fclean: clean
	@rm -f $(NAME) $(BONUS)
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "🧼 All Clean Over !!! 🧼"

# Reconstruction complète
re: fclean all

# Dépendances
.PHONY: all clean fclean re
