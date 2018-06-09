NAME	= 	fdf
FLAGS	= 	-Wall -Wextra -Werror -o3
SRC		= 	src/main.c \
			src/magic.c \
			src/draw.c \
			src/color.c \
			src/image.c \
			src/map.c \
			src/info.c \
			src/keys.c \
			src/utils.c \

OBJ		=	$(patsubst src/%.c,obj/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAGS) -L libft/ -lft -g -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME)
	@printf '\033[32m[✓] %s\n\033[0m' "FDF"

obj/%.o: src/%.c
	@mkdir -p obj
	gcc $(FLAGS) -c $< -o $@
	@printf '\033[35m[✓] %s\n\033[0m' "$<"

clean:
	@/bin/rm -rf obj/
	@make -C libft/ clean
	@printf '\033[31m[✓] %s\n\033[0m' "Clean FDF"

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean
	@printf '\033[31m[✓] %s\n\033[0m' "Fclean FDF"

re: fclean all
