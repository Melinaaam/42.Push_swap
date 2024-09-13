# Nom de l'exécutable
NAME = push_swap

# Compilateur
CC = cc

# Options de compilation
CFLAGS = -Wall -Wextra -Werror

# Chemin vers libft
LIBFT_DIR = libft
LIBFT = -L$(LIBFT_DIR) -lft

# Chemin vers les fichiers d'en-tête
INCLUDES = -Iincludes -I$(LIBFT_DIR)/includes

# Répertoire pour les fichiers objets
OBJ_DIR = objets

# Fichiers sources et objets
SRCS = $(wildcard srcs/*.c)
OBJS = $(SRCS:srcs/%.c=$(OBJ_DIR)/%.o)

# Couleurs
PINK = \033[38;5;213m
RESET = \033[0m

# Texte en gras
BOLD := \033[1m

# Règle par défaut
all: $(NAME)
	@echo "$(BOLD)$(PINK)🎉 Compile with success !!! 🎉$(RESET)"

# Construction de l'exécutable
$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Création du répertoire pour les objets si nécessaire
$(OBJ_DIR):
	@(mkdir -p $(OBJ_DIR))

# Compilation des fichiers source en fichiers objets
$(OBJ_DIR)/%.o: srcs/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Construction de la bibliothèque libft
$(LIBFT_DIR)/libft.a:
	@($(MAKE) -C $(LIBFT_DIR))

# Nettoyage des fichiers objets
clean:
	@rm -rf $(OBJ_DIR)
	@($(MAKE) -C $(LIBFT_DIR) clean)
	@echo "🧹 Clean Over ! 🧹"

# Nettoyage complet (fichiers objets + exécutable)
fclean: clean
	@rm -f $(NAME)
	@($(MAKE) -C $(LIBFT_DIR) fclean)
	@echo "🧼 All Clean Over !!! 🧼"

# Reconstruction complète
re: fclean all

# Dépendances
.PHONY: all clean fclean re
