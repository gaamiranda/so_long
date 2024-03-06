NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
SRC = src/ft_printf.c src/flood_fill.c src/mlx_init.c gnl/get_next_line.c gnl/get_next_line_utils.c src/check_map.c src/error.c src/help_functions.c src/main.c src/structs.c
OBJ_DIR = obj
INCLUDE_FOLDER = include
INCLUDES = -I $(INCLUDE_FOLDER)
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

Color_Off = '\033[0m'
Red = '\033[0;91m'
Green = '\033[0;92m'
Yellow = '\033[0;93m'
Cyan = '\033[0;96m'

MSG1 = @echo $(Green)"$(NAME) compiled successfully"$(Color_Off)
MSG2 = @echo $(Cyan)"cleaned completely"$(Color_Off)
MSG3 = @echo $(Yellow)"$(NAME) cleaned"$(Color_Off)
MSG4 = @echo $(Red)"$(BONUS_NAME) compiled successfully"$(Color_Off)


all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) -Imlx -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) $(INCLUDES) -o $(NAME)
	$(MSG1)

clean:
	@rm -rf $(OBJ_DIR)
	$(MSG3)

fclean: clean
	@rm -f $(NAME)
	$(MSG2)

re: fclean all

.PHONY: all clean fclean re